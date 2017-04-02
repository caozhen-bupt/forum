#include <QMessageBox>

#include "personinfo.h"
#include "allinfo.h"
#include "user.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inpostdialog.h"

extern std::vector<User *> uservec;
extern User *currentUser;
extern int curUserIndex;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::personalInfo()
{
    personInfo * personInfoDlg = new personInfo(this);
    personInfoDlg->exec();
}

void MainWindow::AllTheInfo()
{
    allInfo * allInfoDlg = new allInfo(this);
    allInfoDlg->exec();
}


void MainWindow::on_logout_clicked()
{
    loginDialog logindlg;
    this->close();
    currentUser->logout();
    ui->searchInfo->clear();
    ui->listWidget_search->clear();
    logindlg.show();
    if(logindlg.exec() == loginDialog::Accepted)
    {
        this->show();
    }

}

void MainWindow::on_userInfo_clicked()
{
    int Flag;
    QString name;
    QString pwds;
    QString IDs;
    qDebug()<<"before function";
    uservec[curUserIndex]->getUser(Flag, name, IDs, pwds);
    qDebug()<<"curUserIndex"<<curUserIndex<<Flag;
    if(Flag == 0)
    {
        AllTheInfo();
    }
    else
    {
        personalInfo();
    }

}


void MainWindow::on_sendpost_clicked()
{
    QString board = ui->comboBox->currentText();
    QString title = ui->posttitle->text();
    QString content = ui->postcontent->toPlainText();
    QString nowTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    qDebug()<<title<<content<<nowTime;

    int flag;
    QString id;
    QString name;
    QString password;
    BoardType postBoard;
    std::vector<comment> emptycomment;

    if(title == "" || content == "")
    {
        QMessageBox::warning(this,tr("警告"),tr("标题和内容均不能为空!"),QMessageBox::Yes);
        return;
    }
    else if(title.contains('+') || title.contains('*') || title.contains('#') || title.contains("comment:") || title.contains("\n")
            || content.contains('+') || content.contains('*') || content.contains('#') || content.contains("comment:"))
    {
        QMessageBox::warning(this,tr("警告"),tr("输入非法字符！"),QMessageBox::Yes);
        ui->posttitle->clear();
        ui->postcontent->clear();
        return;
    }

    if(board == "学术科技")
    {
        postBoard = academics;
    }
    else if(board == "信息社会")
    {
        postBoard = information;
    }
    else if(board == "情感天地")
    {
        postBoard = emotions;
    }
    currentUser->getUser(flag, name, id, password);
    post posting(id, title, content, nowTime, emptycomment, postBoard);
    currentUser->sendpost(posting);

    QMessageBox::information(this,tr("提示"),tr("发帖成功!"),QMessageBox::Yes);
    this->ui->posttitle->clear();
    this->ui->postcontent->clear();
    tabAca();
    tabInfo();
    tabEmo();

}

void MainWindow::tabAca()
{
    ui->listWidget_aca->clear();

    ui->listWidget_aca->setResizeMode(QListView::Adjust);
    ui->listWidget_aca->setAutoScroll(true);

    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    QWidget *wContainer = new QWidget(ui->listWidget_aca);
    QHBoxLayout *hLayout = new QHBoxLayout(wContainer);

    QLabel *postTitle = new QLabel(tr("主题"));
    QLabel *postTime = new QLabel(tr("发帖时间"));
    QLabel *postID = new QLabel(tr("发信人"));

    postTitle->setFixedWidth(200);
    postTime->setFixedWidth(200);
    postID->setFixedWidth(80);

    hLayout->addWidget(postTitle);
    hLayout->addWidget(postTime);
    hLayout->addWidget(postID);

    hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
    wContainer->resize(350,50);

    QListWidgetItem *tabAcaItem = new QListWidgetItem(ui->listWidget_aca);
    ui->listWidget_aca->setItemWidget(tabAcaItem, wContainer);

    currentUser->scanIntoBoard(academics, postvec);
    for(unsigned int i = 0; i < postvec.size(); i++)
    {
        postvec[i].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);

        wContainer = new QWidget(ui->listWidget_aca);
        hLayout = new QHBoxLayout(wContainer);

        postTitle = new QLabel(title);
        postTime = new QLabel(pubishtime);
        postID = new QLabel(postWriter);

        postTitle->setFixedWidth(200);
        postTime->setFixedWidth(200);
        postID->setFixedWidth(80);

        hLayout->addWidget(postTitle);
        hLayout->addWidget(postTime);
        hLayout->addWidget(postID);

        hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
        wContainer->resize(350,50);

        QListWidgetItem *acaItem = new QListWidgetItem(ui->listWidget_aca);
        ui->listWidget_aca->setItemWidget(acaItem, wContainer);
    }
}

