/****************************************************************************
** Meta object code from reading C++ file 'ebox_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ebox_qt_pkg/include/ebox_qt_pkg/ebox_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ebox_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Eboxmainwindow_t {
    QByteArrayData data[11];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Eboxmainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Eboxmainwindow_t qt_meta_stringdata_Eboxmainwindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Eboxmainwindow"
QT_MOC_LITERAL(1, 15, 12), // "timer_update"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 29), // "on_forward_pushButton_pressed"
QT_MOC_LITERAL(4, 59, 30), // "on_forward_pushButton_released"
QT_MOC_LITERAL(5, 90, 26), // "on_back_pushButton_pressed"
QT_MOC_LITERAL(6, 117, 27), // "on_back_pushButton_released"
QT_MOC_LITERAL(7, 145, 26), // "on_left_pushButton_pressed"
QT_MOC_LITERAL(8, 172, 27), // "on_left_pushButton_released"
QT_MOC_LITERAL(9, 200, 27), // "on_right_pushButton_pressed"
QT_MOC_LITERAL(10, 228, 28) // "on_right_pushButton_released"

    },
    "Eboxmainwindow\0timer_update\0\0"
    "on_forward_pushButton_pressed\0"
    "on_forward_pushButton_released\0"
    "on_back_pushButton_pressed\0"
    "on_back_pushButton_released\0"
    "on_left_pushButton_pressed\0"
    "on_left_pushButton_released\0"
    "on_right_pushButton_pressed\0"
    "on_right_pushButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Eboxmainwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void Eboxmainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Eboxmainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timer_update(); break;
        case 1: _t->on_forward_pushButton_pressed(); break;
        case 2: _t->on_forward_pushButton_released(); break;
        case 3: _t->on_back_pushButton_pressed(); break;
        case 4: _t->on_back_pushButton_released(); break;
        case 5: _t->on_left_pushButton_pressed(); break;
        case 6: _t->on_left_pushButton_released(); break;
        case 7: _t->on_right_pushButton_pressed(); break;
        case 8: _t->on_right_pushButton_released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Eboxmainwindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Eboxmainwindow.data,
    qt_meta_data_Eboxmainwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Eboxmainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Eboxmainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Eboxmainwindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Eboxmainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
