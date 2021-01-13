/****************************************************************************
** Meta object code from reading C++ file 'newrecordwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ReceptBook/newrecordwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newrecordwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewRecordWidget_t {
    const uint offsetsAndSize[42];
    char stringdata0[456];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NewRecordWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NewRecordWidget_t qt_meta_stringdata_NewRecordWidget = {
    {
QT_MOC_LITERAL(0, 15), // "NewRecordWidget"
QT_MOC_LITERAL(16, 12), // "sendToWidget"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 4), // "name"
QT_MOC_LITERAL(35, 11), // "ingredients"
QT_MOC_LITERAL(47, 6), // "recipe"
QT_MOC_LITERAL(54, 4), // "type"
QT_MOC_LITERAL(59, 3), // "pic"
QT_MOC_LITERAL(63, 23), // "on_addPicButton_clicked"
QT_MOC_LITERAL(87, 30), // "categoriesFirstButton_selected"
QT_MOC_LITERAL(118, 31), // "categoriesSecondButton_selected"
QT_MOC_LITERAL(150, 32), // "categoriesGarnishButton_selected"
QT_MOC_LITERAL(183, 30), // "categoriesSalatButton_selected"
QT_MOC_LITERAL(214, 30), // "categoriesSauceButton_selected"
QT_MOC_LITERAL(245, 30), // "categoriesDrinkButton_selected"
QT_MOC_LITERAL(276, 33), // "categoriesMarinadeButton_sele..."
QT_MOC_LITERAL(310, 30), // "categoriesStockButton_selected"
QT_MOC_LITERAL(341, 30), // "categoriesDoughButton_selected"
QT_MOC_LITERAL(372, 30), // "categoriesSnackButton_selected"
QT_MOC_LITERAL(403, 30), // "categoriesSweetButton_selected"
QT_MOC_LITERAL(434, 21) // "on_saveButton_clicked"

    },
    "NewRecordWidget\0sendToWidget\0\0name\0"
    "ingredients\0recipe\0type\0pic\0"
    "on_addPicButton_clicked\0"
    "categoriesFirstButton_selected\0"
    "categoriesSecondButton_selected\0"
    "categoriesGarnishButton_selected\0"
    "categoriesSalatButton_selected\0"
    "categoriesSauceButton_selected\0"
    "categoriesDrinkButton_selected\0"
    "categoriesMarinadeButton_selected\0"
    "categoriesStockButton_selected\0"
    "categoriesDoughButton_selected\0"
    "categoriesSnackButton_selected\0"
    "categoriesSweetButton_selected\0"
    "on_saveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewRecordWidget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,   98,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  109,    2, 0x08,    6 /* Private */,
       9,    0,  110,    2, 0x08,    7 /* Private */,
      10,    0,  111,    2, 0x08,    8 /* Private */,
      11,    0,  112,    2, 0x08,    9 /* Private */,
      12,    0,  113,    2, 0x08,   10 /* Private */,
      13,    0,  114,    2, 0x08,   11 /* Private */,
      14,    0,  115,    2, 0x08,   12 /* Private */,
      15,    0,  116,    2, 0x08,   13 /* Private */,
      16,    0,  117,    2, 0x08,   14 /* Private */,
      17,    0,  118,    2, 0x08,   15 /* Private */,
      18,    0,  119,    2, 0x08,   16 /* Private */,
      19,    0,  120,    2, 0x08,   17 /* Private */,
      20,    0,  121,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewRecordWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewRecordWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendToWidget((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 1: _t->on_addPicButton_clicked(); break;
        case 2: _t->categoriesFirstButton_selected(); break;
        case 3: _t->categoriesSecondButton_selected(); break;
        case 4: _t->categoriesGarnishButton_selected(); break;
        case 5: _t->categoriesSalatButton_selected(); break;
        case 6: _t->categoriesSauceButton_selected(); break;
        case 7: _t->categoriesDrinkButton_selected(); break;
        case 8: _t->categoriesMarinadeButton_selected(); break;
        case 9: _t->categoriesStockButton_selected(); break;
        case 10: _t->categoriesDoughButton_selected(); break;
        case 11: _t->categoriesSnackButton_selected(); break;
        case 12: _t->categoriesSweetButton_selected(); break;
        case 13: _t->on_saveButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewRecordWidget::*)(const QString & , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewRecordWidget::sendToWidget)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NewRecordWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_NewRecordWidget.offsetsAndSize,
    qt_meta_data_NewRecordWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NewRecordWidget_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NewRecordWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewRecordWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewRecordWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int NewRecordWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void NewRecordWidget::sendToWidget(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
