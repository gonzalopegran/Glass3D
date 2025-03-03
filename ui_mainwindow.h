/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionQuit;
    QAction *actionReset;
    QAction *actionSettings;
    QAction *actionManual_b_sico;
    QAction *actionManual_avanzado;
    QAction *actionInformaci_n;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabSteps;
    QWidget *Step1;
    QLineEdit *infoStep1;
    QLabel *labelStep1Center;
    QPushButton *pushButtonNext1;
    QLineEdit *centerPointText;
    QLabel *label_guide;
    QLabel *label_guide_2;
    QWidget *Step2;
    QPushButton *pushButtonBack2;
    QPushButton *pushButtonNext2;
    QPushButton *pushButtonGenerate2;
    QProgressBar *progressBar;
    QLineEdit *infoStep2;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxTop;
    QDoubleSpinBox *doubleSpinBoxBottom;
    QFrame *line;
    QComboBox *comboBoxDirection;
    QLabel *label_4;
    QFrame *line_2;
    QFrame *line_3;
    QWidget *Step3;
    QPushButton *pushButtonBack3;
    QPushButton *pushButtonSave3;
    QCheckBox *checkBoxShowMesh;
    QCheckBox *checkBoxShowPiece;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuAyuda;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1080, 720);
        MainWindow->setMinimumSize(QSize(1080, 400));
        MainWindow->setIconSize(QSize(24, 24));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconos/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/iconos/abrir.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconos/cerrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName("actionReset");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconos/reiniciar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon2);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName("actionSettings");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iconos/preferencias.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon3);
        actionManual_b_sico = new QAction(MainWindow);
        actionManual_b_sico->setObjectName("actionManual_b_sico");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/iconos/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManual_b_sico->setIcon(icon4);
        actionManual_avanzado = new QAction(MainWindow);
        actionManual_avanzado->setObjectName("actionManual_avanzado");
        actionManual_avanzado->setIcon(icon4);
        actionInformaci_n = new QAction(MainWindow);
        actionInformaci_n->setObjectName("actionInformaci_n");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/iconos/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInformaci_n->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        tabSteps = new QTabWidget(centralwidget);
        tabSteps->setObjectName("tabSteps");
        tabSteps->setEnabled(true);
        tabSteps->setMaximumSize(QSize(1920, 100));
        tabSteps->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        tabSteps->setAutoFillBackground(false);
        tabSteps->setTabPosition(QTabWidget::TabPosition::North);
        tabSteps->setTabShape(QTabWidget::TabShape::Rounded);
        tabSteps->setElideMode(Qt::TextElideMode::ElideLeft);
        tabSteps->setDocumentMode(false);
        tabSteps->setTabsClosable(false);
        tabSteps->setTabBarAutoHide(false);
        Step1 = new QWidget();
        Step1->setObjectName("Step1");
        infoStep1 = new QLineEdit(Step1);
        infoStep1->setObjectName("infoStep1");
        infoStep1->setEnabled(false);
        infoStep1->setGeometry(QRect(10, 40, 461, 24));
        infoStep1->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        labelStep1Center = new QLabel(Step1);
        labelStep1Center->setObjectName("labelStep1Center");
        labelStep1Center->setGeometry(QRect(630, 30, 141, 21));
        pushButtonNext1 = new QPushButton(Step1);
        pushButtonNext1->setObjectName("pushButtonNext1");
        pushButtonNext1->setGeometry(QRect(970, 30, 80, 24));
        pushButtonNext1->setTabletTracking(true);
        pushButtonNext1->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        centerPointText = new QLineEdit(Step1);
        centerPointText->setObjectName("centerPointText");
        centerPointText->setEnabled(false);
        centerPointText->setGeometry(QRect(760, 30, 191, 24));
        centerPointText->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        centerPointText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_guide = new QLabel(Step1);
        label_guide->setObjectName("label_guide");
        label_guide->setGeometry(QRect(10, 10, 261, 16));
        label_guide_2 = new QLabel(Step1);
        label_guide_2->setObjectName("label_guide_2");
        label_guide_2->setGeometry(QRect(230, 10, 241, 20));
        label_guide_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        tabSteps->addTab(Step1, QString());
        Step2 = new QWidget();
        Step2->setObjectName("Step2");
        Step2->setEnabled(true);
        pushButtonBack2 = new QPushButton(Step2);
        pushButtonBack2->setObjectName("pushButtonBack2");
        pushButtonBack2->setGeometry(QRect(880, 30, 80, 24));
        pushButtonBack2->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        pushButtonNext2 = new QPushButton(Step2);
        pushButtonNext2->setObjectName("pushButtonNext2");
        pushButtonNext2->setEnabled(true);
        pushButtonNext2->setGeometry(QRect(970, 30, 80, 24));
        pushButtonNext2->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        pushButtonGenerate2 = new QPushButton(Step2);
        pushButtonGenerate2->setObjectName("pushButtonGenerate2");
        pushButtonGenerate2->setGeometry(QRect(390, 40, 131, 24));
        pushButtonGenerate2->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        progressBar = new QProgressBar(Step2);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(10, 40, 241, 21));
        progressBar->setValue(0);
        infoStep2 = new QLineEdit(Step2);
        infoStep2->setObjectName("infoStep2");
        infoStep2->setEnabled(false);
        infoStep2->setGeometry(QRect(10, 10, 241, 24));
        infoStep2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        doubleSpinBoxWidth = new QDoubleSpinBox(Step2);
        doubleSpinBoxWidth->setObjectName("doubleSpinBoxWidth");
        doubleSpinBoxWidth->setEnabled(true);
        doubleSpinBoxWidth->setGeometry(QRect(610, 10, 71, 25));
        QFont font;
        font.setPointSize(7);
        doubleSpinBoxWidth->setFont(font);
        doubleSpinBoxWidth->setMinimum(0.100000000000000);
        doubleSpinBoxWidth->setSingleStep(0.500000000000000);
        doubleSpinBoxWidth->setValue(1.500000000000000);
        label = new QLabel(Step2);
        label->setObjectName("label");
        label->setGeometry(QRect(540, 10, 71, 21));
        label_2 = new QLabel(Step2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(690, 10, 81, 21));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_2->setPalette(palette);
        label_3 = new QLabel(Step2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(690, 40, 81, 16));
        QPalette palette1;
        QBrush brush3(QColor(0, 0, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_3->setPalette(palette1);
        doubleSpinBoxTop = new QDoubleSpinBox(Step2);
        doubleSpinBoxTop->setObjectName("doubleSpinBoxTop");
        doubleSpinBoxTop->setEnabled(false);
        doubleSpinBoxTop->setGeometry(QRect(771, 10, 91, 25));
        doubleSpinBoxTop->setFont(font);
        doubleSpinBoxTop->setMinimum(-1000.000000000000000);
        doubleSpinBoxTop->setMaximum(1000.000000000000000);
        doubleSpinBoxTop->setSingleStep(1.000000000000000);
        doubleSpinBoxBottom = new QDoubleSpinBox(Step2);
        doubleSpinBoxBottom->setObjectName("doubleSpinBoxBottom");
        doubleSpinBoxBottom->setEnabled(false);
        doubleSpinBoxBottom->setGeometry(QRect(771, 40, 91, 25));
        doubleSpinBoxBottom->setFont(font);
        doubleSpinBoxBottom->setMinimum(-1000.000000000000000);
        doubleSpinBoxBottom->setMaximum(1000.000000000000000);
        line = new QFrame(Step2);
        line->setObjectName("line");
        line->setGeometry(QRect(250, 0, 20, 81));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        comboBoxDirection = new QComboBox(Step2);
        comboBoxDirection->addItem(QString());
        comboBoxDirection->addItem(QString());
        comboBoxDirection->setObjectName("comboBoxDirection");
        comboBoxDirection->setGeometry(QRect(390, 10, 131, 24));
        QFont font1;
        font1.setBold(false);
        comboBoxDirection->setFont(font1);
        label_4 = new QLabel(Step2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(270, 10, 141, 20));
        line_2 = new QFrame(Step2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(520, 0, 20, 91));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(Step2);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(860, -10, 20, 91));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        tabSteps->addTab(Step2, QString());
        Step3 = new QWidget();
        Step3->setObjectName("Step3");
        Step3->setEnabled(true);
        pushButtonBack3 = new QPushButton(Step3);
        pushButtonBack3->setObjectName("pushButtonBack3");
        pushButtonBack3->setGeometry(QRect(880, 30, 80, 24));
        pushButtonBack3->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        pushButtonSave3 = new QPushButton(Step3);
        pushButtonSave3->setObjectName("pushButtonSave3");
        pushButtonSave3->setGeometry(QRect(970, 30, 80, 24));
        QFont font2;
        font2.setBold(true);
        pushButtonSave3->setFont(font2);
        pushButtonSave3->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        checkBoxShowMesh = new QCheckBox(Step3);
        checkBoxShowMesh->setObjectName("checkBoxShowMesh");
        checkBoxShowMesh->setGeometry(QRect(20, 20, 121, 31));
        checkBoxShowMesh->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        checkBoxShowMesh->setChecked(true);
        checkBoxShowMesh->setTristate(false);
        checkBoxShowPiece = new QCheckBox(Step3);
        checkBoxShowPiece->setObjectName("checkBoxShowPiece");
        checkBoxShowPiece->setGeometry(QRect(140, 20, 111, 31));
        checkBoxShowPiece->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        checkBoxShowPiece->setChecked(true);
        checkBoxShowPiece->setTristate(false);
        tabSteps->addTab(Step3, QString());

        gridLayout->addWidget(tabSteps, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1080, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName("menuAyuda");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        QWidget::setTabOrder(pushButtonNext1, comboBoxDirection);
        QWidget::setTabOrder(comboBoxDirection, pushButtonGenerate2);
        QWidget::setTabOrder(pushButtonGenerate2, doubleSpinBoxWidth);
        QWidget::setTabOrder(doubleSpinBoxWidth, doubleSpinBoxTop);
        QWidget::setTabOrder(doubleSpinBoxTop, doubleSpinBoxBottom);
        QWidget::setTabOrder(doubleSpinBoxBottom, pushButtonBack2);
        QWidget::setTabOrder(pushButtonBack2, pushButtonNext2);
        QWidget::setTabOrder(pushButtonNext2, checkBoxShowMesh);
        QWidget::setTabOrder(checkBoxShowMesh, pushButtonBack3);
        QWidget::setTabOrder(pushButtonBack3, pushButtonSave3);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuView->addAction(actionReset);
        menuView->addAction(actionSettings);
        menuAyuda->addAction(actionManual_b_sico);
        menuAyuda->addAction(actionManual_avanzado);
        menuAyuda->addAction(actionInformaci_n);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionReset);

        retranslateUi(MainWindow);

        tabSteps->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Glass3D", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Abrir", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Abrir fichero STL", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Cerrar", nullptr));
