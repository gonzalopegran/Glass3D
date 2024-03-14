
#include "custom3dwindow.h"
#include "customcameracontroller.h"
#include <consecutiveraycaster.h>
#include "mesh.h"
#include "vec3.h"

#include <Qt3DWindow>
#include <QTransform>
#include <QCamera>
#include <QMesh>
#include <QPickPointEvent>
#include <QObjectPicker>
#include <QBuffer>
#include <QPickingSettings>
#include <QRenderSettings>
#include <QPickTriangleEvent>
#include <QSphereMesh>
#include <QPhongMaterial>
#include <QPhongAlphaMaterial>
#include <QPointLight>
#include <QPlaneMesh>
#include <QThread>
#include <QSettings>

#include <QDepthTest>


//#######################
//###                 ###
//###   CONSTRUCTOR   ###
//###                 ###
//#######################

Custom3DWindow::Custom3DWindow() : Qt3DExtras::Qt3DWindow()
{

}


//#############################
//###                       ###
//###   GETTERS + SETTERS   ###
//###                       ###
//#############################

QString Custom3DWindow::getObjPath() const                  { return objPath; }
void Custom3DWindow::setObjPath(const QString &newObjPath)  { objPath = newObjPath; }
int Custom3DWindow::getTabSelected() const { return tabSelected; }
void Custom3DWindow::setTabSelected(int newTabSelected) { tabSelected = newTabSelected; }
float Custom3DWindow::getCenterDepth() const { return centerDepth; }
void Custom3DWindow::setCenterDepth(float newCenterDepth) { centerDepth = newCenterDepth; }
void Custom3DWindow::setPositiveWidth(float newPositiveWidth) { positiveWidth = newPositiveWidth; }
void Custom3DWindow::setRayCastDirection(char newRayCastDirection) { rayCastDirection = newRayCastDirection; }
void Custom3DWindow::enableMesh(bool enabled) { mesh->setEnabled(enabled); }
void Custom3DWindow::enableMeshPositive(bool enabled) { meshPositive->setEnabled(enabled); }

//#####################
//###               ###
//###   FUNCTIONS   ###
//###               ###
//#####################

// Función que crea la Entidad pricipal y la cámara
Qt3DCore::QEntity* Custom3DWindow::createScene()
{
    // Root entity
    rootEntity = new Qt3DCore::QEntity;

    // Establece la posición de la cámara
    m_camera = this->camera();
    m_camera->lens()->setPerspectiveProjection(60.0f, this->width()/this->height(), 0.1f, 1000.0f);
    resetView();

    // Controlador de la cámara
    m_cameraController = new CustomCameraController(rootEntity); // Cámara Custom
    m_cameraController->setCamera(m_camera);

    // Creo 4 focos de luz distintos rodeando el resultado final
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight();
    light->setColor("white");
    light->setIntensity(0.5);

    Qt3DCore::QEntity *lightEntity1 = new Qt3DCore::QEntity(rootEntity);
    lightEntity1->addComponent(light);
    Qt3DCore::QTransform *lightTransform1 = new Qt3DCore::QTransform(lightEntity1) ;
    lightTransform1->setTranslation(QVector3D(0,200,200)) ;
    lightEntity1->addComponent(lightTransform1);

    Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(rootEntity);
    lightEntity2->addComponent(light);
    Qt3DCore::QTransform *lightTransform2 = new Qt3DCore::QTransform(lightEntity2) ;
    lightTransform2->setTranslation(QVector3D(0,-200,200)) ;
    lightEntity2->addComponent(lightTransform2);

    Qt3DCore::QEntity *lightEntity3 = new Qt3DCore::QEntity(rootEntity);
    lightEntity3->addComponent(light);
    Qt3DCore::QTransform *lightTransform3 = new Qt3DCore::QTransform(lightEntity3) ;
    lightTransform3->setTranslation(QVector3D(200,0,-200)) ;
    lightEntity3->addComponent(lightTransform3);

    Qt3DCore::QEntity *lightEntity4 = new Qt3DCore::QEntity(rootEntity);
    lightEntity4->addComponent(light);
    Qt3DCore::QTransform *lightTransform4 = new Qt3DCore::QTransform(lightEntity4) ;
    lightTransform4->setTranslation(QVector3D(-200,0,-200)) ;
    lightEntity4->addComponent(lightTransform4);

    setRootEntity(rootEntity);
    show();

    return rootEntity;
}

