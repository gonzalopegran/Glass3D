
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QSG_RHI_BACKEND", "opengl");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
