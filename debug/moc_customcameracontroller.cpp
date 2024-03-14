/****************************************************************************
** Meta object code from reading C++ file 'customcameracontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../customcameracontroller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customcameracontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS = QtMocHelpers::stringData(
    "CustomCameraController",
    "activeChanged",
    "",
    "isActive",
    "valueChanged",
    "value",
    "frameActionTriggered",
    "dt",
    "zoomCamera"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[23];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[13];
    char stringdata5[6];
    char stringdata6[21];
    char stringdata7[3];
    char stringdata8[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS_t qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "CustomCameraController"
        QT_MOC_LITERAL(23, 13),  // "activeChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 8),  // "isActive"
        QT_MOC_LITERAL(47, 12),  // "valueChanged"
        QT_MOC_LITERAL(60, 5),  // "value"
        QT_MOC_LITERAL(66, 20),  // "frameActionTriggered"
        QT_MOC_LITERAL(87, 2),  // "dt"
        QT_MOC_LITERAL(90, 10)   // "zoomCamera"
    },
    "CustomCameraController",
    "activeChanged",
    "",
    "isActive",
    "valueChanged",
    "value",
    "frameActionTriggered",
    "dt",
    "zoomCamera"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCustomCameraControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x09,    1 /* Protected */,
       4,    1,   41,    2, 0x09,    3 /* Protected */,
       6,    1,   44,    2, 0x09,    5 /* Protected */,
       8,    1,   47,    2, 0x09,    7 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject CustomCameraController::staticMetaObject = { {
    QMetaObject::SuperData::link<Qt3DCore::QEntity::staticMetaObject>(),
    qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCustomCameraControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CustomCameraController, std::true_type>,
        // method 'activeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'frameActionTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'zoomCamera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void CustomCameraController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomCameraController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->activeChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 2: _t->frameActionTriggered((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->zoomCamera((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *CustomCameraController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomCameraController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCustomCameraControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Qt3DCore::QEntity::qt_metacast(_clname);
}

int CustomCameraController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Qt3DCore::QEntity::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
