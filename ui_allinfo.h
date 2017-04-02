/********************************************************************************
** Form generated from reading UI file 'allinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLINFO_H
#define UI_ALLINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_allInfo
{
public:
    QLabel *hello;
    QListWidget *info;
    QPushButton *fresh;

    void setupUi(QDialog *allInfo)
    {
        if (allInfo->objectName().isEmpty())
            allInfo->setObjectName(QStringLiteral("allInfo"));
        allInfo->resize(1099, 557);
        allInfo->setStyleSheet(QLatin1String("\n"
"background-color: rgb(236, 244, 253);"));
        hello = new QLabel(allInfo);
        hello->setObjectName(QStringLiteral("hello"));
        hello->setGeometry(QRect(810, 100, 151, 51));
        QFont font;
        font.setPointSize(14);
        hello->setFont(font);
        info = new QListWidget(allInfo);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(165, 201, 761, 311));
        info->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        fresh = new QPushButton(allInfo);
        fresh->setObjectName(QStringLiteral("fresh"));
        fresh->setGeometry(QRect(810, 160, 93, 28));

        retranslateUi(allInfo);

        QMetaObject::connectSlotsByName(allInfo);
    } // setupUi

    void retranslateUi(QDialog *allInfo)
    {
        allInfo->setWindowTitle(QApplication::translate("allInfo", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        hello->setText(QApplication::translate("allInfo", "Hello, admin!", 0));
        fresh->setText(QApplication::translate("allInfo", "\345\210\267\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class allInfo: public Ui_allInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLINFO_H
