
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QForwardRenderer>
#include <Qt3DWindow>
#include <QOrbitCameraController>
#include <QTransform>
#include <QCamera>
#include <QMesh>
#include <QMessageBox>
#include <QDir>

#include <customcameracontroller.h>
#include <custom3dwindow.h>



//#######################
//###                 ###
//###   CONSTRUCTOR   ###
//###                 ###
//#######################

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":logo_glass3d.ico"));
    connect(ui->actionOpen,             SIGNAL(triggered()), this, SLOT(onFileOpen()));
    connect(ui->actionQuit,             SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionReset,            SIGNAL(triggered()), this, SLOT(onResetView()));
    connect(ui->actionSettings,         SIGNAL(triggered()), this, SLOT(onSettings()));
    connect(ui->actionManual_b_sico,    SIGNAL(triggered()), this, SLOT(onManualB()));
    connect(ui->actionManual_avanzado,  SIGNAL(triggered()), this, SLOT(onManualA()));
    connect(ui->actionInformaci_n,      SIGNAL(triggered()), this, SLOT(onInfo()));

    // TABs
    connect(ui->tabSteps, SIGNAL(currentChanged(int)), this, SLOT(tabSelected()));

    // Paso 1
    connect(ui->pushButtonNext1, SIGNAL(clicked()), this, SLOT(nextStep()));

    // Paso 2
    connect(ui->pushButtonGenerate2,    SIGNAL(clicked()),                  this, SLOT(onPushButtonGenerate2()));
    connect(ui->pushButtonBack2,        SIGNAL(clicked()),                  this, SLOT(prevStep()));
    connect(ui->pushButtonNext2,        SIGNAL(clicked()),                  this, SLOT(nextStep()));
    connect(ui->comboBoxDirection,      SIGNAL(currentIndexChanged(int)),   this, SLOT(onComboBoxDirectionChanged(int)));
    connect(ui->doubleSpinBoxWidth,     SIGNAL(valueChanged(double)),       this, SLOT(onWidthChanged(double)));
    connect(ui->doubleSpinBoxTop,       SIGNAL(valueChanged(double)),       this, SLOT(onTopPlaneChanged()));
    connect(ui->doubleSpinBoxBottom,    SIGNAL(valueChanged(double)),       this, SLOT(onBottomPlaneChanged()));

    // Paso 3
    connect(ui->pushButtonSave3,    SIGNAL(clicked()),      this, SLOT(onPushButtonSave3()));
    connect(ui->pushButtonBack3,    SIGNAL(clicked()),      this, SLOT(prevStep()));
    connect(ui->checkBoxShowMesh,   SIGNAL(clicked(bool)),  this, SLOT(onMeshEnableChanged(bool)));
    connect(ui->checkBoxShowPiece,  SIGNAL(clicked(bool)),  this, SLOT(onMeshPositiveEnableChanged(bool)));

    new3DWindow();
}

// Destructor de la clase, también se encarga de borrar los archivos STL generados durante la ejecución
MainWindow::~MainWindow()
{
    QFile::remove("temp.stl"); // Borrado del STL temporal
    QFile::remove("binTemp.stl"); // Borrado del STL Binario temporal
    delete ui;
}

// Función que crea la escena 3D instanciando una nueva clase Custom3DWindow
void MainWindow::new3DWindow()
{

    // Qt3D
    window = new Custom3DWindow();
    window->defaultFrameGraph()->setClearColor(QColor(QRgb(0xffffff)));
    QWidget *container = QWidget::createWindowContainer(window);
    container->setObjectName("Custom3DWindow");

    QTabWidget *tabPasos = ui->tabSteps;
    ui->tabSteps->setVisible(false);

    ui->centralwidget->layout()->addWidget(container);
    ui->centralwidget->layout()->addWidget(tabPasos);

    // Desactivo todos los tabs menos el primero
    for (int idx = 1; idx < ui->tabSteps->count(); ++idx) {
        ui->tabSteps->setTabEnabled(idx,false);
    }

    window->createScene();

    // Conexiones de las señales
    connect(window, SIGNAL(sendMessageBox(QString)),        this,               SLOT(messageBox(QString)));
    connect(window, SIGNAL(setCenterPointText(QString)),    this,               SLOT(centerPointTextChanged(QString)));
    connect(window, SIGNAL(setInfoStep2(QString)),          this,               SLOT(infoStep2Changed(QString)));
    connect(window, SIGNAL(setProgressBar(int)),            ui->progressBar,    SLOT(setValue(int)));
    connect(window, SIGNAL(pauseUserActions(bool)),         this,               SLOT(pauseUserActions(bool)));
    connect(window, SIGNAL(setTopPlane(float)),             this,               SLOT(setTopPlaneSpinBox(float)));
    connect(window, SIGNAL(setBottomPlane(float)),          this,               SLOT(setBottomPlaneSpinBox(float)));
}