//
void Custom3DWindow::restoreDefaults()
{
    m_center = QVector3D(0,0,0);
    planeTopZ = 0, planeBottomZ = 0;

    m_positiveRayCaster = nullptr;
    m_centerRayCaster = nullptr;
    m_TopPlaneTransform1    = nullptr;
    m_TopPlaneTransform2    = nullptr;
    m_BottomPlaneTransform1 = nullptr;
    m_BottomPlaneTransform2 = nullptr;

    deleteEntities("selectedPoint");
    deleteEntities("centerPoint");
    deleteEntities("preview");
    deleteEntities("positivo");
    deleteEntities("molde");

    resetView();
}

//###################
//###   MenuBar   ###
//###################
// Función que carga ficheros .obj en la escena mediante la clase QMesh
void Custom3DWindow::loadObj()
{
    // Mesh Material
    Qt3DExtras::QPhongMaterial *meshM = new Qt3DExtras::QPhongMaterial();
    meshM->setDiffuse(QColor("grey"));

    // Mesh Entity
    meshE = new Qt3DCore::QEntity(rootEntity);
    meshE->setObjectName("molde");
    mesh = new Qt3DRender::QMesh();
    mesh->setPrimitiveType(Qt3DRender::QGeometryRenderer::PrimitiveType::Triangles);
    mesh->setSource(QUrl::fromLocalFile(objPath));

    // Mesh Transform
    Qt3DCore::QTransform *meshT = new Qt3DCore::QTransform();
    meshT->setScale(1);
    meshT->setRotationX(-90);

    auto rsettings = this->renderSettings();
    rsettings->pickingSettings()->setFaceOrientationPickingMode(Qt3DRender::QPickingSettings::FrontFace);
    rsettings->pickingSettings()->setPickMethod(Qt3DRender::QPickingSettings::TrianglePicking);
    rsettings->pickingSettings()->setPickResultMode(Qt3DRender::QPickingSettings::NearestPick);
    rsettings->pickingSettings()->setWorldSpaceTolerance(2.0f);
    rsettings->setRenderPolicy(Qt3DRender::QRenderSettings::Always);

//    Qt3DRender::QDepthTest*  rootDepthTest  = new Qt3DRender::QDepthTest;
//    rootDepthTest ->setDepthFunction(Qt3DRender::QDepthTest::Always);

    Qt3DRender::QObjectPicker *meshP = new Qt3DRender::QObjectPicker(rootEntity);
    meshP->setHoverEnabled(false);
    meshP->setDragEnabled(false);
    connect(meshP, &Qt3DRender::QObjectPicker::clicked, this, &Custom3DWindow::select_points);

    meshE->addComponent(mesh);
    meshE->addComponent(meshM);
    meshE->addComponent(meshT);
    meshE->addComponent(meshP);
}

// Función para reiniciar la cámara a la posición inicial
void Custom3DWindow::resetView()
{
    m_camera->setPosition(QVector3D(0,200,0));
    m_camera->setUpVector(QVector3D(0,0,-1));
    m_camera->setViewCenter(m_center);

    deleteEntities("selectedPoint");
}


//###################################
//###   3D Generation Functions   ###
//###################################
// Función que comienza el escaneo de puntos con el RayCaster y posteriormente llama a collisions() para construir los triángulos.
void Custom3DWindow::loadGeometry()
{
    m_centerSphere->setEnabled(false);
    emit setInfoStep2("Realizando escaneo del contorno...");

    m_positiveRayCaster = new ConsecutiveRayCaster(rootEntity, TimeDelayStatus::NoDelay, 0 /* milliseconds */, rayCastCount*2, m_center);
    m_positiveRayCaster->setHalfDirection(rayCastDirection);
    connect(m_positiveRayCaster, SIGNAL(rayCasterProgressBar(int)), this, SLOT(emitProgressBar(int)));

    // Una vez ha terminado el escaneo de puntos emito la señal de finalización para ejecutar el slot que crea los triángulos
    connect(m_positiveRayCaster, SIGNAL(rayCastingFinished()), this, SLOT(previewCollisions()));

    QThread *thread = new QThread;
    m_positiveRayCaster->moveToThread(thread);
    thread->start();

    m_positiveRayCaster->runHalfRayCastTests();
}

// Función que ejecuta la emisión de rayos para detectar colisiones desde el punto seleccionado por el usuario en el paso 1
void Custom3DWindow::rayCastCenter()
{
    int originX = static_cast<int>(m_picked.x());
    if (originX < 20)
        originX++;

    m_centerRayCaster = new ConsecutiveRayCaster(rootEntity, TimeDelayStatus::SomeDelay, 0, 2, QVector3D(originX,m_picked.y(),m_picked.z()));
    connect(m_centerRayCaster, SIGNAL(rayCastingFinished()), this, SLOT(centerCollisions()));
    m_centerRayCaster->runRayCastTests();
}

