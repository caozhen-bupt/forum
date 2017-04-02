

#include <QMessageBox.h>
#include <QTextCodec.h>

#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern std::vector<User *> uservec;
extern User *currentUser;
extern int curUserIndex;

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->txtname->setFocus();
    ui->txtpwd->setEchoMode(QLineEdit::Password);

}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_confirm_clicked()
{
    qDebug()<<"user vecsize"<<uservec.size();

    User *unknownUser = new commonUser;
    if(unknownUser->login(this->ui->txtname->text().trimmed(), this->ui->txtpwd->text().trimmed()))
    {
        accept();
    }
    else
    {
        qDebug()<<"pop out warning";
        QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误!"),QMessageBox::Yes);
        this->ui->txtname->clear();
        this->ui->txtpwd->clear();
        this->ui->txtname->setFocus();
    }
    delete unknownUser;
}

void loginDialog::on_cancel_clicked()
{
    this->close();
    exit(0);
}


