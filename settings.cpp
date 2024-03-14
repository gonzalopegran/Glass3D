#include "settings.h"
#include "ui_settings.h"
#include <QFile>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(saveSettings()));
    connect(ui->pushButtonDefault, SIGNAL(clicked()), this, SLOT(setDefaultValues()));

    if (QFile::exists("cfg_Glass3D.ini")) {
        QSettings settings("cfg_Glass3D.ini",QSettings::Format::IniFormat);
        // Defaults
        ui->doubleSpinBoxWidth->setValue(settings.value("Defaults/border_width").toDouble());
        if (settings.value("Defaults/scan_direction").toString() == "R")
            ui->comboBoxDirection->setCurrentIndex(1);
        ui->lineEditSaveSuffix->setText(settings.value("Defaults/save_suffix").toString());

        // Generation
        ui->spinBoxScans->setValue(settings.value("Generation/scan_points").toInt());
        ui->spinBoxGeneration->setValue(settings.value("Generation/generation_points").toInt());
    }
}

Settings::~Settings()
{
    delete ui;
}

void Settings::saveSettings() {
    QSettings settings("cfg_Glass3D.ini",QSettings::Format::IniFormat);

    // Defaults
    settings.setValue("Defaults/border_width",ui->doubleSpinBoxWidth->value());
    if (ui->comboBoxDirection->currentIndex()==0)
        settings.setValue("Defaults/scan_direction","L");
    else
        settings.setValue("Defaults/scan_direction","R");
    settings.setValue("Defaults/save_suffix",ui->lineEditSaveSuffix->text());

    // Generation
    settings.setValue("Generation/scan_points",ui->spinBoxScans->value());
    settings.setValue("Generation/generation_points",ui->spinBoxGeneration->value());

    emit changed();
}

void Settings::setDefaultValues() {
    ui->doubleSpinBoxWidth->setValue(1.5);
    ui->comboBoxDirection->setCurrentIndex(0);
    ui->lineEditSaveSuffix->setText("");

    // Generation
    ui->spinBoxScans->setValue(400);
    ui->spinBoxGeneration->setValue(256);

}
