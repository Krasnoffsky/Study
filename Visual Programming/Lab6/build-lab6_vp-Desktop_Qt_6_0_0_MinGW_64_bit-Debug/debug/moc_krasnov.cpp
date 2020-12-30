/****************************************************************************
** Meta object code from reading C++ file 'krasnov.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab6_vp/krasnov.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'krasnov.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_krasnov_t {
    const uint offsetsAndSize[14];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_krasnov_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_krasnov_t qt_meta_stringdata_krasnov = {
    {
QT_MOC_LITERAL(0, 7), // "krasnov"
QT_MOC_LITERAL(8, 10), // "reciveData"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 3), // "str"
QT_MOC_LITERAL(24, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(45, 16), // "QAbstractButton*"
QT_MOC_LITERAL(62, 6) // "button"

    },
    "krasnov\0reciveData\0\0str\0on_buttonBox_clicked\0"
    "QAbstractButton*\0button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_krasnov[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    0 /* Public */,
       4,    1,   29,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void krasnov::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<krasnov *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reciveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject krasnov::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_krasnov.offsetsAndSize,
    qt_meta_data_krasnov,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_krasnov_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>


>,
    nullptr
} };


const QMetaObject *krasnov::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *krasnov::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_krasnov.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int krasnov::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
