/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelDefaults;
    QLabel *labelWidth;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QLabel *labelDirection;
    QComboBox *comboBoxDirection;
    QLabel *labelDefaults_2;
    QLabel *labelScans;
    QLabel *labelGeneration;
    QSpinBox *spinBoxScans;
    QSpinBox *spinBoxGeneration;
    QLabel *labelSavename;
    QLineEdit *lineEditSaveSuffix;
    QPushButton *pushButtonDefault;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(400, 300);
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(190, 260, 191, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(false);
        labelDefaults = new QLabel(Settings);
        labelDefaults->setObjectName("labelDefaults");
        labelDefaults->setGeometry(QRect(20, 20, 111, 16));
        QFont font;
        font.setUnderline(true);
        labelDefaults->setFont(font);
        labelWidth = new QLabel(Settings);
        labelWidth->setObjectName("labelWidth");
        labelWidth->setGeometry(QRect(50, 50, 151, 16));
        doubleSpinBoxWidth = new QDoubleSpinBox(Settings);
        doubleSpinBoxWidth->setObjectName("doubleSpinBoxWidth");
        doubleSpinBoxWidth->setGeometry(QRect(200, 50, 111, 25));
        doubleSpinBoxWidth->setMinimum(0.050000000000000);
        doubleSpinBoxWidth->setSingleStep(0.500000000000000);
        doubleSpinBoxWidth->setValue(1.500000000000000);
        labelDirection = new QLabel(Settings);
        labelDirection->setObjectName("labelDirection");
        labelDirection->setGeometry(QRect(50, 80, 151, 16));
        comboBoxDirection = new QComboBox(Settings);
        comboBoxDirection->addItem(QString());
        comboBoxDirection->addItem(QString());
        comboBoxDirection->setObjectName("comboBoxDirection");
        comboBoxDirection->setGeometry(QRect(200, 80, 171, 24));
        QFont font1;
        font1.setBold(false);
        comboBoxDirection->setFont(font1);
        labelDefaults_2 = new QLabel(Settings);
        labelDefaults_2->setObjectName("labelDefaults_2");
        labelDefaults_2->setGeometry(QRect(20, 160, 161, 16));
        labelDefaults_2->setFont(font);
        labelScans = new QLabel(Settings);
        labelScans->setObjectName("labelScans");
        labelScans->setGeometry(QRect(50, 190, 211, 16));
        labelGeneration = new QLabel(Settings);
        labelGeneration->setObjectName("labelGeneration");
        labelGeneration->setGeometry(QRect(50, 220, 221, 16));
        spinBoxScans = new QSpinBox(Settings);
        spinBoxScans->setObjectName("spinBoxScans");
        spinBoxScans->setGeometry(QRect(270, 190, 101, 25));
        spinBoxScans->setMinimum(50);
        spinBoxScans->setMaximum(2000);
        spinBoxScans->setSingleStep(10);
        spinBoxScans->setValue(400);
        spinBoxGeneration = new QSpinBox(Settings);
        spinBoxGeneration->setObjectName("spinBoxGeneration");
        spinBoxGeneration->setGeometry(QRect(270, 220, 101, 25));
        spinBoxGeneration->setMinimum(20);
        spinBoxGeneration->setMaximum(500);
        spinBoxGeneration->setSingleStep(10);
        spinBoxGeneration->setValue(256);
        labelSavename = new QLabel(Settings);
        labelSavename->setObjectName("labelSavename");
        labelSavename->setGeometry(QRect(50, 110, 121, 16));
        lineEditSaveSuffix = new QLineEdit(Settings);
        lineEditSaveSuffix->setObjectName("lineEditSaveSuffix");
        lineEditSaveSuffix->setGeometry(QRect(200, 110, 171, 24));
        pushButtonDefault = new QPushButton(Settings);
        pushButtonDefault->setObjectName("pushButtonDefault");
        pushButtonDefault->setGeometry(QRect(20, 260, 80, 24));
        QWidget::setTabOrder(doubleSpinBoxWidth, comboBoxDirection);
        QWidget::setTabOrder(comboBoxDirection, lineEditSaveSuffix);
        QWidget::setTabOrder(lineEditSaveSuffix, spinBoxScans);
        QWidget::setTabOrder(spinBoxScans, spinBoxGeneration);

        retranslateUi(Settings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Settings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Settings, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Preferencias de Glass3D", nullptr));
        labelDefaults->setText(QCoreApplication::translate("Settings", "Valores por defecto:", nullptr));
        labelWidth->setText(QCoreApplication::translate("Settings", "Grosor de la pieza (mm):", nullptr));
        labelDirection->setText(QCoreApplication::translate("Settings", "Direcci\303\263n del escaneo:", nullptr));
        comboBoxDirection->setItemText(0, QCoreApplication::translate("Settings", "Izquierda  (-X)", nullptr));
        comboBoxDirection->setItemText(1, QCoreApplication::translate("Settings", "Derecha   (+X)", nullptr));

        labelDefaults_2->setText(QCoreApplication::translate("Settings", "Valores para la generaci\303\263n:", nullptr));
        labelScans->setText(QCoreApplication::translate("Settings", "Puntos escaneados en preview (Paso 2):", nullptr));
        labelGeneration->setText(QCoreApplication::translate("Settings", "Puntos de generaci\303\263n circular (Paso 3):", nullptr));
        labelSavename->setText(QCoreApplication::translate("Settings", "Sufijo de guardado:", nullptr));
        pushButtonDefault->setText(QCoreApplication::translate("Settings", "Por defecto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
