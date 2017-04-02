/********************************************************************************
** Form generated from reading UI file 'delboardmanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELBOARDMANAGERDIALOG_H
#define UI_DELBOARDMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_delBoardManagerDialog
{
public:
    QPushButton *confirm;
    QLabel *label;

    void setupUi(QDialog *delBoardManagerDialog)
    {
        if (delBoardManagerDialog->objectName().isEmpty())
            delBoardManagerDialog->setObjectName(QStringLiteral("delBoardManagerDialog"));
        delBoardManagerDialog->resize(555, 343);
        delBoardManagerDialog->setStyleSheet(QStringLiteral("background-image: url(:/icons/BG2.png);"));
        confirm = new QPushButton(delBoardManagerDialog);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(402, 260, 71, 28));
        label = new QLabel(delBoardManagerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 140, 321, 51));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        retranslateUi(delBoardManagerDialog);

        QMetaObject::connectSlotsByName(delBoardManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *delBoardManagerDialog)
    {
        delBoardManagerDialog->setWindowTitle(QApplication::translate("delBoardManagerDialog", "\345\210\240\351\231\244\347\211\210\344\270\273", 0));
        confirm->setText(QApplication::translate("delBoardManagerDialog", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("delBoardManagerDialog", "\347\241\256\350\256\244\345\217\226\346\266\210\350\257\245\347\224\250\346\210\267\347\232\204\347\211\210\344\270\273\346\235\203\351\231\220\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class delBoardManagerDialog: public Ui_delBoardManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELBOARDMANAGERDIALOG_H
