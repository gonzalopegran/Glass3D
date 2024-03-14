#ifndef CUSTOM3DWINDOW_H
#define CUSTOM3DWINDOW_H

#include <QEntity>
#include <Qt3DWindow>
#include <QPhongMaterial>
#include <QPhongAlphaMaterial>
#include <QSphereMesh>
#include <QPickEvent>
#include <QObjectPicker>
#include <QMesh>
#include <QtCore/QBuffer>
#include <QOrbitCameraController>
#include <QTransform>

#include <customcameracontroller.h>
#include <consecutiveraycaster.h>
#include <mesh.h>

class Custom3DWindow : public Qt3DExtras::Qt3DWindow
{
Q_OBJECT
private:
    Qt3DCore::QEntity               *rootEntity;
    Qt3DRender::QCamera             *m_camera;
    CustomCameraController          *m_cameraController;
    Qt3DExtras::QPhongMaterial      *m_material;
    Qt3DRender::QMesh               *mesh, *meshPositive;
    Qt3DCore::QEntity               *meshE, *meshPositiveE;
    Qt3DExtras::QSphereMesh         *m_centerSphere;
    Qt3DRender::QObjectPicker       *m_picker;
    Qt3DCore::QTransform            *m_TopPlaneTransform1, *m_TopPlaneTransform2, *m_BottomPlaneTransform1, *m_BottomPlaneTransform2;
    ConsecutiveRayCaster            *m_positiveRayCaster, *m_centerRayCaster;
    Mesh                            meshExport;
    QVector3D                       m_picked;
    QVector3D                       m_center;

    // Simples
    QString                         objPath;
    int                             tabSelected = 0, trianglesCount = 256, rayCastCount = 400; // Estos valores se modifican con el cfg_Glass3D.ini
    char                            rayCastDirection; // L = Left, R = Right #Se modifica con el cfg_Glass3D.ini
    float                           centerDepth, planeTopZ, planeBottomZ, positiveWidth; // Medido en mm el positiveWidth

public:
    Custom3DWindow();
    Qt3DCore::QEntity*  createScene();
    void                restoreDefaults();

    // Getters & Setters
    QString             getObjPath() const;
    void                setObjPath(const QString &newObjPath);
    int                 getTabSelected() const;
    void                setTabSelected(int newTabSelected);
    void                setCenterDepth(float newCenterDepth);
    float               getCenterDepth() const;
    void                setPositiveWidth(float newPositiveWidth);
    void                setRayCastDirection(char newRayCastDirection);
    void                enableMesh(bool enabled);
    void                enableMeshPositive(bool enabled);

    // MenuBar Functions
    void                loadObj();
    void                resetView();

    // 3D Generation Functions
    void                loadGeometry();
    void                rayCastCenter();
    void                drawPositive();
    void                drawLine(const QVector3D& start, const QVector3D& end, Qt3DCore::QEntity* _rootEntity);

    // User interaction functions
    void                select_points(Qt3DRender::QPickEvent *event);
    void                moveTopPlane(float z);
    void                moveBottomPlane(float z);
    void                settingsChanged();

    // Utils
    void                exportBinarySTL(Qt3DRender::QMesh *mesh);
    void                generateBinaryPositive();
    void                deleteEntities(const QString &name);
    void                enableEntities(const QString &name, bool enabled);

signals:
    void                setCenterPointText(QString s);
    void                setProgressBar(int n);
    void                setInfoStep2(QString s);
    void                setTopPlane(float z);
    void                setBottomPlane(float z);
    void                sendMessageBox(QString s);
    void                pauseUserActions(bool enabled);

public slots:
    void                positiveCollisions();
    void                previewCollisions();
    void                centerCollisions();
    void                emitProgressBar(int n);

};

#endif // CUSTOM3DWINDOW_H