// Función que carga en escena el positivo generado por positiveCollisions()
void Custom3DWindow::drawPositive()
{
    m_centerSphere->setEnabled(false);

    // Mesh Material
    m_material = new Qt3DExtras::QPhongMaterial();
    m_material->setDiffuse(QColor("green"));

    // Mesh Entity
    meshPositiveE = new Qt3DCore::QEntity(rootEntity);
    meshPositiveE->setObjectName("positivo");

    meshPositive = new Qt3DRender::QMesh();
    meshPositive->setPrimitiveType(Qt3DRender::QGeometryRenderer::PrimitiveType::Triangles);
    meshPositive->setSource(QUrl::fromLocalFile(QString("temp.stl")));

    // Mesh Transform
    Qt3DCore::QTransform *meshPositiveT = new Qt3DCore::QTransform();
    meshPositiveT->setScale(1);
    meshPositiveT->setTranslation(QVector3D(m_center.x(),m_center.y(),0));
    meshPositiveT->setRotationX(180);

    meshPositiveE->addComponent(meshPositive);
    meshPositiveE->addComponent(m_material);
    meshPositiveE->addComponent(meshPositiveT);

    deleteEntities("preview");
}

// Función que guarda el positivo en formato STL binario en vez de ASCII para el guardado final
void Custom3DWindow::generateBinaryPositive(){
    exportBinarySTL(meshPositive);
}

// Función que dibuja una línea entre los dos puntos pasados por parámetro
void Custom3DWindow::drawLine(const QVector3D& start, const QVector3D& end, Qt3DCore::QEntity *_rootEntity)
{
    auto *geometry = new Qt3DCore::QGeometry(_rootEntity);

    // position vertices (start and end)
    QByteArray bufferBytes;
    bufferBytes.resize(3 * 2 * sizeof(float)); // start.x, start.y, start.end + end.x, end.y, end.z
    float *positions = reinterpret_cast<float*>(bufferBytes.data());
    *positions++ = start.x();
    *positions++ = start.y();
    *positions++ = start.z();
    *positions++ = end.x();
    *positions++ = end.y();
    *positions++ = end.z();

    auto *buf = new Qt3DCore::QBuffer(geometry);
    buf->setData(bufferBytes);

    auto *positionAttribute = new Qt3DCore::QAttribute(geometry);
    positionAttribute->setName(Qt3DCore::QAttribute::defaultPositionAttributeName());
    positionAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
    positionAttribute->setVertexSize(3);
    positionAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
    positionAttribute->setBuffer(buf);
    positionAttribute->setByteStride(3 * sizeof(float));
    positionAttribute->setCount(2);
    geometry->addAttribute(positionAttribute); // We add the vertices in the geometry

    // connectivity between vertices
    QByteArray indexBytes;
    indexBytes.resize(2 * sizeof(unsigned int)); // start to end
    unsigned int *indices = reinterpret_cast<unsigned int*>(indexBytes.data());
    *indices++ = 0;
    *indices++ = 1;

    auto *indexBuffer = new Qt3DCore::QBuffer(geometry);
    indexBuffer->setData(indexBytes);

    auto *indexAttribute = new Qt3DCore::QAttribute(geometry);
    indexAttribute->setVertexBaseType(Qt3DCore::QAttribute::UnsignedInt);
    indexAttribute->setAttributeType(Qt3DCore::QAttribute::IndexAttribute);
    indexAttribute->setBuffer(indexBuffer);
    indexAttribute->setCount(2);
    geometry->addAttribute(indexAttribute); // We add the indices linking the points in the geometry

    // mesh
    auto *line = new Qt3DRender::QGeometryRenderer(_rootEntity);
    line->setGeometry(geometry);
    line->setPrimitiveType(Qt3DRender::QGeometryRenderer::Lines);
    auto *material = new Qt3DExtras::QPhongMaterial(_rootEntity);
    material->setAmbient(QColor("green"));

    // entity
    auto *lineEntity = new Qt3DCore::QEntity(_rootEntity);
    lineEntity->addComponent(line);
    lineEntity->addComponent(material);
    lineEntity->setObjectName("preview");
}



