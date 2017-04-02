/********************************************************************************
** Form generated from reading UI file 'setboardmanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETBOARDMANAGERDIALOG_H
#define UI_SETBOARDMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setBoardManagerDialog
{
public:
    QComboBox *comboBox;
    QPushButton *confirm;

    void setupUi(QDialog *setBoardManagerDialog)
    {
        if (setBoardManagerDialog->objectName().isEmpty())
            setBoardManagerDialog->setObjectName(QStringLiteral("setBoardManagerDialog"));
        setBoardManagerDialog->resize(400, 300);
        setBoardManagerDialog->setStyleSheet(QStringLiteral("background-image: url(:/icons/BG2.png);"));
        comboBox = new QComboBox(setBoardManagerDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 140, 151, 31));
        QFont font;
        font.setPointSize(12);
        comboBox->setFont(font);
        confirm = new QPushButton(setBoardManagerDialog);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(282, 250, 71, 28));

        retranslateUi(setBoardManagerDialog);

        QMetaObject::connectSlotsByName(setBoardManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *setBoardManagerDialog)
    {
        setBoardManagerDialog->setWindowTitle(QApplication::translate("setBoardManagerDialog", "\350\256\276\347\275\256\347\211\210", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("setBoardManagerDialog", "\345\255\246\346\234\257\347\247\221\346\212\200", 0)
         << QApplication::translate("setBoardManagerDialog", "\344\277\241\346\201\257\347\244\276\344\274\232", 0)
         << QApplication::translate("setBoardManagerDialog", "\346\203\205\346\204\237\345\244\251\345\234\260", 0)
        );
        confirm->setText(QApplication::translate("setBoardManagerDialog", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class setBoardManagerDialog: public Ui_setBoardManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETBOARDMANAGERDIALOG_H
