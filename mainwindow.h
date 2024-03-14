#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qt3DWindow>

#include <custom3dwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void new3DWindow();
    void init();

private:
    Ui::MainWindow *ui;
    Custom3DWindow *window;
    QString         path, lastSavePath = "";

    // CFG values
    double          defaultWidth;
    QString         defaultScanDirection, defaultSaveSuffix;

private slots:
    // MenuBar Functions
    void onFileOpen();
    void onResetView();
    void onSettings();
    void onManualB();
    void onManualA();
    void onInfo();

    // Tab Moving Functions
    void tabSelected();
    void nextStep();
    void prevStep();

    // Button Functions
    void onPushButtonGenerate2();
    void onPushButtonSave3();

    // Data changes Functions
    void onComboBoxDirectionChanged(int index);
    void onWidthChanged(double w);
    void onTopPlaneChanged();
    void onBottomPlaneChanged();
    void onMeshEnableChanged(bool enabled);
    void onMeshPositiveEnableChanged(bool enabled);
    void onSettingsChanged();

    // Functions connected to Custom3DWindow
    void centerPointTextChanged(QString s);
    void infoStep2Changed(QString s);
    void setTopPlaneSpinBox(float z);
    void setBottomPlaneSpinBox(float z);
    void messageBox(QString s);

    // Utils
    void pauseUserActions(bool enabled);
};

#endif // MAINWINDOW_H