void MainWindow::tabInfo()
{
    ui->listWidget_info->clear();

    ui->listWidget_info->setResizeMode(QListView::Adjust);
    ui->listWidget_info->setAutoScroll(true);

    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    QWidget *wContainer = new QWidget(ui->listWidget_info);
    QHBoxLayout *hLayout = new QHBoxLayout(wContainer);

    QLabel *postTitle = new QLabel(tr("主题"));
    QLabel *postTime = new QLabel(tr("发帖时间"));
    QLabel *postID = new QLabel(tr("发信人"));

    postTitle->setFixedWidth(200);
    postTime->setFixedWidth(200);
    postID->setFixedWidth(80);

    hLayout->addWidget(postTitle);
    hLayout->addWidget(postTime);
    hLayout->addWidget(postID);

    hLayout->setContentsMargins(5,0,0,5);
    wContainer->resize(350,50);

    QListWidgetItem *tabAcaItem = new QListWidgetItem(ui->listWidget_info);
    ui->listWidget_info->setItemWidget(tabAcaItem, wContainer);

    currentUser->scanIntoBoard(information, postvec);
    qDebug()<<"postvec.size()"<<postvec.size();
    for(unsigned int i = 0; i < postvec.size(); i++)
    {
        postvec[i].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);

        wContainer = new QWidget(ui->listWidget_info);
        hLayout = new QHBoxLayout(wContainer);

        postTitle = new QLabel(title);
        postTime = new QLabel(pubishtime);
        postID = new QLabel(postWriter);

        postTitle->setFixedWidth(200);
        postTime->setFixedWidth(200);
        postID->setFixedWidth(80);

        hLayout->addWidget(postTitle);
        hLayout->addWidget(postTime);
        hLayout->addWidget(postID);

        hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
        wContainer->resize(350,50);

        QListWidgetItem *infoItem = new QListWidgetItem(ui->listWidget_info);
        ui->listWidget_info->setItemWidget(infoItem, wContainer);
    }
}

void MainWindow::tabEmo()
{
    ui->listWidget_emo->clear();

    ui->listWidget_emo->setResizeMode(QListView::Adjust);
    ui->listWidget_emo->setAutoScroll(true);

    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    QWidget *wContainer = new QWidget(ui->listWidget_emo);
    QHBoxLayout *hLayout = new QHBoxLayout(wContainer);

    QLabel *postTitle = new QLabel(tr("主题"));
    QLabel *postTime = new QLabel(tr("发帖时间"));
    QLabel *postID = new QLabel(tr("发信人"));

    postTitle->setFixedWidth(200);
    postTime->setFixedWidth(200);
    postID->setFixedWidth(80);

    hLayout->addWidget(postTitle);
    hLayout->addWidget(postTime);
    hLayout->addWidget(postID);

    hLayout->setContentsMargins(5,0,0,5);
    wContainer->resize(350,50);

    QListWidgetItem *tabEmoItem = new QListWidgetItem(ui->listWidget_emo);
    ui->listWidget_emo->setItemWidget(tabEmoItem, wContainer);

    currentUser->scanIntoBoard(emotions, postvec);
    qDebug()<<"postvec.size()"<<postvec.size();
    for(unsigned int i = 0; i < postvec.size(); i++)
    {
        postvec[i].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);

        wContainer = new QWidget(ui->listWidget_emo);
        hLayout = new QHBoxLayout(wContainer);

        postTitle = new QLabel(title);
        postTime = new QLabel(pubishtime);
        postID = new QLabel(postWriter);

        postTitle->setFixedWidth(200);
        postTime->setFixedWidth(200);
        postID->setFixedWidth(80);

        hLayout->addWidget(postTitle);
        hLayout->addWidget(postTime);
        hLayout->addWidget(postID);

        hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
        wContainer->resize(350,50);

        QListWidgetItem *emoItem = new QListWidgetItem(ui->listWidget_emo);
        ui->listWidget_emo->setItemWidget(emoItem, wContainer);
    }
}