//############################
//###   User Interaction   ###
//############################
// Función que se ejecuta al hacer click en el QMesh del molde importado.
void Custom3DWindow::select_points(Qt3DRender::QPickEvent *pick)
{
    // Paso 1: Selección del centro del molde
    if (tabSelected == 0 && pick->button() == Qt3DRender::QPickEvent::RightButton) {
        deleteEntities("selectedPoint");
        deleteEntities("centerPoint");
        m_picked = pick->worldIntersection();
        centerDepth = m_picked.y();

        rayCastCenter();
    }
}

// Función encargada de mover el plano de corte superior
void Custom3DWindow::moveTopPlane(float z)
{
    if ((m_TopPlaneTransform1 != nullptr) & (m_TopPlaneTransform2 != nullptr)) {
        planeTopZ = z;
        QVector3D newPos = QVector3D(m_TopPlaneTransform1->translation().x(), m_TopPlaneTransform1->translation().y(), z);
        m_TopPlaneTransform1->setTranslation(newPos);
        m_TopPlaneTransform2->setTranslation(newPos);
    }
}

// Función encargada de mover el plano de generación de la base interior
void Custom3DWindow::moveBottomPlane(float z)
{
    if ((m_BottomPlaneTransform1 != nullptr) & (m_BottomPlaneTransform2 != nullptr)) {
        planeBottomZ = z;
        QVector3D newPos = QVector3D(m_BottomPlaneTransform1->translation().x(), m_BottomPlaneTransform1->translation().y(), z);
        m_BottomPlaneTransform1->setTranslation(newPos);
        m_BottomPlaneTransform2->setTranslation(newPos);
    }
}

// Función que recarga los valores establecidos en el fichero de ajustes cuando este se modifica
void Custom3DWindow::settingsChanged()
{
    QSettings settings("cfg_Glass3D.ini",QSettings::Format::IniFormat);
    // Defaults
    positiveWidth = settings.value("Defaults/border_width").toDouble();
    if (settings.value("Defaults/scan_direction").toString() == "R")
        rayCastDirection = 'R';
    else
        rayCastDirection = 'L';

    // Generation
    rayCastCount = settings.value("Generation/scan_points").toInt();
    trianglesCount = settings.value("Generation/generation_points").toInt();
}


//#################
//###   Utils   ###
//#################

