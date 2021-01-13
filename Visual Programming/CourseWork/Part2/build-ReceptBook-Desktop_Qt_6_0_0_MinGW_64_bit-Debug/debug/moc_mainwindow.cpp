/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ReceptBook/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[490];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "currentRecipe"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 11), // "QModelIndex"
QT_MOC_LITERAL(38, 2), // "id"
QT_MOC_LITERAL(41, 21), // "on_bestButton_clicked"
QT_MOC_LITERAL(63, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(87, 26), // "on_edit_bestButton_clicked"
QT_MOC_LITERAL(114, 28), // "categoriesAllButton_selected"
QT_MOC_LITERAL(143, 30), // "categoriesFirstButton_selected"
QT_MOC_LITERAL(174, 31), // "categoriesSecondButton_selected"
QT_MOC_LITERAL(206, 32), // "categoriesGarnishButton_selected"
QT_MOC_LITERAL(239, 30), // "categoriesSalatButton_selected"
QT_MOC_LITERAL(270, 30), // "categoriesSauceButton_selected"
QT_MOC_LITERAL(301, 30), // "categoriesDrinkButton_selected"
QT_MOC_LITERAL(332, 33), // "categoriesMarinadeButton_sele..."
QT_MOC_LITERAL(366, 30), // "categoriesStockButton_selected"
QT_MOC_LITERAL(397, 30), // "categoriesDoughButton_selected"
QT_MOC_LITERAL(428, 30), // "categoriesSnackButton_selected"
QT_MOC_LITERAL(459, 30) // "categoriesSweetButton_selected"

    },
    "MainWindow\0currentRecipe\0\0QModelIndex\0"
    "id\0on_bestButton_clicked\0"
    "on_deleteButton_clicked\0"
    "on_edit_bestButton_clicked\0"
    "categoriesAllButton_selected\0"
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
    "categoriesSweetButton_selected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x08,    0 /* Private */,
       5,    0,  113,    2, 0x08,    2 /* Private */,
       6,    0,  114,    2, 0x08,    3 /* Private */,
       7,    0,  115,    2, 0x08,    4 /* Private */,
       8,    0,  116,    2, 0x08,    5 /* Private */,
       9,    0,  117,    2, 0x08,    6 /* Private */,
      10,    0,  118,    2, 0x08,    7 /* Private */,
      11,    0,  119,    2, 0x08,    8 /* Private */,
      12,    0,  120,    2, 0x08,    9 /* Private */,
      13,    0,  121,    2, 0x08,   10 /* Private */,
      14,    0,  122,    2, 0x08,   11 /* Private */,
      15,    0,  123,    2, 0x08,   12 /* Private */,
      16,    0,  124,    2, 0x08,   13 /* Private */,
      17,    0,  125,    2, 0x08,   14 /* Private */,
      18,    0,  126,    2, 0x08,   15 /* Private */,
      19,    0,  127,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentRecipe((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_bestButton_clicked(); break;
        case 2: _t->on_deleteButton_clicked(); break;
        case 3: _t->on_edit_bestButton_clicked(); break;
        case 4: _t->categoriesAllButton_selected(); break;
        case 5: _t->categoriesFirstButton_selected(); break;
        case 6: _t->categoriesSecondButton_selected(); break;
        case 7: _t->categoriesGarnishButton_selected(); break;
        case 8: _t->categoriesSalatButton_selected(); break;
        case 9: _t->categoriesSauceButton_selected(); break;
        case 10: _t->categoriesDrinkButton_selected(); break;
        case 11: _t->categoriesMarinadeButton_selected(); break;
        case 12: _t->categoriesStockButton_selected(); break;
        case 13: _t->categoriesDoughButton_selected(); break;
        case 14: _t->categoriesSnackButton_selected(); break;
        case 15: _t->categoriesSweetButton_selected(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
