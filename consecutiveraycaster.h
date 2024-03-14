#ifndef CONSECUTIVERAYCASTER_H
#define CONSECUTIVERAYCASTER_H

#include <QObject>
#include <Qt3DWindow>
#include "raycasthandler.h"

class ConsecutiveRayCaster : public QObject
{
    Q_OBJECT

public:
    ConsecutiveRayCaster(Qt3DCore::QEntity *scene, TimeDelayStatus timeDelayStatus, unsigned int timeDelayBetweenRayCasts = 0, int points = 100, QVector3D center = QVector3D(0,-4,0));
    ~ConsecutiveRayCaster();
    void runRayCastTests();
    void runHalfRayCastTests();

    RayCastHandler *rayCastHandler() const;

    int             m_points;
    QVector3D       m_center;
    char            m_halfDirection = 'L';

    void setHalfDirection(char newHalfDirection);

signals:
    void rayCastingFinished();
    void rayCasterProgressBar(int n);

public slots:
    void emitRayCasterProgressBar(int n);


private Q_SLOTS:
    void handleFinish(const QVector<HitPoint> collisions);

private:
    RayCastHandler *m_rayCastHandler;
    QVector<RayTest> *m_rayTests;
};

#endif // CONSECUTIVERAYCASTER_H