// Función para exportar los triángulos de un QMesh
void Custom3DWindow::exportBinarySTL(Qt3DRender::QMesh *mesh)
{
//    qDebug() << __func__ << " iniciada.";

    Qt3DCore::QGeometry *geometry = mesh->geometry();
    QVector<Qt3DCore::QAttribute *> atts = geometry->attributes();
    int byteOffsetPos = 0, byteOffsetNorm = 0, byteStridePos = 0, byteStrideNorm = 0;

    Qt3DCore::QBuffer *bufferPtrPos = nullptr, *bufferPtrNorm = nullptr;

    for(int i = 0; i < atts.size(); ++i) {
        if(atts.at(i)->name() == Qt3DCore::QAttribute::defaultPositionAttributeName()) {
            byteOffsetPos = atts.at(i)->byteOffset();
            byteStridePos = atts.at(i)->byteStride();
            bufferPtrPos = atts.at(i)->buffer();
        } else if(atts.at(i)->name() == Qt3DCore::QAttribute::defaultNormalAttributeName()) {
            byteOffsetNorm = atts.at(i)->byteOffset();
            byteStrideNorm = atts.at(i)->byteStride();
            bufferPtrNorm = atts.at(i)->buffer();
        }
    }

    // I loop over attributes to get access to VertexBuffer buffer
    for(int i = 0; i < atts.size(); ++i) {

        if(atts.at(i)->name() == Qt3DCore::QAttribute::defaultPositionAttributeName()) {
            QByteArray dataPos = bufferPtrPos->data();
            QByteArray dataNorm = bufferPtrNorm->data();

            // Number of triangles is number of vertices divided by 3:
            long trianglesCount = atts.at(i)->count() / 3;
            QByteArray baStl;
            meshExport.binarystl_write_init(trianglesCount);

            // For each triangle, extract vertex positions and normals
            for(int j = 0; j < trianglesCount; ++j) {

                // Index for each triangle positions data
                // Each triangle has 3 vertices, hence 3 factor:
                // We already know byte-offset and byte-stride for positions
                int idxPos  = byteOffsetPos  + j * 3 * byteStridePos ;

                // Index for each triangle normals data
                // Each tirangle has 3 normals (right?), hence 3 factor:
                // We already know byte-offset and byte-stride for normals
                int idxNorm = byteOffsetNorm + j * 3 * byteStrideNorm;

                // Get x, y, z positions for 1st vertex
                // I have already checked that attribute base type is float by: `atts.at(i)->vertexBaseType();`
                QByteArray pos0x = dataPos.mid(idxPos + 0 * sizeof(float), sizeof(float));
                QByteArray pos0y = dataPos.mid(idxPos + 1 * sizeof(float), sizeof(float));
                QByteArray pos0z = dataPos.mid(idxPos + 2 * sizeof(float), sizeof(float));

                // Get x, y, z positions for 2nd vertex
                QByteArray pos1x = dataPos.mid(idxPos  + 1 * byteStridePos + 0 * sizeof(float), sizeof(float));
                QByteArray pos1y = dataPos.mid(idxPos  + 1 * byteStridePos + 1 * sizeof(float), sizeof(float));
                QByteArray pos1z = dataPos.mid(idxPos  + 1 * byteStridePos + 2 * sizeof(float), sizeof(float));

                // Get x, y, z positions for 3rd vertex
                QByteArray pos2x = dataPos.mid(idxPos  + 2 * byteStridePos + 0 * sizeof(float), sizeof(float));
                QByteArray pos2y = dataPos.mid(idxPos  + 2 * byteStridePos + 1 * sizeof(float), sizeof(float));
                QByteArray pos2z = dataPos.mid(idxPos  + 2 * byteStridePos + 2 * sizeof(float), sizeof(float));


                // Get x, y z for 1st NORMAL
                QByteArray norm0x= dataNorm.mid(idxNorm + 0 * sizeof(float), sizeof(float));
                QByteArray norm0y= dataNorm.mid(idxNorm + 1 * sizeof(float), sizeof(float));
                QByteArray norm0z= dataNorm.mid(idxNorm + 2 * sizeof(float), sizeof(float));

                // Write the triangle to QByteArray
                QBuffer tempBuffer(&baStl);
                tempBuffer.open(QIODevice::Append);
                tempBuffer.write( norm0x   ); // vertex 0 Normal vector
                tempBuffer.write( norm0y   );
                tempBuffer.write( norm0z   );
                tempBuffer.write( pos0x ); // New vertex 0 position
                tempBuffer.write( pos0y );
                tempBuffer.write( pos0z );
                tempBuffer.write( pos1x ); // New vertex 1 position
                tempBuffer.write( pos1y );
                tempBuffer.write( pos1z );
                tempBuffer.write( pos2x ); // New vertex 2 position
                tempBuffer.write( pos2y );
                tempBuffer.write( pos2z );
                tempBuffer.write("aa"); // Attribute byte count: UINT16: 2 bytes: content doesn't matter, just write 2 bytes
                tempBuffer.close();
            }
            meshExport.binarystl_write_triangles(baStl);
        }

    }

//    qDebug() << __func__ << " finalizada.";
}

// Función que borra las entidades hijas de rootEntity buscando por el nombre
void Custom3DWindow::deleteEntities(const QString &name)
{
    while (rootEntity->findChild<Qt3DCore::QEntity *>(name,Qt::FindChildOption::FindChildrenRecursively) != nullptr) {
        delete rootEntity->findChild<Qt3DCore::QEntity *>(name,Qt::FindChildOption::FindChildrenRecursively);
    }
}

// Función usada para habilitar o deshabilitar entidades de la entidad pricipal según su nombre
void Custom3DWindow::enableEntities(const QString &name, bool enabled)
{
    while (rootEntity->findChild<Qt3DCore::QEntity *>(name,Qt::FindChildOption::FindChildrenRecursively) != nullptr) {
        rootEntity->findChild<Qt3DCore::QEntity *>(name,Qt::FindChildOption::FindChildrenRecursively)->setEnabled(enabled);
    }
}