// Función de inicio de devuelve todos los campos y valores de la GUI a su estado original
void MainWindow::init()
{
    onSettingsChanged();
    window->restoreDefaults();

    ui->tabSteps->setCurrentIndex(0);
    ui->tabSteps->setTabEnabled(0,true);
    ui->tabSteps->setTabEnabled(1,false);
    ui->tabSteps->setTabEnabled(2,false);

    // Paso 1
    ui->infoStep1->setText("Seleccione un punto del molde con click derecho para generar el centro");
    ui->centerPointText->setText("");
    ui->menuView->actions().at(1)->setEnabled(true);

    // Paso 2
    ui->infoStep2->setText("");
    ui->progressBar->setValue(0);
    ui->doubleSpinBoxTop->setValue(0);
    ui->doubleSpinBoxBottom->setValue(0);
    ui->doubleSpinBoxTop->setEnabled(false);
    ui->doubleSpinBoxBottom->setEnabled(false);

    // Paso 3
    ui->checkBoxShowMesh->setChecked(true);
    ui->checkBoxShowPiece->setChecked(true);

    QFile::remove("temp.stl"); // Borrado del STL temporal
    QFile::remove("binTemp.stl"); // Borrado del STL Binario temporal
}



//#####################
//###               ###
//###   FUNCTIONS   ###
//###               ###
//#####################

//###################
//###   MenuBar   ###
//###################
// Función de menú: Archivo -> Abrir
void MainWindow::onFileOpen()
{
    QString modelName = QFileDialog::getOpenFileName(this, "Seleccionar molde", "", "Modelos (*.stl)");

    if (modelName != ""){

        init();

        path = modelName;
        window->setObjPath(path);
        window->loadObj();
        ui->tabSteps->setVisible(true);

        this->setWindowTitle("Glass3D - " + modelName);
    }
}

// Función de menú: Ver -> Reiniciar
void MainWindow::onResetView() { window->resetView(); }

// Función de menú: Ver -> Preferencias
void MainWindow::onSettings()
{
    Settings *s = new Settings(this);
    connect(s, SIGNAL(changed()), this, SLOT(onSettingsChanged()));
    s->setWindowModality(Qt::WindowModal);
    s->show();
}

// Función de menú: Ayuda -> Manual Básico
void MainWindow::onManualB() { QDesktopServices::openUrl(QUrl::fromLocalFile("./manuales/Glass3D_Basico.pdf")); }
// Función de menú: Ayuda -> Manual Avanzado
void MainWindow::onManualA() { QDesktopServices::openUrl(QUrl::fromLocalFile("./manuales/Glass3D_Avanzado.pdf")); }
// Función de menú: Ayuda -> Información
void MainWindow::onInfo()
{
    QMessageBox info;
    info.about(this, "Información", "Glass3D (1.0):\nEste software permite generar el modelo 3D de las piezas de vidrio fabricadas "
                                    "mediante la técnica de soplado rodado. Para ello se usa el modelo escaneado de su respectivo molde (formato STL)."
                                    "\n\nGRP-Digitalización Moldes, TFG Gonzalo López Pérez");
}

//################
//###   Tabs   ###
//################
// Función que devuelve el paso donde se encuentra el usuario.
void MainWindow::tabSelected(){
    window->setTabSelected(ui->tabSteps->currentIndex());
}

// Función para avanzar al siguiente tab.
void MainWindow::nextStep()
{
    int curidx = ui->tabSteps->currentIndex();

    // Validaciones
    switch (curidx) {
    case 0:
        if (ui->centerPointText->text() == "") {
            messageBox("Debe generar un centro de escena haciendo click derecho sobre el molde.");
            return;
        }
        ui->menuView->actions().at(1)->setEnabled(false);
        break;
    case 1:
        if (!ui->doubleSpinBoxTop->isEnabled()) {
            messageBox("Para generar el positivo primero se debe cargar una preview.");
            return;
        } else {
            window->positiveCollisions();
        }
    default:
        break;
    }

    ui->tabSteps->setTabEnabled(curidx,false);
    ui->tabSteps->setTabEnabled(curidx+1,true);
    ui->tabSteps->setCurrentIndex(curidx+1);
}

// Función para volver al tab anterior.
void MainWindow::prevStep()
{
    int curidx = ui->tabSteps->currentIndex();

    // Validaciones
    switch (curidx) {
    case 1:
        window->deleteEntities("preview");
        ui->doubleSpinBoxTop->setEnabled(false);
        ui->doubleSpinBoxBottom->setEnabled(false);

        ui->infoStep2->setText("");
        ui->progressBar->setValue(0);
        ui->menuView->actions().at(1)->setEnabled(true);
        break;
    case 2:
        ui->checkBoxShowMesh->setChecked(true);
        ui->checkBoxShowPiece->setChecked(true);
        window->enableMesh(true);

        window->deleteEntities("positivo");
        window->previewCollisions();

    default:
        break;
    }

    ui->tabSteps->setTabEnabled(curidx,false);
    ui->tabSteps->setTabEnabled(curidx-1,true);
    ui->tabSteps->setCurrentIndex(curidx-1);
}


