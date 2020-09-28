/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../KULoaderFinal/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[18];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 15), // "onNumberChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "ifIdIsOne"
QT_MOC_LITERAL(4, 34, 9), // "onSuccess"
QT_MOC_LITERAL(5, 44, 9), // "onFailure"
QT_MOC_LITERAL(6, 54, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(7, 76, 23), // "on_browseButton_clicked"
QT_MOC_LITERAL(8, 100, 25), // "on_downloadButton_clicked"
QT_MOC_LITERAL(9, 126, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(10, 149, 23), // "on_resumeButton_clicked"
QT_MOC_LITERAL(11, 173, 26), // "on_urlPath_editingFinished"
QT_MOC_LITERAL(12, 200, 28), // "on_directory_editingFinished"
QT_MOC_LITERAL(13, 229, 27), // "on_fileName_editingFinished"
QT_MOC_LITERAL(14, 257, 21), // "on_homeButton_clicked"
QT_MOC_LITERAL(15, 279, 26), // "on_downloadsButton_clicked"
QT_MOC_LITERAL(16, 306, 22), // "on_aboutButton_clicked"
QT_MOC_LITERAL(17, 329, 24) // "on_exploreButton_clicked"

    },
    "Widget\0onNumberChanged\0\0ifIdIsOne\0"
    "onSuccess\0onFailure\0on_quitButton_clicked\0"
    "on_browseButton_clicked\0"
    "on_downloadButton_clicked\0"
    "on_pauseButton_clicked\0on_resumeButton_clicked\0"
    "on_urlPath_editingFinished\0"
    "on_directory_editingFinished\0"
    "on_fileName_editingFinished\0"
    "on_homeButton_clicked\0on_downloadsButton_clicked\0"
    "on_aboutButton_clicked\0on_exploreButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   94,    2, 0x08 /* Private */,
       3,    0,  103,    2, 0x08 /* Private */,
       4,    0,  104,    2, 0x08 /* Private */,
       5,    0,  105,    2, 0x08 /* Private */,
       6,    0,  106,    2, 0x08 /* Private */,
       7,    0,  107,    2, 0x08 /* Private */,
       8,    0,  108,    2, 0x08 /* Private */,
       9,    0,  109,    2, 0x08 /* Private */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    0,  111,    2, 0x08 /* Private */,
      12,    0,  112,    2, 0x08 /* Private */,
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,
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

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNumberChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->ifIdIsOne(); break;
        case 2: _t->onSuccess(); break;
        case 3: _t->onFailure(); break;
        case 4: _t->on_quitButton_clicked(); break;
        case 5: _t->on_browseButton_clicked(); break;
        case 6: _t->on_downloadButton_clicked(); break;
        case 7: _t->on_pauseButton_clicked(); break;
        case 8: _t->on_resumeButton_clicked(); break;
        case 9: _t->on_urlPath_editingFinished(); break;
        case 10: _t->on_directory_editingFinished(); break;
        case 11: _t->on_fileName_editingFinished(); break;
        case 12: _t->on_homeButton_clicked(); break;
        case 13: _t->on_downloadsButton_clicked(); break;
        case 14: _t->on_aboutButton_clicked(); break;
        case 15: _t->on_exploreButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