//#################
//###   Slots   ###
//#################
// Función encargada de la generación final del positivo
void Custom3DWindow::positiveCollisions()
{
    emit setInfoStep2("Generando el positivo...");
    emit pauseUserActions(true);

    int     baseInteriorCount = 0;
    bool    positivoCerrado = false;

    float r, rNext = 0, x, y, xAux, yAux, xNext, yNext, xNextAux, yNextAux;
    float rInt, rIntNext = 0, xInt, yInt, xIntAux, yIntAux, xIntNext = 0, yIntNext = 0, xIntNextAux = 0, yIntNextAux = 0;
    float tetha, tethaAux;

    meshExport.stl_write_init("temp.stl","PositivoTemporal");

    for (int i = 0; i < m_positiveRayCaster->rayCastHandler()->collisions().size() ; i++) {

        int porcentaje = (i * 100)/ m_positiveRayCaster->rayCastHandler()->collisions().size();
        emit setProgressBar(porcentaje);

        QVector3D intersection = m_positiveRayCaster->rayCastHandler()->collisions().at(i).point;
        QVector3D intersectionNext;

        if (intersection.z() > planeTopZ) {
            // GENERACIÓN DE LOS TRIÁNGULOS EXTERIORES:
            // Si no estoy en la última colision es que hay una más después y tengo que componer sus triángulos.
            if (i+1 < m_positiveRayCaster->rayCastHandler()->collisions().size()) {

                intersectionNext = m_positiveRayCaster->rayCastHandler()->collisions().at(i+1).point;
                for (int j = 0; j < trianglesCount ; j++) {
                    // Obtengo el radio del circulo de la intersección actual
                    if (rayCastDirection == 'L') {
                        r = m_center.x()-intersection.x(); // Circle radius
                        rNext = m_center.x()-intersectionNext.x();
                    } else {
                        r = intersection.x()-m_center.x(); // Circle radius
                        rNext = intersectionNext.x()-m_center.x();
                    }

                    rInt = r-positiveWidth;
                    rIntNext = rNext-positiveWidth;
                    if (r<0) r = r*(-1);
                    if (rNext<0) rNext = rNext*(-1);
                    if (rInt<0) rInt = rInt*(-1);
                    if (rIntNext<0) rIntNext = rIntNext*(-1);

                    // Obtengo los valores para el sin y cos del punto j del circulo actual y el siguiente
                    tetha = 2 * M_PI / trianglesCount * j;
                    if (j==trianglesCount-1) {
                        tethaAux = 2 * M_PI / trianglesCount * 0;
                    } else {
                        tethaAux = 2 * M_PI / trianglesCount * (j+1);
                    }

                    x = r * cos(tetha);
                    y = r * sin(tetha);
                    // Siguiente punto en el círculo
                    xAux = r * cos(tethaAux);
                    yAux = r * sin(tethaAux);

                    xNext = rNext * cos(tetha);
                    yNext = rNext * sin(tetha);
                    // Siguiente punto en el círculo
                    xNextAux = rNext * cos(tethaAux);
                    yNextAux = rNext * sin(tethaAux);

                    // La primera iteración es una cantidad j de triangulos. El resto es una cantidad j*2
                    if (i == 0) {
                        meshExport.add(Vec3(0,0,-intersection.z()),Vec3(xAux,yAux,-intersection.z()),Vec3(x,y,-intersection.z()));
                    }
                    meshExport.add(Vec3(xNext,yNext,-intersectionNext.z()),Vec3(xAux,yAux,-intersection.z()),Vec3(xNextAux,yNextAux,-intersectionNext.z()));
                    meshExport.add(Vec3(xAux,yAux,-intersection.z()),Vec3(xNext,yNext,-intersectionNext.z()),Vec3(x,y,-intersection.z()));

                    // GENERACIÓN DE LOS TRIÁNGULOS INTERIORES:
                    if (intersection.z() <= planeBottomZ) {
                        xInt = rInt * cos(tetha);
                        yInt = rInt * sin(tetha);
                        // Siguiente punto en el círculo
                        xIntAux = rInt * cos(tethaAux);
                        yIntAux = rInt * sin(tethaAux);

                        xIntNext = rIntNext * cos(tetha);
                        yIntNext = rIntNext * sin(tetha);
                        // Siguiente punto en el círculo
                        xIntNextAux = rIntNext * cos(tethaAux);
                        yIntNextAux = rIntNext * sin(tethaAux);

                        if (baseInteriorCount < trianglesCount) {
                            meshExport.add(Vec3(0,0,-intersection.z()),Vec3(xInt,yInt,-intersection.z()),Vec3(xIntAux,yIntAux,-intersection.z()));
                            baseInteriorCount++;
                        }
                        meshExport.add(Vec3(xIntNext,yIntNext,-intersectionNext.z()),Vec3(xIntNextAux,yIntNextAux,-intersectionNext.z()),Vec3(xIntAux,yIntAux,-intersection.z()));
                        meshExport.add(Vec3(xIntAux,yIntAux,-intersection.z()),Vec3(xInt,yInt,-intersection.z()),Vec3(xIntNext,yIntNext,-intersectionNext.z()));

                    }

                    // CIERRE DE LA PARTE SUPERIOR (Sin plano de corte superior)
                    if (i+1 == m_positiveRayCaster->rayCastHandler()->collisions().size()-1) {
                        meshExport.add(Vec3(xNext,yNext,-intersectionNext.z()),Vec3(xNextAux,yNextAux,-intersectionNext.z()),Vec3(xIntNextAux,yIntNextAux,-intersectionNext.z()));
                        meshExport.add(Vec3(xIntNextAux,yIntNextAux,-intersectionNext.z()),Vec3(xIntNext,yIntNext,-intersectionNext.z()),Vec3(xNext,yNext,-intersectionNext.z()));
                    }
                }
            }

        } else if (!positivoCerrado) { // CIERRE DE LA PARTE SUPERIOR (usando plano de corte superior)
            // Utilizo los valores guardados de los puntos "Next" para realizar el cierre.
            for (int j = 0; j < trianglesCount ; j++) {
                // Obtengo los valores para el sin y cos del punto j del circulo y el siguiente
                tetha = 2 * M_PI / trianglesCount * j;
                if (j==trianglesCount-1) {
                    tethaAux = 2 * M_PI / trianglesCount * 0;
                } else {
                    tethaAux = 2 * M_PI / trianglesCount * (j+1);
                }

                // EXTERIOR
                xNext = rNext * cos(tetha);
                yNext = rNext * sin(tetha);
                    // Siguiente punto en el círculo
                xNextAux = rNext * cos(tethaAux);
                yNextAux = rNext * sin(tethaAux);

                // INTERIOR
                xIntNext = rIntNext * cos(tetha);
                yIntNext = rIntNext * sin(tetha);
                    // Siguiente punto en el círculo
                xIntNextAux = rIntNext * cos(tethaAux);
                yIntNextAux = rIntNext * sin(tethaAux);

                meshExport.add(Vec3(xNext,yNext,-intersection.z()),Vec3(xNextAux,yNextAux,-intersection.z()),Vec3(xIntNextAux,yIntNextAux,-intersection.z()));
                meshExport.add(Vec3(xIntNextAux,yIntNextAux,-intersection.z()),Vec3(xIntNext,yIntNext,-intersection.z()),Vec3(xNext,yNext,-intersection.z()));
            }
            positivoCerrado = true;
        }
        meshExport.stl_write_triangles("temp.stl");
        meshExport.clear();
    }
    meshExport.stl_write_end("temp.stl","PositivoTemporal");

    emit setInfoStep2("Generación completada.");
    emit setProgressBar(100);
    emit pauseUserActions(false);

    drawPositive();
}

