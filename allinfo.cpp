#include "allinfo.h"
#include "user.h"
#include "ui_allinfo.h"
#include <QMessageBox>

extern std::vector<User *> uservec;
extern int curUserIndex;
extern QTextCodec *codec;

allInfo::allInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allInfo)
{
    ui->setupUi(this);
    ui->info->clear();
    ui->info->setResizeMode(QListView::Adjust);
    ui->info->setAutoScroll(true);

    int userflag;
    QString username;
    QString userIDs;
    BoardType BT;

    QWidget *wContainer = new QWidget(ui->info);
    QHBoxLayout *hLayout = new QHBoxLayout(wContainer);

    QLabel *infousername = new QLabel(tr("用户名"));
    QLabel *infouserIDs = new QLabel(tr("id"));
    QLabel *infouserflag = new QLabel(tr("用户权限"));

    infousername->setFixedWidth(70);
    infouserIDs->setFixedWidth(70);
    infouserflag->setFixedWidth(120);

    hLayout->addWidget(infousername);
    hLayout->addWidget(infouserIDs);
    hLayout->addWidget(infouserflag);
    hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来

    wContainer->resize(350,50);

    QListWidgetItem *infoItem = new QListWidgetItem(ui->info);
    ui->info->setItemWidget(infoItem,wContainer);

    qDebug()<<"in allinfodlg:"<<uservec.size();
    for(unsigned int i = 0; i < uservec.size(); i++)
    {
        uservec[i]->checkUserInfo(i, userflag, username, userIDs, BT);
        qDebug()<<"in allinfodlg"<<i<<userflag<<username<<userIDs;

        wContainer = new QWidget(ui->info);
        hLayout = new QHBoxLayout(wContainer);

        infousername = new QLabel(username);
        infouserIDs = new QLabel(userIDs);
        infouserflag = nullptr;


        if(userflag == 0)
        {
            infouserflag = new QLabel(tr("管理员"));
        }
        else if(userflag == 1)
        {
            infouserflag = new QLabel(tr("普通用户"));
        }
        else if(userflag == 2)
        {
            if(BT == academics)
            {
                infouserflag = new QLabel(tr("版主:学术科技"));
            }
            else if(BT == information)
            {
                infouserflag = new QLabel(tr("版主:信息社会"));
            }
            else if(BT == emotions)
            {
                infouserflag = new QLabel(tr("版主:情感天地"));
            }
        }

        infousername->setFixedWidth(70);
        infouserIDs->setFixedWidth(70);
        infouserflag->setFixedWidth(120);

        hLayout->addWidget(infousername);
        hLayout->addWidget(infouserIDs);
        hLayout->addWidget(infouserflag);
        hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
        wContainer->resize(350,50);

        QListWidgetItem *infoItem = new QListWidgetItem(ui->info);
        ui->info->setItemWidget(infoItem, wContainer);
    }
}

allInfo::~allInfo()
{
    delete ui;
}

void allInfo::setBM(const int &baseindex)
{
    setBoardManagerDialog *setBMdlg = new setBoardManagerDialog(this);
    setBMdlg->index = baseindex;
    setBMdlg->exec();
}

void allInfo::delBM(const int &baseindex)
{
    delBoardManagerDialog *delBMdlg = new delBoardManagerDialog(this);
    delBMdlg->index = baseindex;
    delBMdlg->exec();
}

void allInfo::on_info_clicked(const QModelIndex &index)
{
    unsigned int row = ui->info->currentRow();
    qDebug()<<"currentrow"<<row;
    int Flag;
    QString name;
    QString pwds;
    QString IDs;
    if(row == 1)
    {
        QMessageBox::information(this,tr("提示"),tr("管理员不能设置为版主!"),QMessageBox::Yes);
    }
    if(row >= 1 && row <= uservec.size())
    {
        uservec[row-1]->getUser(Flag, name, IDs, pwds);
        if(Flag == 1)
        {
            setBM(row-1);
        }
        else if(Flag == 2)
        {
            delBM(row-1);
        }
    }
}

void allInfo::on_fresh_clicked()
{
    ui->info->clear();
    ui->info->setResizeMode(QListView::Adjust);
    ui->info->setAutoScroll(true);

    int userflag;
    QString username;
    QString userIDs;
    BoardType BT;

    QWidget *wContainer = new QWidget(ui->info);
    QHBoxLayout *hLayout = new QHBoxLayout(wContainer);

    QLabel *infousername = new QLabel(tr("用户名"));
    QLabel *infouserIDs = new QLabel(tr("id"));
    QLabel *infouserflag = new QLabel(tr("用户权限"));

    infousername->setFixedWidth(70);
    infouserIDs->setFixedWidth(70);
    infouserflag->setFixedWidth(120);

    hLayout->addWidget(infousername);
    hLayout->addWidget(infouserIDs);
    hLayout->addWidget(infouserflag);
    hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
    wContainer->resize(350,50);

    QListWidgetItem *infoItem = new QListWidgetItem(ui->info);
    ui->info->setItemWidget(infoItem,wContainer);

    qDebug()<<"in allinfodlg:"<<uservec.size();
    for(unsigned int i = 0; i < uservec.size(); i++)
    {
        uservec[i]->checkUserInfo(i, userflag, username, userIDs, BT);
        qDebug()<<"in allinfodlg"<<i<<userflag<<username<<userIDs;

        wContainer = new QWidget(ui->info);
        hLayout = new QHBoxLayout(wContainer);

        infousername = new QLabel(username);
        infouserIDs = new QLabel(userIDs);
        infouserflag = nullptr;


        if(userflag == 0)
        {
            infouserflag = new QLabel(tr("管理员"));
        }
        else if(userflag == 1)
        {
            infouserflag = new QLabel(tr("普通用户"));
        }
        else if(userflag == 2)
        {
            if(BT == academics)
            {
                infouserflag = new QLabel(tr("版主:学术科技"));
            }
            else if(BT == information)
            {
                infouserflag = new QLabel(tr("版主:信息社会"));
            }
            else if(BT == emotions)
            {
                infouserflag = new QLabel(tr("版主:情感天地"));
            }
        }

        infousername->setFixedWidth(70);
        infouserIDs->setFixedWidth(70);
        infouserflag->setFixedWidth(120);

        hLayout->addWidget(infousername);
        hLayout->addWidget(infouserIDs);
        hLayout->addWidget(infouserflag);
        hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
        wContainer->resize(350,50);

        QListWidgetItem *infoItem = new QListWidgetItem(ui->info);
        ui->info->setItemWidget(infoItem, wContainer);
    }
}
