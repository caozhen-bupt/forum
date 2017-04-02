#include "personinfo.h"
#include "ui_personinfo.h"
#include "user.h"

extern std::vector<User *> uservec;
extern int curUserIndex;
extern User *currentUser;

personInfo::personInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personInfo)
{
    ui->setupUi(this);
    ui->name->clear();
    ui->id->clear();
    ui->BT->clear();
    int userflag;
    QString username;
    QString userIDs;
    BoardType BT = (BoardType)3;
    uservec[curUserIndex]->checkUserInfo(curUserIndex, userflag, username, userIDs, BT);
    QString nametxt = "我的昵称："+username;
    QString idtxt = "我的id："+userIDs;
    QString BTText;
    if(BT == academics)
    {
        BTText = "版主：学术科技";
    }
    else if(BT == information)
    {
        BTText = "版主：信息社会";
    }
    else if(BT == emotions)
    {
        BTText = "版主：情感天地";
    }
    else
    {
        BTText = "普通用户";
    }
    qDebug()<<BTText;
    ui->name->setText(nametxt);
    ui->id->setText(idtxt);
    ui->BT->setText(BTText);
}

personInfo::~personInfo()
{
    delete ui;
}