void MainWindow::tabsearch(QString searchfor, int searchtype)
{
    ui->listWidget_search->clear();

    ui->listWidget_search->setResizeMode(QListView::Adjust);
    ui->listWidget_search->setAutoScroll(true);


    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    QWidget *wContainer = new QWidget(ui->listWidget_search);
    QHBoxLayout *hLayout = new QHBoxLayout(wContainer);

    QLabel *postTitle = new QLabel(tr("主题"));
    QLabel *postTime = new QLabel(tr("发帖时间"));
    QLabel *postID = new QLabel(tr("发信人"));

    postTitle->setFixedWidth(200);
    postTime->setFixedWidth(200);
    postID->setFixedWidth(80);

    hLayout->addWidget(postTitle);
    hLayout->addWidget(postTime);
    hLayout->addWidget(postID);

    hLayout->setContentsMargins(5,0,0,5);
    wContainer->resize(350,50);

    QListWidgetItem *tabSearchItem = new QListWidgetItem(ui->listWidget_search);
    ui->listWidget_search->setItemWidget(tabSearchItem, wContainer);

    currentUser->scanIntoBoard(searchfor, searchtype, this->targetPost);
    qDebug()<<"postvec.size()"<<targetPost.size();
    for(unsigned int i = 0; i < targetPost.size(); i++)
    {
        targetPost[i].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);

        wContainer = new QWidget(ui->listWidget_emo);
        hLayout = new QHBoxLayout(wContainer);

        postTitle = new QLabel(title);
        postTime = new QLabel(pubishtime);
        postID = new QLabel(postWriter);

        postTitle->setFixedWidth(200);
        postTime->setFixedWidth(200);
        postID->setFixedWidth(80);

        hLayout->addWidget(postTitle);
        hLayout->addWidget(postTime);
        hLayout->addWidget(postID);

        hLayout->setContentsMargins(5,0,0,5);//关键代码，如果没有很可能显示不出来
        wContainer->resize(350,50);

        QListWidgetItem *searchItem = new QListWidgetItem(ui->listWidget_search);
        ui->listWidget_search->setItemWidget(searchItem, wContainer);
    }
}

void MainWindow::inThePost(std::vector<post> postvec, int index, QString postWriter, QString title,
                            QString content,  QString pubishtime,
                            std::vector<comment> postcomments,  BoardType postkind)
{
    inPostDialog * inPostDlg = new inPostDialog(postvec, index, postWriter, title, content,
                                                pubishtime, postcomments, postkind, this);
    inPostDlg->exec();
}

void MainWindow::on_listWidget_aca_clicked()
{
    unsigned int row = ui->listWidget_aca->currentRow();
    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    currentUser->scanIntoBoard(academics, postvec);
    if(row >= 1 && row <= postvec.size())
    {
        postvec[row-1].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);
        inThePost(postvec, row-1, postWriter, title, content, pubishtime, postcomments, postkind);
    }

}

void MainWindow::on_listWidget_info_clicked()
{
    unsigned int row = ui->listWidget_info->currentRow();
    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString publishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    currentUser->scanIntoBoard(information, postvec);
    if(row >= 1 && row <= postvec.size())
    {
        postvec[row-1].getpostinfo(postWriter, title, content, publishtime, postcomments, postkind);
        qDebug()<<publishtime<<"in listWidget:postkind="<<(int)postkind;
        inThePost(postvec, row-1, postWriter, title, content, publishtime, postcomments, postkind);
    }
}

void MainWindow::on_listWidget_emo_clicked()
{
    unsigned int row = ui->listWidget_emo->currentRow();
    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    currentUser->scanIntoBoard(emotions, postvec);
    if(row >= 1 && row <= postvec.size())
    {
        postvec[row-1].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);
        inThePost(postvec, row-1, postWriter, title, content, pubishtime, postcomments, postkind);
    }
}

void MainWindow::on_tabWidget_tabBarClicked()
{
    tabAca();
    tabInfo();
    tabEmo();

}

void MainWindow::on_searchconfirm_clicked()
{

    ui->listWidget_search->clear();

    std::vector<post> targetPost;
    QString searchtype = ui->searchkind->currentText();
    QString searchInfo = ui->searchInfo->text();

    if(searchInfo == "")
    {
        QMessageBox::warning(this,tr("警告"),tr("搜索内容不能为空!"),QMessageBox::Yes);
        return;
    }

    if(searchtype == "发信人")
    {
        currentUser->scanIntoBoard(searchInfo, 0, targetPost);
        if(targetPost.empty())
        {
            QMessageBox::information(this,tr("提示"),tr("对不起，无匹配项!"),QMessageBox::Yes);
            return;
        }
        tabsearch(searchInfo, 0);
    }
    else if(searchtype == "标题")
    {
        currentUser->scanIntoBoard(searchInfo, 1, targetPost);
        if(targetPost.empty())
        {
            QMessageBox::information(this,tr("提示"),tr("对不起，无匹配项!"),QMessageBox::Yes);
            return;
        }
        tabsearch(searchInfo, 1);
    }
}

void MainWindow::on_listWidget_search_clicked()
{
    unsigned int row = ui->listWidget_search->currentRow();
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    if(row >= 1 && row <= targetPost.size())
    {
        this->targetPost[row-1].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);
        inThePost(targetPost, row-1, postWriter, title, content, pubishtime, postcomments, postkind);
    }
}
