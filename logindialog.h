#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "user.h"
#include "mainwindow.h"




namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

private:
    Ui::loginDialog *ui;

private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();
};

#endif // LOGINDIALOG_H