// Función encargada de gestionar las colisiones después de escanear el contorno:
// - Dibuja el contorno a partir de los puntos detectados
// - Define los planos de corte superior y generación de base interior
void Custom3DWindow::previewCollisions()
{
    deleteEntities("preview");
    emit setInfoStep2("Cargando la preview...");

    qDebug() << __func__ << " iniciada.";
    int collisionsSize = m_positiveRayCaster->rayCastHandler()->collisions().size() ;

    for (int i = 0; i < collisionsSize ; i++) {

        int porcentaje = (i * 100)/ collisionsSize;
        emit setProgressBar(porcentaje);

        QVector3D intersection = m_positiveRayCaster->rayCastHandler()->collisions().at(i).point;

        if (i == 0) {

            // PLANO INFERIOR
            if (planeBottomZ == 0)
                planeBottomZ = intersection.z()-10;

            Qt3DExtras::QPlaneMesh *planeBottomMesh = new Qt3DExtras::QPlaneMesh();
            planeBottomMesh->setWidth(100);
            planeBottomMesh->setHeight(100);
            Qt3DExtras::QPhongAlphaMaterial *planeM = new Qt3DExtras::QPhongAlphaMaterial(rootEntity);
            planeM->setDiffuse(QColor("blue"));

            m_BottomPlaneTransform1 = new Qt3DCore::QTransform();
            m_BottomPlaneTransform1->setScale(1);
            m_BottomPlaneTransform1->setTranslation(QVector3D(m_center.x(),m_center.y(),planeBottomZ));
            m_BottomPlaneTransform1->setRotationX(90);
            Qt3DCore::QEntity *planeE = new Qt3DCore::QEntity(rootEntity);
            planeE->addComponent(planeBottomMesh);
            planeE->addComponent(m_BottomPlaneTransform1);
            planeE->addComponent(planeM);
            planeE->setObjectName("preview");

            m_BottomPlaneTransform2 = new Qt3DCore::QTransform();
            m_BottomPlaneTransform2->setScale(1);
            m_BottomPlaneTransform2->setTranslation(QVector3D(m_center.x(),m_center.y(),planeBottomZ));
            m_BottomPlaneTransform2->setRotationX(-90);
            Qt3DCore::QEntity *planeE2 = new Qt3DCore::QEntity(rootEntity);
            planeE2->addComponent(planeBottomMesh);
            planeE2->addComponent(m_BottomPlaneTransform2);
            planeE2->addComponent(planeM);
            planeE2->setObjectName("preview");

            emit setBottomPlane(planeBottomZ);

        } else if (i+1 == collisionsSize) {

            // PLANO SUPERIOR
            if (planeTopZ == 0)
                planeTopZ = intersection.z();

            Qt3DExtras::QPlaneMesh *planeBottomMesh = new Qt3DExtras::QPlaneMesh();
            planeBottomMesh->setWidth(100);
            planeBottomMesh->setHeight(100);
            Qt3DExtras::QPhongAlphaMaterial *planeM = new Qt3DExtras::QPhongAlphaMaterial(rootEntity);
            planeM->setDiffuse(QColor("green"));

            m_TopPlaneTransform1 = new Qt3DCore::QTransform();
            m_TopPlaneTransform1->setScale(1);
            m_TopPlaneTransform1->setTranslation(QVector3D(m_center.x(),m_center.y(),planeTopZ));
            m_TopPlaneTransform1->setRotationX(90);
            Qt3DCore::QEntity *planeE = new Qt3DCore::QEntity(rootEntity);
            planeE->addComponent(planeBottomMesh);
            planeE->addComponent(m_TopPlaneTransform1);
            planeE->addComponent(planeM);
            planeE->setObjectName("preview");

            m_TopPlaneTransform2 = new Qt3DCore::QTransform();
            m_TopPlaneTransform2->setScale(1);
            m_TopPlaneTransform2->setTranslation(QVector3D(m_center.x(),m_center.y(),planeTopZ));
            m_TopPlaneTransform2->setRotationX(-90);
            Qt3DCore::QEntity *planeE2 = new Qt3DCore::QEntity(rootEntity);
            planeE2->addComponent(planeBottomMesh);
            planeE2->addComponent(m_TopPlaneTransform2);
            planeE2->addComponent(planeM);
            planeE2->setObjectName("preview");

            emit setTopPlane(planeTopZ);
        }

        if (i+1 != collisionsSize)
        {
            drawLine(intersection,m_positiveRayCaster->rayCastHandler()->collisions().at(i+1).point,rootEntity);
        }

    }

    qDebug() << __func__ << " finalizada.";
    m_centerSphere->setEnabled(true);

    emit setInfoStep2("Preview cargada.");
    emit pauseUserActions(false);
    emit setProgressBar(100);

    resetView();
}

