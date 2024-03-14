#include "raycasthandler.h"

#include <Qt3DCore/QEntity>
#include <Qt3DRender/QRayCaster>
#include <Qt3DRender/QLayer>
#include <QTimer>

#include <cfloat> // For FLT_MAX

RayCastHandler::RayCastHandler(Qt3DCore::QEntity *scene, TimeDelayStatus timeDelayStatus, unsigned int timeDelayBetweenRayCasts, QObject *parent) : QObject(parent)
    , m_rayCaster(nullptr)
    , m_layer(nullptr)
    , m_scene(scene)
    , m_tests(nullptr)
    , m_testCounter(0)
    , m_testsTotal(0)
    , m_timeDelayStatus(timeDelayStatus)
    , m_timeDelayBetweenRayCasts(timeDelayBetweenRayCasts)
{
    m_rayCaster = new Qt3DRender::QRayCaster(m_scene);
    m_layer = new Qt3DRender::QLayer();
    m_rayCaster->setRunMode(Qt3DRender::QAbstractRayCaster::SingleShot);
    m_rayCaster->addLayer(m_layer);
    m_rayCaster->setFilterMode(Qt3DRender::QAbstractRayCaster::FilterMode::AcceptAnyMatchingLayers);

    // Only scene root can have ray caster
    m_scene->addComponent(m_rayCaster);

    // Handle ray cast results
    QObject::connect(m_rayCaster, &Qt3DRender::QRayCaster::hitsChanged, this, &RayCastHandler::handleRayCasterHits);
    QObject::connect(m_rayCaster, &Qt3DCore::QNode::enabledChanged, this, &RayCastHandler::handleRayCasterEnabledChange);

    if (!parent) {
        setParent(m_scene);
    }
}

void RayCastHandler::runTests(const QVector<RayTest> *tests)
{
    if (tests->isEmpty()) {
        emit rayCastResultsChanged(QVector<HitPoint>());
        return;
    }

    updateLayers(m_scene, m_layer);

    m_tests = tests;
    m_collisions = QVector<HitPoint>();
    m_testCounter = 0;
    m_testsTotal = m_tests->length();
    triggerTest(m_rayCaster, m_tests, m_testCounter);

    return;
}

void RayCastHandler::handleRayCasterHits(const Qt3DRender::QAbstractRayCaster::Hits hits)
{
    analyzeHits(m_testCounter, m_collisions, hits);
    return;
}

void RayCastHandler::handleRayCasterEnabledChange(const bool enabled)
{
    if (!enabled) {
        bool required = isNextTestRequired(m_testCounter, m_testsTotal);
        if (required)
            triggerTest(m_rayCaster, m_tests, m_testCounter);
        else
            emit rayCastResultsChanged(m_collisions);
    }
    return;
}

void RayCastHandler::updateLayers(Qt3DCore::QEntity * const &scene, Qt3DRender::QLayer * const &layerSupport)
{
    const QList<QObject *> children = scene->children();
    for ( QObject *child : children ) {
        Qt3DCore::QEntity *childEntity = qobject_cast<Qt3DCore::QEntity *>(child);
        if (childEntity) {
            childEntity->addComponent(layerSupport);
//            qDebug() << __func__ << "Layer added to" << childEntity->objectName();
        }
    }
}

void RayCastHandler::triggerTest(Qt3DRender::QRayCaster * const rayCaster, const QVector<RayTest> * const &tests, int &testCounter)
{
    int porcentaje = (testCounter * 100) / tests->size();
    emit rayProgressBar(porcentaje);

    RayTest test = (*tests)[testCounter];
    QVector3D origin = test.origin;
    QVector3D end = test.end;
    QVector3D direction = end - origin;
    float length = direction.length();
    direction.normalize();

    rayCaster->setOrigin(origin);
    rayCaster->setDirection(direction);
    rayCaster->setLength(length);

    switch (m_timeDelayStatus) {
    case NoDelay:
        rayCaster->trigger();
        break;
    case SomeDelay:
        QTimer::singleShot(m_timeDelayBetweenRayCasts, [rayCaster](){ rayCaster->trigger(); });
        break;
    }

    return;
}

void RayCastHandler::analyzeHits(const int &testCounter, QVector<HitPoint> &collisions, const Qt3DRender::QAbstractRayCaster::Hits hits)
{
    if (hits.isEmpty()) {
//        qDebug() << __func__ << "Empty hits";
    } else {
//        qDebug() << __func__ << "Hits NOT empty";
        HitPoint hitPoint = {};
        hitPoint.indexSortedAscending = testCounter;
        hitPoint.point = hits.at(0).worldIntersection();
        collisions.append(hitPoint);
    }

    return;
}

bool RayCastHandler::isNextTestRequired(int &testCounter, const int &testsTotal)
{
    testCounter++;
    if (testCounter >= testsTotal) {
        return false;
    }
    return true;
}

QVector<HitPoint> RayCastHandler::collisions() const
{
    return m_collisions;
}
