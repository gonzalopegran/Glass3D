/****************************************************************************
** Meta object code from reading C++ file 'raycasthandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../raycasthandler.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'raycasthandler.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRayCastHandlerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRayCastHandlerENDCLASS = QtMocHelpers::stringData(
    "RayCastHandler",
    "rayCastResultsChanged",
    "",
    "QList<HitPoint>",
    "collisions",
    "rayProgressBar",
    "n",
    "handleRayCasterHits",
    "Qt3DRender::QAbstractRayCaster::Hits",
    "hits",
    "handleRayCasterEnabledChange",
    "enabled"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRayCastHandlerENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[15];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[11];
    char stringdata5[15];
    char stringdata6[2];
    char stringdata7[20];
    char stringdata8[37];
    char stringdata9[5];
    char stringdata10[29];
    char stringdata11[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRayCastHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRayCastHandlerENDCLASS_t qt_meta_stringdata_CLASSRayCastHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "RayCastHandler"
        QT_MOC_LITERAL(15, 21),  // "rayCastResultsChanged"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 15),  // "QList<HitPoint>"
        QT_MOC_LITERAL(54, 10),  // "collisions"
        QT_MOC_LITERAL(65, 14),  // "rayProgressBar"
        QT_MOC_LITERAL(80, 1),  // "n"
        QT_MOC_LITERAL(82, 19),  // "handleRayCasterHits"
        QT_MOC_LITERAL(102, 36),  // "Qt3DRender::QAbstractRayCaste..."
        QT_MOC_LITERAL(139, 4),  // "hits"
        QT_MOC_LITERAL(144, 28),  // "handleRayCasterEnabledChange"
        QT_MOC_LITERAL(173, 7)   // "enabled"
    },
    "RayCastHandler",
    "rayCastResultsChanged",
    "",
    "QList<HitPoint>",
    "collisions",
    "rayProgressBar",
    "n",
    "handleRayCasterHits",
    "Qt3DRender::QAbstractRayCaster::Hits",
    "hits",
    "handleRayCasterEnabledChange",
    "enabled"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRayCastHandlerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    1,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   44,    2, 0x08,    5 /* Private */,
      10,    1,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject RayCastHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSRayCastHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRayCastHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRayCastHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RayCastHandler, std::true_type>,
        // method 'rayCastResultsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<HitPoint>, std::false_type>,
        // method 'rayProgressBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleRayCasterHits'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Qt3DRender::QAbstractRayCaster::Hits, std::false_type>,
        // method 'handleRayCasterEnabledChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>
    >,
    nullptr
} };

void RayCastHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RayCastHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rayCastResultsChanged((*reinterpret_cast< std::add_pointer_t<QList<HitPoint>>>(_a[1]))); break;
        case 1: _t->rayProgressBar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->handleRayCasterHits((*reinterpret_cast< std::add_pointer_t<Qt3DRender::QAbstractRayCaster::Hits>>(_a[1]))); break;
        case 3: _t->handleRayCasterEnabledChange((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Qt3DRender::QAbstractRayCaster::Hits >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RayCastHandler::*)(const QVector<HitPoint> );
            if (_t _q_method = &RayCastHandler::rayCastResultsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RayCastHandler::*)(int );
            if (_t _q_method = &RayCastHandler::rayProgressBar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *RayCastHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RayCastHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRayCastHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RayCastHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RayCastHandler::rayCastResultsChanged(const QVector<HitPoint> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RayCastHandler::rayProgressBar(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
