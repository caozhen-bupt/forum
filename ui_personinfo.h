/********************************************************************************
** Form generated from reading UI file 'personinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONINFO_H
#define UI_PERSONINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personInfo
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *id;
    QLabel *BT;

    void setupUi(QDialog *personInfo)
    {
        if (personInfo->objectName().isEmpty())
            personInfo->setObjectName(QStringLiteral("personInfo"));
        personInfo->resize(609, 392);
        personInfo->setStyleSheet(QStringLiteral("background-image: url(:/icons/BG2.png);"));
        verticalLayoutWidget = new QWidget(personInfo);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 110, 301, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(verticalLayoutWidget);
        name->setObjectName(QStringLiteral("name"));
        QFont font;
        font.setPointSize(12);
        name->setFont(font);

        verticalLayout->addWidget(name);

        id = new QLabel(verticalLayoutWidget);
        id->setObjectName(QStringLiteral("id"));
        id->setFont(font);

        verticalLayout->addWidget(id);

        BT = new QLabel(verticalLayoutWidget);
        BT->setObjectName(QStringLiteral("BT"));
        BT->setFont(font);

        verticalLayout->addWidget(BT);


        retranslateUi(personInfo);

        QMetaObject::connectSlotsByName(personInfo);
    } // setupUi

    void retranslateUi(QDialog *personInfo)
    {
        personInfo->setWindowTitle(QApplication::translate("personInfo", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        name->setText(QApplication::translate("personInfo", "TextLabel", 0));
        id->setText(QApplication::translate("personInfo", "TextLabel", 0));
        BT->setText(QApplication::translate("personInfo", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class personInfo: public Ui_personInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONINFO_H
