#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QString>
#include <QDebug>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;

private slots:
    void saveSettings();
    void setDefaultValues();

signals:
    void changed();

};

#endif // SETTINGS_H
