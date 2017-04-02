/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QPushButton *confirm;
    QPushButton *cancel;
    QLineEdit *txtname;
    QLineEdit *txtpwd;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(501, 312);
        loginDialog->setStyleSheet(QStringLiteral("background-color: rgb(236, 244, 253);"));
        confirm = new QPushButton(loginDialog);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(90, 260, 93, 28));
        cancel = new QPushButton(loginDialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(320, 260, 93, 28));
        txtname = new QLineEdit(loginDialog);
        txtname->setObjectName(QStringLiteral("txtname"));
        txtname->setGeometry(QRect(222, 80, 151, 31));
        txtpwd = new QLineEdit(loginDialog);
        txtpwd->setObjectName(QStringLiteral("txtpwd"));
        txtpwd->setGeometry(QRect(222, 150, 151, 31));
        label = new QLabel(loginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 90, 71, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(loginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 160, 55, 16));
        label_2->setFont(font);
        groupBox = new QGroupBox(loginDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(90, 50, 321, 161));
        groupBox->raise();
        confirm->raise();
        cancel->raise();
        txtname->raise();
        txtpwd->raise();
        label->raise();
        label_2->raise();

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "\347\231\273\351\231\206", 0));
        confirm->setText(QApplication::translate("loginDialog", "\347\241\256\345\256\232", 0));
        cancel->setText(QApplication::translate("loginDialog", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201\357\274\232", 0));
        groupBox->setTitle(QApplication::translate("loginDialog", "\347\231\273\351\231\206\351\252\214\350\257\201", 0));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
