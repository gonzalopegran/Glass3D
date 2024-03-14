QT       += core gui 3dcore 3dextras 3drender 3dinput 3dlogic

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

std=c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    consecutiveraycaster.cpp \
    custom3dwindow.cpp \
    customcameracontroller.cpp \
    main.cpp \
    mainwindow.cpp \
    raycasthandler.cpp \
    settings.cpp


HEADERS += \
    consecutiveraycaster.h \
    custom3dwindow.h \
    customcameracontroller.h \
    mainwindow.h \
    mesh.h \
    raycasthandler.h \
    settings.h \
    triangle.h \
    vec3.h

FORMS += \
    mainwindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc

RC_ICONS = logo_glass3d.ico
