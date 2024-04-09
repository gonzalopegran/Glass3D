#include "consecutiveraycaster.h"
#include <cmath> // for M_PI

//#######################
//###                 ###
//###   CONSTRUCTOR   ###
//###                 ###
//#######################

ConsecutiveRayCaster::ConsecutiveRayCaster(Qt3DCore::QEntity *scene, TimeDelayStatus timeDelayStatus, unsigned int timeDelayBetweenRayCasts, int points, QVector3D center)
    : m_rayCastHandler(nullptr)
    , m_rayTests(nullptr)
{
    m_rayCastHandler = new RayCastHandler(scene, timeDelayStatus, timeDelayBetweenRayCasts);
    QObject::connect(m_rayCastHandler, SIGNAL(rayProgressBar(int)), this, SLOT(emitRayCasterProgressBar(int)));
    QObject::connect(m_rayCastHandler, &RayCastHandler::rayCastResultsChanged, this, &ConsecutiveRayCaster::handleFinish);

    m_rayTests = new QVector<RayTest>();
    m_points = points;
    m_center = center;
}

// Destructor
ConsecutiveRayCaster::~ConsecutiveRayCaster()
{
    if (m_rayCastHandler) {
        delete m_rayCastHandler;
        m_rayCastHandler = nullptr;
    }
    if (m_rayTests) {
        delete m_rayTests;
        m_rayTests = nullptr;
    }
}

//#############################
//###                       ###
//###   GETTERS + SETTERS   ###
//###                       ###
//#############################

RayCastHandler* ConsecutiveRayCaster::rayCastHandler() const { return m_rayCastHandler; }
void ConsecutiveRayCaster::setHalfDirection(char newHalfDirection) { m_halfDirection = newHalfDirection; }


//#####################
//###               ###
//###   FUNCTIONS   ###
//###               ###
//#####################

// Función que inicia el escano de colisiones por trazado de rayos en forma circular.
void ConsecutiveRayCaster::runRayCastTests()
{
    m_rayTests->clear();

    // m_points puntos en el círculo
    int count = m_points;
    for (int i = 0; i < count ; ++i) {
        float tetha = 2 * M_PI / count * i;
        float r = 1000.0f; // Radio
        float x = r * cosf(tetha); // x del punto en el círculo
        float z = r * sinf(tetha); // z del punto en el círculo

        RayTest rayTest = {};
        rayTest.origin = m_center; // Centro
        rayTest.end    = QVector3D( x, m_center.y(), z); // Punto del círculo
        m_rayTests->append(rayTest);
    }

    m_rayCastHandler->runTests(m_rayTests);
}

// Función que inicia el escano de colisiones por trazado de rayos en forma circular pero solo escaneando media circunferencia.
// TO_DO: Podría simplificarse llamando a la función runRayCastTests() con un parámetro que le indique la dirección.
void ConsecutiveRayCaster::runHalfRayCastTests()
{
    m_rayTests->clear();

    // m_points puntos en el círculo
    int count = m_points;
    for (int i = count/4; i < count * 3/4 ; ++i) {
        float tetha = 2 * M_PI / count * i;
        float r = 1000.0f; // Radio
        float x = r * cosf(tetha); // x del punto en el círculo
        float z = r * sinf(tetha); // z del punto en el círculo

        // Para hacerlo hacia la derecha hay que poner a negativo el valor de la X
        if (m_halfDirection != 'L') {
            x = x * (-1);
        }

        RayTest rayTest = {};
        rayTest.origin = m_center; // Centro
        rayTest.end    = QVector3D( x, m_center.y(), z); // Punto del círculo
        m_rayTests->append(rayTest);
    }

    m_rayCastHandler->runTests(m_rayTests);
}

// Función que finaliza el escaneo de colisiones y emite la señales que se comunican con la GUI.
void ConsecutiveRayCaster::handleFinish(const QVector<HitPoint> collisions)
{
    for (HitPoint collision : collisions) {
        int index = collision.indexSortedAscending;
        QVector3D intersection = collision.point;
        qDebug() << __func__ << "collision index =" << index << "collision intersection =" << intersection;
    }

    qDebug() << __func__ << "Finished: all ray-cast collisions are logged.";

    emit rayCasterProgressBar(100);
    emit rayCastingFinished();

}

void ConsecutiveRayCaster::emitRayCasterProgressBar(int n)
{
    emit rayCasterProgressBar(n);
}
