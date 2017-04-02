/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[31];
    char stringdata0[438];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "personalInfo"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "AllTheInfo"
QT_MOC_LITERAL(4, 36, 17), // "on_logout_clicked"
QT_MOC_LITERAL(5, 54, 19), // "on_userInfo_clicked"
QT_MOC_LITERAL(6, 74, 9), // "inThePost"
QT_MOC_LITERAL(7, 84, 17), // "std::vector<post>"
QT_MOC_LITERAL(8, 102, 7), // "postvec"
QT_MOC_LITERAL(9, 110, 5), // "index"
QT_MOC_LITERAL(10, 116, 10), // "postWriter"
QT_MOC_LITERAL(11, 127, 5), // "title"
QT_MOC_LITERAL(12, 133, 7), // "content"
QT_MOC_LITERAL(13, 141, 10), // "pubishtime"
QT_MOC_LITERAL(14, 152, 20), // "std::vector<comment>"
QT_MOC_LITERAL(15, 173, 12), // "postcomments"
QT_MOC_LITERAL(16, 186, 9), // "BoardType"
QT_MOC_LITERAL(17, 196, 8), // "postkind"
QT_MOC_LITERAL(18, 205, 6), // "tabAca"
QT_MOC_LITERAL(19, 212, 7), // "tabInfo"
QT_MOC_LITERAL(20, 220, 6), // "tabEmo"
QT_MOC_LITERAL(21, 227, 9), // "tabsearch"
QT_MOC_LITERAL(22, 237, 9), // "searchfor"
QT_MOC_LITERAL(23, 247, 10), // "searchtype"
QT_MOC_LITERAL(24, 258, 19), // "on_sendpost_clicked"
QT_MOC_LITERAL(25, 278, 25), // "on_listWidget_aca_clicked"
QT_MOC_LITERAL(26, 304, 26), // "on_listWidget_info_clicked"
QT_MOC_LITERAL(27, 331, 25), // "on_listWidget_emo_clicked"
QT_MOC_LITERAL(28, 357, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(29, 384, 24), // "on_searchconfirm_clicked"
QT_MOC_LITERAL(30, 409, 28) // "on_listWidget_search_clicked"

    },
    "MainWindow\0personalInfo\0\0AllTheInfo\0"
    "on_logout_clicked\0on_userInfo_clicked\0"
    "inThePost\0std::vector<post>\0postvec\0"
    "index\0postWriter\0title\0content\0"
    "pubishtime\0std::vector<comment>\0"
    "postcomments\0BoardType\0postkind\0tabAca\0"
    "tabInfo\0tabEmo\0tabsearch\0searchfor\0"
    "searchtype\0on_sendpost_clicked\0"
    "on_listWidget_aca_clicked\0"
    "on_listWidget_info_clicked\0"
    "on_listWidget_emo_clicked\0"
    "on_tabWidget_tabBarClicked\0"
    "on_searchconfirm_clicked\0"
    "on_listWidget_search_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    8,   98,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,
      21,    2,  118,    2, 0x08 /* Private */,
      24,    0,  123,    2, 0x08 /* Private */,
      25,    0,  124,    2, 0x08 /* Private */,
      26,    0,  125,    2, 0x08 /* Private */,
      27,    0,  126,    2, 0x08 /* Private */,
      28,    0,  127,    2, 0x08 /* Private */,
      29,    0,  128,    2, 0x08 /* Private */,
      30,    0,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 14, 0x80000000 | 16,    8,    9,   10,   11,   12,   13,   15,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   22,   23,
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
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->personalInfo(); break;
        case 1: _t->AllTheInfo(); break;
        case 2: _t->on_logout_clicked(); break;
        case 3: _t->on_userInfo_clicked(); break;
        case 4: _t->inThePost((*reinterpret_cast< std::vector<post>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< std::vector<comment>(*)>(_a[7])),(*reinterpret_cast< BoardType(*)>(_a[8]))); break;
        case 5: _t->tabAca(); break;
        case 6: _t->tabInfo(); break;
        case 7: _t->tabEmo(); break;
        case 8: _t->tabsearch((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_sendpost_clicked(); break;
        case 10: _t->on_listWidget_aca_clicked(); break;
        case 11: _t->on_listWidget_info_clicked(); break;
        case 12: _t->on_listWidget_emo_clicked(); break;
        case 13: _t->on_tabWidget_tabBarClicked(); break;
        case 14: _t->on_searchconfirm_clicked(); break;
        case 15: _t->on_listWidget_search_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
