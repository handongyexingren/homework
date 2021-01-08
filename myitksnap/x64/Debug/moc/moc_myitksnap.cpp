/****************************************************************************
** Meta object code from reading C++ file 'myitksnap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../myitksnap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myitksnap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myitksnap_t {
    QByteArrayData data[9];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myitksnap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myitksnap_t qt_meta_stringdata_myitksnap = {
    {
QT_MOC_LITERAL(0, 0, 9), // "myitksnap"
QT_MOC_LITERAL(1, 10, 13), // "firstDrawLine"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(4, 49, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(5, 74, 21), // "on_action3D_triggered"
QT_MOC_LITERAL(6, 96, 28), // "on_actionThreshold_triggered"
QT_MOC_LITERAL(7, 125, 32), // "on_actionRegionGrowing_triggered"
QT_MOC_LITERAL(8, 158, 25) // "on_actionWindow_triggered"

    },
    "myitksnap\0firstDrawLine\0\0"
    "on_actionOpen_triggered\0"
    "on_actionClose_triggered\0on_action3D_triggered\0"
    "on_actionThreshold_triggered\0"
    "on_actionRegionGrowing_triggered\0"
    "on_actionWindow_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myitksnap[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myitksnap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myitksnap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstDrawLine(); break;
        case 1: _t->on_actionOpen_triggered(); break;
        case 2: _t->on_actionClose_triggered(); break;
        case 3: _t->on_action3D_triggered(); break;
        case 4: _t->on_actionThreshold_triggered(); break;
        case 5: _t->on_actionRegionGrowing_triggered(); break;
        case 6: _t->on_actionWindow_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject myitksnap::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_myitksnap.data,
    qt_meta_data_myitksnap,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myitksnap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myitksnap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myitksnap.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int myitksnap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
