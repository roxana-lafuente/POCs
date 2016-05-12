/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 11 21:26:54 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtCalc/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      20,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     133,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clear()\0clearAll()\0equals()\0"
    "add()\0substract()\0multiply()\0divide()\0"
    "zero()\0one()\0two()\0three()\0four()\0"
    "five()\0six()\0seven()\0eight()\0nine()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->clear(); break;
        case 1: _t->clearAll(); break;
        case 2: _t->equals(); break;
        case 3: _t->add(); break;
        case 4: _t->substract(); break;
        case 5: _t->multiply(); break;
        case 6: _t->divide(); break;
        case 7: _t->zero(); break;
        case 8: _t->one(); break;
        case 9: _t->two(); break;
        case 10: _t->three(); break;
        case 11: _t->four(); break;
        case 12: _t->five(); break;
        case 13: _t->six(); break;
        case 14: _t->seven(); break;
        case 15: _t->eight(); break;
        case 16: _t->nine(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