// Función encargada de gestionar los puntos detectados durante el cálculo del centro
void Custom3DWindow::centerCollisions()
{
    if (m_centerRayCaster->rayCastHandler()->collisions().size() > 1 ) {
        float x0 = m_centerRayCaster->rayCastHandler()->collisions().at(0).point.x();
        float x1 = m_centerRayCaster->rayCastHandler()->collisions().at(1).point.x();
        float x = x1 + ((x0-x1)/2);

        m_center = QVector3D(x,m_picked.y(),m_picked.z());
        emit setCenterPointText("(" + QString::number(m_center.x()) + ", " + QString::number(m_center.y()) + ", " + QString::number(m_center.z()) + ")");

        deleteEntities("centerPoint");

        m_centerSphere = new Qt3DExtras::QSphereMesh();
        m_centerSphere->setRadius(1);
        m_centerSphere->setRings(50);
        m_centerSphere->setSlices(50);

        Qt3DCore::QTransform *esferaT = new Qt3DCore::QTransform();
        esferaT->setScale(2);
        esferaT->setTranslation(m_center);

        Qt3DExtras::QPhongAlphaMaterial *esferaM = new Qt3DExtras::QPhongAlphaMaterial(rootEntity);
        esferaM->setDiffuse(QColor("red"));

        Qt3DCore::QEntity *esferaE = new Qt3DCore::QEntity(rootEntity);
        esferaE->addComponent(m_centerSphere);
        esferaE->addComponent(esferaM);
        esferaE->addComponent(esferaT);
        esferaE->setObjectName("centerPoint");

        resetView();

    } else {
        emit sendMessageBox("No se puede generar un centro desde ese punto. Por favor, seleccione otro.");
        emit setCenterPointText("");
    }
}

// Señal que emite el estado de la barra de progreso a MainWindow
void Custom3DWindow::emitProgressBar(int n)
{
    emit setProgressBar(n);
}
