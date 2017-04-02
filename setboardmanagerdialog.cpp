#include "setboardmanagerdialog.h"
#include "ui_setboardmanagerdialog.h"
#include "user.h"

extern User *currentUser;

setBoardManagerDialog::setBoardManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setBoardManagerDialog)
{
    ui->setupUi(this);
}

setBoardManagerDialog::~setBoardManagerDialog()
{
    delete ui;
}

void setBoardManagerDialog::on_confirm_clicked()
{
    QString board = ui->comboBox->currentText();
    if(board == "学术科技")
    {
        currentUser->addBoardManager(index, academics);
        qDebug()<<"academics addBM";
    }
    else if(board == "信息社会")
    {
        currentUser->addBoardManager(index, information);
        qDebug()<<"information addBM";
    }
    else if(board == "情感天地")
    {
        currentUser->addBoardManager(index, emotions);
        qDebug()<<"emotions addBM";
    }
    close();

}
