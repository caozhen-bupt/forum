/********************************************************************************
** Form generated from reading UI file 'inpostdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPOSTDIALOG_H
#define UI_INPOSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inPostDialog
{
public:
    QTextBrowser *postInfo;
    QTextEdit *myComment;
    QPushButton *confirm;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *up;
    QPushButton *deletePost;

    void setupUi(QDialog *inPostDialog)
    {
        if (inPostDialog->objectName().isEmpty())
            inPostDialog->setObjectName(QStringLiteral("inPostDialog"));
        inPostDialog->resize(1205, 701);
        inPostDialog->setStyleSheet(QStringLiteral("background-image: url(:/icons/BG2.png);"));
        postInfo = new QTextBrowser(inPostDialog);
        postInfo->setObjectName(QStringLiteral("postInfo"));
        postInfo->setGeometry(QRect(130, 130, 931, 391));
        QFont font;
        font.setPointSize(12);
        postInfo->setFont(font);
        myComment = new QTextEdit(inPostDialog);
        myComment->setObjectName(QStringLiteral("myComment"));
        myComment->setGeometry(QRect(130, 540, 931, 87));
        QFont font1;
        font1.setPointSize(10);
        myComment->setFont(font1);
        confirm = new QPushButton(inPostDialog);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(982, 650, 81, 28));
        horizontalLayoutWidget = new QWidget(inPostDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(870, 20, 195, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        up = new QPushButton(horizontalLayoutWidget);
        up->setObjectName(QStringLiteral("up"));
        QFont font2;
        font2.setPointSize(9);
        up->setFont(font2);

        horizontalLayout->addWidget(up);

        deletePost = new QPushButton(horizontalLayoutWidget);
        deletePost->setObjectName(QStringLiteral("deletePost"));
        deletePost->setFont(font2);

        horizontalLayout->addWidget(deletePost);


        retranslateUi(inPostDialog);

        QMetaObject::connectSlotsByName(inPostDialog);
    } // setupUi

    void retranslateUi(QDialog *inPostDialog)
    {
        inPostDialog->setWindowTitle(QApplication::translate("inPostDialog", "\345\270\226\345\255\220", 0));
        confirm->setText(QApplication::translate("inPostDialog", "\346\210\221\350\246\201\350\257\204\350\256\272", 0));
        up->setText(QApplication::translate("inPostDialog", "\347\275\256\351\241\266", 0));
        deletePost->setText(QApplication::translate("inPostDialog", "\345\210\240\345\270\226", 0));
    } // retranslateUi

};

namespace Ui {
    class inPostDialog: public Ui_inPostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPOSTDIALOG_H
