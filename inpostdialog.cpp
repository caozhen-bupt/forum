#include <QDebug>
#include <QTextBrowser>
#include <QMessageBox>

#include "inpostdialog.h"
#include "ui_inpostdialog.h"
#include "user.h"

extern User *currentUser;


inPostDialog::inPostDialog(std::vector<post> postvec, int index, QString postWriter,
                           QString title,  QString content, QString pubishtime,
                           std::vector<comment> postcomments, BoardType postkind, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inPostDialog)
{
    this->index = index;
    this->postvec = postvec;
    this->postkind = postkind;
    this->postWriter = postWriter;
    this->content =  content;
    this->title = title;
    this->pubishtime = pubishtime;
    this->postcomments = postcomments;

    ui->setupUi(this);

    QString boardstr;
    if(postkind == academics){
        boardstr = "学术科技";
    }
    else if(postkind == information)
    {
        boardstr = "信息社会";
    }
    else if(postkind == emotions)
    {
        boardstr = "情感天地";
    }
    else
    {
        qDebug()<<"Board Error!";
    }
    QString txt = "发信人："+postWriter+"\t"+"发信区："+boardstr+"\t"+"发信站：北邮人论坛"+"\t"+"1楼"+"\n";
    txt += "标题："+title+"           ";
    txt += pubishtime;
    txt += "\n";
    txt += "\n";
    txt += content+"\n"+"\n"+"*********************************************************************************"+"\n"+"\n";
    QString Content;
    QString Time;
    QString CommentWriter;

    for(unsigned int i = 0; i < postcomments.size(); i++)
    {
        postcomments[i].getComment(Content, Time, CommentWriter);
        txt += "回复人："+CommentWriter+"            "+Time+"              "+QString::number(i+2)+"楼"+"\n"+Content+"\n"+"\n";
        txt += "*********************************************************************************";
        txt += "\n";
        txt += "\n";

    }
    qDebug()<<txt;
    this->ui->postInfo->clear();
    ui->postInfo->insertPlainText(txt);

}

inPostDialog::~inPostDialog()
{
    delete ui;
}

void inPostDialog::on_confirm_clicked()
{
    QString CommentInfo = ui->myComment->toPlainText();
    if(CommentInfo == "" || CommentInfo.contains('+') || CommentInfo.contains('*')
            || CommentInfo.contains('#') || CommentInfo.contains("comment:") || CommentInfo.contains("\n"))
    {
        QMessageBox::warning(this,tr("警告"),tr("非法输入!"),QMessageBox::Yes);
        ui->myComment->clear();
        return;
    }

    QString nowTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    int Flag;
    QString name;
    QString IDs;
    QString pwds;
    currentUser->getUser(Flag, name, IDs, pwds);
    comment theComment(CommentInfo, nowTime, IDs);
    postcomments.push_back(theComment);
    currentUser->makecomment(this->postvec, theComment, this->index);
    QMessageBox::information(this,tr("提示"),tr("评论成功!"),QMessageBox::Yes);
    this->ui->myComment->clear();

    QString boardstr;
    if(postkind == academics){
        boardstr = "学术科技";
    }
    else if(postkind == information)
    {
        boardstr = "信息社会";
    }
    else if(postkind == emotions)
    {
        boardstr = "情感天地";
    }
    else
    {
        qDebug()<<"Board Error!";
    }
    QString txt = "发信人："+postWriter+"\t"+"发信区："+boardstr+"\t"+"发信站：北邮人论坛"+"\t"+"1楼"+"\n";
    txt += "标题："+title+"           ";
    txt += pubishtime;
    txt += "\n";
    txt += "\n";
    txt += content+"\n"+"\n"+"*********************************************************************************"+"\n"+"\n";
    QString Content;
    QString Time;
    QString CommentWriter;

    for(unsigned int i = 0; i < postcomments.size(); i++)
    {
        postcomments[i].getComment(Content, Time, CommentWriter);
        txt += "回复人："+CommentWriter+"            "+Time+"              "+QString::number(i+2)+"楼"+"\n"+Content+"\n"+"\n";
        txt += "*********************************************************************************";
        txt += "\n";
        txt += "\n";

    }
    qDebug()<<txt;
    this->ui->postInfo->clear();
    ui->postInfo->insertPlainText(txt);
}

void inPostDialog::on_deletePost_clicked()
{
    int Flag;
    QString name;
    QString IDs;
    QString pwds;
    BoardType boardkind;
    currentUser->getUser(Flag, name, IDs, pwds);
    qDebug()<<"Flag:"<<Flag;
    if(Flag == 2)
    {
        currentUser->getboard(boardkind);
        qDebug()<<"boardkind:"<<(int)boardkind<<"postkind:"<<this->postkind;
        if(boardkind == this->postkind)
        {
            currentUser->delpost(this->postkind, this->postvec, this->index);
            QMessageBox::information(this,tr("提示"),tr("删帖成功!"),QMessageBox::Yes);
            this->close();

        }
        else
        {
            QMessageBox::warning(this,tr("提示"),tr("您不是该版版主!"),QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("您不是版主，没有删帖权限!"),QMessageBox::Yes);
    }
}
void inPostDialog::on_up_clicked()
{
    int Flag;
    QString name;
    QString IDs;
    QString pwds;
    BoardType boardkind;
    currentUser->getUser(Flag, name, IDs, pwds);

    if(Flag == 2)
    {
        currentUser->getboard(boardkind);
        qDebug()<<"boardkind:"<<(int)boardkind<<"postkind:"<<this->postkind;
        if(boardkind == this->postkind)
        {
            currentUser->up(this->postkind, this->postvec, this->index);
            QMessageBox::information(this,tr("提示"),tr("置顶成功!"),QMessageBox::Yes);
            this->close();
        }
        else
        {
            QMessageBox::warning(this,tr("提示"),tr("您不是该版版主!"),QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("您不是版主，没有置顶权限!"),QMessageBox::Yes);
    }
}
