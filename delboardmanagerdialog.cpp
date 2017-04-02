#include "delboardmanagerdialog.h"
#include "ui_delboardmanagerdialog.h"

#include "user.h"
extern User *currentUser;
delBoardManagerDialog::delBoardManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delBoardManagerDialog)
{
    ui->setupUi(this);
}

delBoardManagerDialog::~delBoardManagerDialog()
{
    delete ui;
}

void delBoardManagerDialog::on_confirm_clicked()
{
    currentUser->delBoardManager(index);
    close();
}
