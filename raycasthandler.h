#ifndef RAYCASTHANDLER_H
#define RAYCASTHANDLER_H

#include <QObject>
#include <Qt3DRender/QAbstractRayCaster>

namespace Qt3DRender {
class QRayCaster;
class QLayer;
}

struct RayTest {
    QVector3D origin = QVector3D();
    QVector3D end    = QVector3D();
};

struct HitPoint {
    int indexSortedAscending = 0;
    QVector3D point = QVector3D();
};

enum TimeDelayStatus {
    NoDelay = 1,
    SomeDelay
};

class RayCastHandler : public QObject
{
    Q_OBJECT
public:
    explicit RayCastHandler(Qt3DCore::QEntity *scene, TimeDelayStatus timeDelayStatus, unsigned int timeDelayBetweenRayCasts = 0, QObject *parent = nullptr);
    void runTests(const QVector<RayTest> *tests);

    QVector<HitPoint> collisions() const;

signals:
    void rayCastResultsChanged(const QVector<HitPoint> collisions);
    void rayProgressBar(int n);

private slots:
    void handleRayCasterHits(const Qt3DRender::QAbstractRayCaster::Hits hits);
    void handleRayCasterEnabledChange(const bool enabled);

private:
    void updateLayers(Qt3DCore::QEntity *const &scene, Qt3DRender::QLayer *const &layerSupport);
    void triggerTest(Qt3DRender::QRayCaster *const rayCaster, const QVector<RayTest> *const &tests, int &testCounter);
    void analyzeHits(const int &testCounter, QVector<HitPoint> &collisions, const Qt3DRender::QAbstractRayCaster::Hits hits);
    bool isNextTestRequired(int &testCounter, const int &testsTotal);

private:
    Qt3DRender::QRayCaster  *m_rayCaster;
    Qt3DRender::QLayer      *m_layer;
    Qt3DCore::QEntity       *m_scene; // parent, not owned
    const QVector<RayTest>  *m_tests; // Not owned, set by others
    QVector<HitPoint>       m_collisions;
    int                     m_testCounter;
    int                     m_testsTotal;
    TimeDelayStatus         m_timeDelayStatus;
    unsigned int            m_timeDelayBetweenRayCasts;
};

#endif // RAYCASTHANDLER_H
