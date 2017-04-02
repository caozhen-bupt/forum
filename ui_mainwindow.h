/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *home;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *searchkind;
    QLineEdit *searchInfo;
    QPushButton *searchconfirm;
    QListWidget *listWidget_search;
    QWidget *Acadamics;
    QListWidget *listWidget_aca;
    QWidget *Information;
    QListWidget *listWidget_info;
    QWidget *Emotions;
    QListWidget *listWidget_emo;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *userInfo;
    QPushButton *logout;
    QWidget *widget;
    QTextEdit *postcontent;
    QPushButton *sendpost;
    QLineEdit *posttitle;
    QComboBox *comboBox;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1281, 751);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(236, 244, 253);"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(140, 120, 971, 351));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(16);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        home = new QWidget();
        home->setObjectName(QStringLiteral("home"));
        horizontalLayoutWidget_2 = new QWidget(home);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 931, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchkind = new QComboBox(horizontalLayoutWidget_2);
        searchkind->setObjectName(QStringLiteral("searchkind"));
        QFont font1;
        font1.setPointSize(10);
        searchkind->setFont(font1);

        horizontalLayout_2->addWidget(searchkind);

        searchInfo = new QLineEdit(horizontalLayoutWidget_2);
        searchInfo->setObjectName(QStringLiteral("searchInfo"));
        searchInfo->setFont(font1);

        horizontalLayout_2->addWidget(searchInfo);

        searchconfirm = new QPushButton(horizontalLayoutWidget_2);
        searchconfirm->setObjectName(QStringLiteral("searchconfirm"));
        searchconfirm->setFont(font1);

        horizontalLayout_2->addWidget(searchconfirm);

        listWidget_search = new QListWidget(home);
        listWidget_search->setObjectName(QStringLiteral("listWidget_search"));
        listWidget_search->setGeometry(QRect(10, 60, 931, 241));
        tabWidget->addTab(home, QString());
        Acadamics = new QWidget();
        Acadamics->setObjectName(QStringLiteral("Acadamics"));
        listWidget_aca = new QListWidget(Acadamics);
        listWidget_aca->setObjectName(QStringLiteral("listWidget_aca"));
        listWidget_aca->setGeometry(QRect(20, 20, 931, 291));
        tabWidget->addTab(Acadamics, QString());
        Information = new QWidget();
        Information->setObjectName(QStringLiteral("Information"));
        listWidget_info = new QListWidget(Information);
        listWidget_info->setObjectName(QStringLiteral("listWidget_info"));
        listWidget_info->setGeometry(QRect(20, 20, 931, 291));
        tabWidget->addTab(Information, QString());
        Emotions = new QWidget();
        Emotions->setObjectName(QStringLiteral("Emotions"));
        listWidget_emo = new QListWidget(Emotions);
        listWidget_emo->setObjectName(QStringLiteral("listWidget_emo"));
        listWidget_emo->setGeometry(QRect(20, 20, 931, 291));
        tabWidget->addTab(Emotions, QString());
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(990, 40, 195, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userInfo = new QPushButton(horizontalLayoutWidget);
        userInfo->setObjectName(QStringLiteral("userInfo"));

        horizontalLayout->addWidget(userInfo);

        logout = new QPushButton(horizontalLayoutWidget);
        logout->setObjectName(QStringLiteral("logout"));

        horizontalLayout->addWidget(logout);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 470, 971, 231));
        postcontent = new QTextEdit(widget);
        postcontent->setObjectName(QStringLiteral("postcontent"));
        postcontent->setGeometry(QRect(0, 70, 971, 111));
        sendpost = new QPushButton(widget);
        sendpost->setObjectName(QStringLiteral("sendpost"));
        sendpost->setGeometry(QRect(910, 190, 61, 28));
        posttitle = new QLineEdit(widget);
        posttitle->setObjectName(QStringLiteral("posttitle"));
        posttitle->setGeometry(QRect(130, 30, 841, 31));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(0, 30, 101, 31));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1281, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\214\227\351\202\256\344\272\272\350\256\272\345\235\233", 0));
        searchkind->clear();
        searchkind->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\217\221\344\277\241\344\272\272", 0)
         << QApplication::translate("MainWindow", "\346\240\207\351\242\230", 0)
        );
        searchconfirm->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(home), QApplication::translate("MainWindow", "\351\246\226\351\241\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(Acadamics), QApplication::translate("MainWindow", "\345\255\246\346\234\257\347\247\221\346\212\200", 0));
        tabWidget->setTabText(tabWidget->indexOf(Information), QApplication::translate("MainWindow", "\344\277\241\346\201\257\347\244\276\344\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(Emotions), QApplication::translate("MainWindow", "\346\203\205\346\204\237\345\244\251\345\234\260", 0));
        userInfo->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        logout->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", 0));
        sendpost->setText(QApplication::translate("MainWindow", "\345\217\221\345\270\226", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\255\246\346\234\257\347\247\221\346\212\200", 0)
         << QApplication::translate("MainWindow", "\344\277\241\346\201\257\347\244\276\344\274\232", 0)
         << QApplication::translate("MainWindow", "\346\203\205\346\204\237\345\244\251\345\234\260", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