#if QT_CONFIG(tooltip)
        actionQuit->setToolTip(QCoreApplication::translate("MainWindow", "Cerrar Glass3D", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReset->setText(QCoreApplication::translate("MainWindow", "&Reiniciar", nullptr));
#if QT_CONFIG(tooltip)
        actionReset->setToolTip(QCoreApplication::translate("MainWindow", "Reiniciar vista", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionReset->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSettings->setText(QCoreApplication::translate("MainWindow", "&Preferencias", nullptr));
#if QT_CONFIG(tooltip)
        actionSettings->setToolTip(QCoreApplication::translate("MainWindow", "Preferencias de Glass3D", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSettings->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionManual_b_sico->setText(QCoreApplication::translate("MainWindow", "&Manual b\303\241sico", nullptr));
#if QT_CONFIG(shortcut)
        actionManual_b_sico->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionManual_avanzado->setText(QCoreApplication::translate("MainWindow", "Manual avanzado", nullptr));
#if QT_CONFIG(shortcut)
        actionManual_avanzado->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionInformaci_n->setText(QCoreApplication::translate("MainWindow", "Informaci\303\263n", nullptr));
#if QT_CONFIG(shortcut)
        actionInformaci_n->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        infoStep1->setText(QCoreApplication::translate("MainWindow", "Seleccione un punto del molde con clic derecho para generar el centro...", nullptr));
        labelStep1Center->setText(QCoreApplication::translate("MainWindow", "Centro de la escena:", nullptr));
        pushButtonNext1->setText(QCoreApplication::translate("MainWindow", "&Siguiente", nullptr));
        centerPointText->setText(QString());
        label_guide->setText(QCoreApplication::translate("MainWindow", "Clic IZQ: Movimiento de la c\303\241mara", nullptr));
        label_guide_2->setText(QCoreApplication::translate("MainWindow", "Clic DER: Generar centro", nullptr));
        tabSteps->setTabText(tabSteps->indexOf(Step1), QCoreApplication::translate("MainWindow", "Paso 1", nullptr));
#if QT_CONFIG(tooltip)
        tabSteps->setTabToolTip(tabSteps->indexOf(Step1), QCoreApplication::translate("MainWindow", "Selecci\303\263n de altura del plano de corte", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonBack2->setText(QCoreApplication::translate("MainWindow", "&Volver", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonNext2->setToolTip(QCoreApplication::translate("MainWindow", "Generaci\303\263n del positivo", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonNext2->setText(QCoreApplication::translate("MainWindow", "&Siguiente", nullptr));
        pushButtonGenerate2->setText(QCoreApplication::translate("MainWindow", "&Generar Preview", nullptr));
        infoStep2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Grosor (mm)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Corte superior", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Base interior", nullptr));
        comboBoxDirection->setItemText(0, QCoreApplication::translate("MainWindow", "Izquierda  (-X)", nullptr));
        comboBoxDirection->setItemText(1, QCoreApplication::translate("MainWindow", "Derecha   (+X)", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Direcci\303\263n del escaneo:", nullptr));
        tabSteps->setTabText(tabSteps->indexOf(Step2), QCoreApplication::translate("MainWindow", "Paso 2", nullptr));
#if QT_CONFIG(tooltip)
        tabSteps->setTabToolTip(tabSteps->indexOf(Step2), QCoreApplication::translate("MainWindow", "Selecci\303\263n de los vertices del plano", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonBack3->setText(QCoreApplication::translate("MainWindow", "&Volver", nullptr));
        pushButtonSave3->setText(QCoreApplication::translate("MainWindow", "&Guardar", nullptr));
        checkBoxShowMesh->setText(QCoreApplication::translate("MainWindow", "Ver &Molde", nullptr));
        checkBoxShowPiece->setText(QCoreApplication::translate("MainWindow", "Ver &Pieza", nullptr));
        tabSteps->setTabText(tabSteps->indexOf(Step3), QCoreApplication::translate("MainWindow", "Paso 3", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&Archivo", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "&Ver", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