//###################
//###   Buttons   ###
//###################

// Botón para iniciar la generación de la preview en el paso 2
void MainWindow::onPushButtonGenerate2()
{
    window->deleteEntities("preview");
    pauseUserActions(true);
    window->loadGeometry();
}

// Botón para guardar el resultado final en el paso 3
void MainWindow::onPushButtonSave3()
{
    window->generateBinaryPositive();

    if (lastSavePath == "" || lastSavePath == nullptr) {
        lastSavePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    }
    std::string base_filename = path.toStdString().substr(path.toStdString().find_last_of("/\\") + 1);
    std::string::size_type const p(base_filename.find_last_of('.'));
    std::string file_without_extension = base_filename.substr(0, p);

    QString filePath = QFileDialog::getSaveFileName(this ,QObject::tr("Guardara STL"), lastSavePath + "/" + QString::fromStdString(file_without_extension) + defaultSaveSuffix, "STL (*.stl)");

    if (filePath != ""){
        QFileInfo f(filePath);
        lastSavePath = f.absolutePath();

        if (QFile::exists(filePath))
            QFile::remove(filePath);
        if(QFile::copy("binTemp.stl", filePath))
            qDebug() << "Archivo guardado con éxito";
        else
            emit messageBox("Se ha producido un error al guardar el archivo STL. Intentelo de nuevo o compruebe la ruta de guardado si el problema persiste.");
    }
;}

//########################
//###   Data Changes   ###
//########################
// Función que detecta el cambio de dirección de escaneo del contorno
void MainWindow::onComboBoxDirectionChanged(int index)
{
    switch (index) {
    case 0:
        window->setRayCastDirection('L');
        break;
    case 1:
        window->setRayCastDirection('R');
        break;
    }
}

// Funciones de moficiación del grosor y movimiento de los planos de ajuste
void MainWindow::onWidthChanged(double w) { window->setPositiveWidth(static_cast<float>(w)); }
void MainWindow::onTopPlaneChanged() { window->moveTopPlane(ui->doubleSpinBoxTop->value()); }
void MainWindow::onBottomPlaneChanged() { window->moveBottomPlane(ui->doubleSpinBoxBottom->value()); }

// Funciones para mostrar u ocultar el molde y/o el positivo
void MainWindow::onMeshEnableChanged(bool enabled) { window->enableMesh(enabled); }
void MainWindow::onMeshPositiveEnableChanged(bool enabled) { window->enableMeshPositive(enabled); }

//#########################################
//###   Connections to Custom3DWindow   ###
//#########################################
void MainWindow::centerPointTextChanged(QString s) { ui->centerPointText->setText(s); }
void MainWindow::infoStep2Changed(QString s) { ui->infoStep2->setText(s); }

void MainWindow::setTopPlaneSpinBox(float z)
{
    ui->doubleSpinBoxTop->setEnabled(true);
    ui->doubleSpinBoxTop->setValue(static_cast<double>(z));
}

void MainWindow::setBottomPlaneSpinBox(float z)
{
    ui->doubleSpinBoxBottom->setEnabled(true);
    ui->doubleSpinBoxBottom->setValue(static_cast<double>(z));
}

void MainWindow::messageBox(QString s)
{
    QMessageBox Msgbox;
    Msgbox.setText(s);
    Msgbox.setIcon(QMessageBox::Icon::Warning);
    Msgbox.exec();
}

void MainWindow::onSettingsChanged() {

    QSettings settings("cfg_Glass3D.ini",QSettings::Format::IniFormat);
    defaultWidth =          settings.value("Defaults/border_width").toDouble();
    defaultScanDirection =  settings.value("Defaults/scan_direction").toString();
    defaultSaveSuffix =     settings.value("Defaults/save_suffix").toString();

    if (defaultScanDirection == "R")
        ui->comboBoxDirection->setCurrentIndex(1);
    else
        ui->comboBoxDirection->setCurrentIndex(0);
    ui->doubleSpinBoxWidth->setValue(defaultWidth);

    window->settingsChanged();
}

//#################
//###   Utils   ###
//#################
// Función que limita las acciones del usuario durante los procesos de mayor carga
void MainWindow::pauseUserActions(bool enabled)
{
    ui->menuFile->actions().at(0)->setEnabled(!enabled);
    ui->menuView->actions().at(0)->setEnabled(!enabled);
    ui->comboBoxDirection->setEnabled(!enabled);
    ui->pushButtonGenerate2->setEnabled(!enabled);
    ui->doubleSpinBoxWidth->setEnabled(!enabled);
    ui->doubleSpinBoxTop->setEnabled(!enabled);
    ui->doubleSpinBoxBottom->setEnabled(!enabled);
    ui->pushButtonBack2->setEnabled(!enabled);
    ui->pushButtonNext2->setEnabled(!enabled);
}
