/****************************************************************************
** Meta object code from reading C++ file 'consecutiveraycaster.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../consecutiveraycaster.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consecutiveraycaster.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS = QtMocHelpers::stringData(
    "ConsecutiveRayCaster",
    "rayCastingFinished",
    "",
    "rayCasterProgressBar",
    "n",
    "emitRayCasterProgressBar",
    "handleFinish",
    "QList<HitPoint>",
    "collisions"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[21];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[2];
    char stringdata5[25];
    char stringdata6[13];
    char stringdata7[16];
    char stringdata8[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS_t qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "ConsecutiveRayCaster"
        QT_MOC_LITERAL(21, 18),  // "rayCastingFinished"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 20),  // "rayCasterProgressBar"
        QT_MOC_LITERAL(62, 1),  // "n"
        QT_MOC_LITERAL(64, 24),  // "emitRayCasterProgressBar"
        QT_MOC_LITERAL(89, 12),  // "handleFinish"
        QT_MOC_LITERAL(102, 15),  // "QList<HitPoint>"
        QT_MOC_LITERAL(118, 10)   // "collisions"
    },
    "ConsecutiveRayCaster",
    "rayCastingFinished",
    "",
    "rayCasterProgressBar",
    "n",
    "emitRayCasterProgressBar",
    "handleFinish",
    "QList<HitPoint>",
    "collisions"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConsecutiveRayCasterENDCLASS[] = {

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
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    1,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   42,    2, 0x0a,    4 /* Public */,
       6,    1,   45,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject ConsecutiveRayCaster::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConsecutiveRayCasterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ConsecutiveRayCaster, std::true_type>,
        // method 'rayCastingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rayCasterProgressBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'emitRayCasterProgressBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleFinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<HitPoint>, std::false_type>
    >,
    nullptr
} };

void ConsecutiveRayCaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConsecutiveRayCaster *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rayCastingFinished(); break;
        case 1: _t->rayCasterProgressBar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->emitRayCasterProgressBar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->handleFinish((*reinterpret_cast< std::add_pointer_t<QList<HitPoint>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConsecutiveRayCaster::*)();
            if (_t _q_method = &ConsecutiveRayCaster::rayCastingFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConsecutiveRayCaster::*)(int );
            if (_t _q_method = &ConsecutiveRayCaster::rayCasterProgressBar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ConsecutiveRayCaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsecutiveRayCaster::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConsecutiveRayCasterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConsecutiveRayCaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ConsecutiveRayCaster::rayCastingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConsecutiveRayCaster::rayCasterProgressBar(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP