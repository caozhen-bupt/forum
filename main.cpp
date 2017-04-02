/* 曹桢
 * 北京邮电大学 2014级计科2班（2014211302） 学号：2014211182
 * 工程描述：一个论坛，用面向对象的方法实现基本功能（第二版本）
 * 完成于2016-09-11 20：04
*/


#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <QMessageBox>

#include "mainwindow.h"
#include "user.h"

QTextCodec *codec = QTextCodec::codecForName("UTF-8");
std::vector<User *> uservec;
User *currentUser = nullptr;
int curUserIndex = -1;

User::User(){}

User::User(const int &Flag, const QString &names, const QString &IDs, const QString &pwds):
    flag(Flag), userName(names), id(IDs), password(pwds){qDebug()<<"user的构造函数";}

User::~User()
{}

void User::getboard(BoardType &BM){}

bool User::login(const QString &inputname, const QString &inputpassword)
{
    int Flag;
    QString name;
    QString pwds;
    QString IDs;

    for(unsigned int i = 0; i < uservec.size(); i++){
        uservec[i]->getUser(Flag, name, IDs, pwds);
        if(inputname == name &&
            inputpassword == pwds){
            curUserIndex = i;
            currentUser = uservec[i];
            return true;
        }
    }
    return false;
}

bool User::logout()
{
    curUserIndex = -1;
    currentUser = nullptr;
}

void User::checkUserInfo(int i, int &flag, QString &nametxt, QString &IDstxt, BoardType &BM)
{
    QString pwds;
    uservec[i]->getUser(flag, nametxt, IDstxt, pwds);
    if(flag == 2)
    {
        uservec[i]->getboard(BM);
    }
    else
    {
        BM = (BoardType)3;
    }
}


void User::scanIntoBoard(const BoardType &BT, std::vector<post> &postvec)
{
    try
    {
        QString str;
        postvec.clear();
        if(BT == academics)
        {
            str = "academics.txt";
        }
        else if(BT == information)
        {
            str = "information.txt";
        }
        else if(BT == emotions)
        {
            str = "emotions.txt";
        }
        else
        {
            qDebug()<<"boarderror";
            throw "No such board";
        }

        QFile fl(str);
        QTextStream in(&fl);
        post thePost;
        if(!fl.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"cannot open the file!"<<fl.exists();
            throw QFileDevice::FileError();
        }
        while( !in.atEnd()){
            if(in.readLine() == "***"){
                in>>thePost;
                thePost.setpostkind(BT);
                postvec.push_back(thePost);
            }
        }
        fl.close();
    }
    catch(QString e)
    {
        QMessageBox::information(nullptr, "Error", e, QMessageBox::Yes);
    }

    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error", "Unknown Error", QMessageBox::Yes);
    }
}

void User::sendpost(post thePost)
{
    std::vector<post> postvec;
    QString str;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

    try{
        thePost.getpostinfo(postWriter, title, content,
                             pubishtime, postcomments, postkind);

        currentUser->scanIntoBoard(postkind, postvec);
        postvec.push_back(thePost);


        if(postkind == academics)
        {
            str = "academics.txt";
        }
        else if(postkind == information)
        {
            str = "information.txt";
        }
        else if(postkind == emotions)
        {
            str = "emotions.txt";
        }
        else{
            qDebug()<<"boarderror";
            throw "No such board";
        }

        QFile file(str);
        QTextStream out(&file);

        if(!file.open(QFile::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            qDebug()<<"in sendpost: Can't open the file!"<<endl;
            throw QFileDevice::FileError();
        }

        for(int i = 0; i < postvec.size(); i++)
        {
            out<<postvec[i];
        }
        out.flush();
        file.close();
    }
    catch(QString e)
    {
        QMessageBox::information(nullptr, "Error", e, QMessageBox::Yes);
    }

    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }
}

void User::scanIntoBoard(QString searchfor, int searchtype, std::vector<post> &targetPost)
{
    std::vector<post> postList;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;
    std::vector<std::vector<post> > postvec;
    targetPost.clear();
    for(int i = 0; i < boardNum; i++)
    {
        scanIntoBoard((BoardType)i, postList);
        postvec.push_back(postList);

    }
    qDebug()<<"boardnum"<<postvec.size();
    if(searchtype == 0)
    {
        for(int i = 0; i < postvec.size(); i++)
        {
            for(int j = 0; j < postvec[i].size(); j++)
            {
                postvec[i][j].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);
                qDebug()<<"postWriter"<<postWriter;
                if(postWriter == searchfor)
                {
                    targetPost.push_back(postvec[i][j]);
                    qDebug()<<"postWriter:"<<postWriter<<"targetPost.size()"<<targetPost.size()<<"i,j"<<i<<j;

                }
            }
        }
    }
    else if(searchtype == 1)
    {
        for(int i = 0; i < postvec.size(); i++)
        {
            for(int j = 0; j < postvec[i].size(); j++)
            {
                postvec[i][j].getpostinfo(postWriter, title, content, pubishtime, postcomments, postkind);
                if(title == searchfor)
                {
                    targetPost.push_back(postvec[i][j]);
                    qDebug()<<"searchtype=1,title:"<<title<<"id"<<postWriter<<"targetPost.size()"<<targetPost.size();
                }
            }
        }
    }
}

void User::makecomment(std::vector<post> &postvec, comment theComment, int postvecIndex)
{
    QString str;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;


    try{
        postvec[postvecIndex].getpostinfo(postWriter, title, content,
                             pubishtime, postcomments, postkind);

        postvec[postvecIndex].postcomments.push_back(theComment);

        if(postkind == academics)
        {
            str = "academics.txt";
        }
        else if(postkind == information)
        {
            str = "information.txt";
        }
        else if(postkind == emotions)
        {
            str = "emotions.txt";
        }
        else{
            qDebug()<<"boarderror";
            throw "no such board!";
        }
        QFile fl(str);
        QTextStream out(&fl);
        if (!fl.open(QFile::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            qDebug()<<"in makeComment: Can't open the file!"<<endl;
            throw QFileDevice::FileError();
        }
        for(int i = 0; i < postvec.size(); i++)
        {
            out<<postvec[i];
        }
        out.flush();
        fl.close();
    }
    catch(QString e)
    {
        QMessageBox::information(nullptr, "Error", e, QMessageBox::Yes);
    }

    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }
}

void User::getUser(int &Flag, QString &name, QString &IDs, QString &pwds)
{
    Flag = flag;
    name = userName;
    IDs = id;
    pwds = password;
}

commonUser::commonUser()
{}

commonUser::commonUser(const int &Flag, const QString &names, const QString &IDs, const QString &pwds):
    User(Flag, names, IDs, pwds){qDebug()<<"commonuser的构造函数";}


commonUser::~commonUser()
{

}

void User::delpost(BoardType BT, std::vector<post> &postvec, int postvecIndex){}
void User::up(BoardType BT, std::vector<post> &postvec, int postvecIndex){}

void commonUser::addBoardManager(int uservecIndex, BoardType BM){}
void commonUser::delBoardManager(int uservecIndex){}

administor::administor(const int &Flag, const QString &names, const QString &IDs, const QString &pwds):
    User(Flag, names, IDs, pwds){qDebug()<<"admin的构造函数";}


administor::~administor()
{

}

void administor::addBoardManager(int uservecIndex, BoardType BM)
{
    int Flag;
    QString name;
    QString pwds;
    QString IDs;

    uservec[uservecIndex]->getUser(Flag, name, IDs, pwds);
    User *abstrUser = new boardManager(2, name, IDs, pwds, BM);
    delete uservec[uservecIndex];
    uservec[uservecIndex] = abstrUser;

    QFile file("namepwd.txt");
    QTextStream out(&file);
    qDebug() <<"in addBoardManager():"<<file.exists();
    BoardType whichboard;
    try{
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            qDebug()<<"in addBoardManager():Can't open the file!"<<file.error()<<file.errorString()<<endl;
            throw QFileDevice::FileError();
        }

        for(int i = 0; i < uservec.size(); i++)
        {
            out<<uservec[i];
        }
        out.flush();
        file.close();
    }

    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }

}

void administor::delBoardManager(int uservecIndex)
{
    int Flag;
    QString name;
    QString pwds;
    QString IDs;
    uservec[uservecIndex]->getUser(Flag, name, IDs, pwds);
    User *abstrUser = new commonUser(1, name, IDs, pwds);
    delete uservec[uservecIndex];
    uservec[uservecIndex] = abstrUser;


    QFile file("namepwd.txt");
    QTextStream out(&file);

    BoardType whichboard;

    try{
        if(!file.open(QFile::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            qDebug()<<"in delBoardManager: Can't open the file!"<<endl;
            throw QFileDevice::FileError();
        }

        for(int i = 0; i < uservec.size(); i++)
        {
            out<<uservec[i];
        }
        out.flush();
        file.close();
    }
    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }
}


//boardManager::boardManager()
//{}

boardManager::boardManager(const int &Flag, const QString &names, const QString &IDs, const QString &pwds, const BoardType &BMBoard):
    commonUser(Flag, names, IDs, pwds), manageWhichBoard(BMBoard){qDebug()<<"boardmanager的构造函数";}


boardManager::~boardManager()
{}

void boardManager::delpost(BoardType BT, std::vector<post> &postvec, int postvecIndex)
{


    try{
        QString str;
        postvec.erase(postvec.begin()+postvecIndex);
        if(BT == academics)
        {
            str = "academics.txt";
        }
        else if(BT == information)
        {
            str = "information.txt";
        }
        else if(BT == emotions)
        {
            str = "emotions.txt";
        }
        else{
            qDebug()<<"boarderror";
            throw "no such board!";
        }

        QFile file(str);
        QTextStream out(&file);
        if (!file.open(QFile::WriteOnly | QIODevice::Truncate)) {
            qDebug()<<"Can't open the file!"<<endl;
            throw QFileDevice::FileError();
        }
        for(int i = 0; i < postvec.size(); i++)
        {
            out<<postvec[i];
        }
        out.flush();
        file.close();
    }
    catch(QString e)
    {
        QMessageBox::information(nullptr, "Error", e, QMessageBox::Yes);
    }

    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }
}

void boardManager::getboard(BoardType &BM)
{
    BM = manageWhichBoard;
}

void boardManager::up(BoardType BT, std::vector<post> &postvec, int postvecIndex)
{
    QString str;
    post temp = postvec[postvecIndex];   
    try
    {
        postvec.erase(postvec.begin()+postvecIndex);
        postvec.insert(postvec.begin(), temp);

        if(BT == academics)
        {
            str = "academics.txt";
        }
        else if(BT == information)
        {
            str = "information.txt";
        }
        else if(BT == emotions)
        {
            str = "emotions.txt";
        }
        else{
            qDebug()<<"boarderror";
            throw "no such board";
        }

        QFile file(str);
        QTextStream out(&file);
        if (!file.open(QFile::WriteOnly | QIODevice::Truncate)) {
            qDebug()<<"Can't open the file!"<<endl;
            throw QFileDevice::FileError();
        }
        for(int i = 0; i < postvec.size(); i++)
        {
            out<<postvec[i];
        }
        out.flush();
        file.close();
    }
    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }
}

void initUserVec()
{
    try{
        QFile namepwd("namepwd.txt");
        if(!namepwd.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"Can't open the file!"<<endl;
            exit(1);
        }

        QTextStream in(&namepwd);
        User * abstrUser = new commonUser;

        while( !in.atEnd()){
            in>>abstrUser;
            uservec.push_back(abstrUser);

            int flag;
            QString name;
            QString pwd;
            QString id;
            abstrUser->getUser(flag, name, id, pwd);
            qDebug()<<flag<<name<<id<<pwd;

            qDebug()<< "user vecsize"<<uservec.size();
        }
        namepwd.close();
    }
    catch(QFileDevice::FileError fileErr)
    {
        QMessageBox::information(nullptr, "Error", "File Error:"+QString::number((int)fileErr)+"cannot open the file", QMessageBox::Yes);
    }
    catch(...)
    {
        QMessageBox::information(nullptr, "Error:", "Unknown Error", QMessageBox::Yes);
    }
}

QTextStream& operator >>(QTextStream &in, User *&abstrUser)
{
    QString line = in.readLine();
    QStringList nameIDpassword = line.split(" ");

    if(nameIDpassword[0] == "0"){
        abstrUser = new administor(nameIDpassword[0].toInt(), nameIDpassword[1],
                nameIDpassword[2], nameIDpassword[3]);
    }
    else if(nameIDpassword[0] == "2"){
        abstrUser = new boardManager(nameIDpassword[0].toInt(), nameIDpassword[1],
                nameIDpassword[2], nameIDpassword[3], (BoardType)nameIDpassword[4].toInt());
    }
    else if(nameIDpassword[0] == "1"){
        abstrUser = new commonUser(nameIDpassword[0].toInt(), nameIDpassword[1],
                nameIDpassword[2], nameIDpassword[3]);
    }
    int flag;
    QString name;
    QString pwd;
    QString id;
    abstrUser->getUser(flag, name, id, pwd);

    qDebug()<< line<<nameIDpassword[0]<<nameIDpassword[0].toInt();
    qDebug()<<flag<<name<<id<<pwd;
    return in;
}

QTextStream& operator <<(QTextStream &out, User *&C)
{
    int Flag;
    QString name;
    QString pwds;
    QString IDs;
    BoardType whichboard;

    C->getUser(Flag, name, IDs, pwds);
    if(Flag == 0 || Flag == 1)
    {
        out<<Flag<<" "<<name<<" "<<IDs<<" "<<pwds<<endl;
        qDebug()<<Flag<<" "<<name<<" "<<IDs<<" "<<pwds;
    }
    else if(Flag == 2)
    {
        C->getboard(whichboard);
        out<<Flag<<" "<<name<<" "<<IDs<<" "<<pwds<<" "<<(int)whichboard<<endl;
        qDebug()<<Flag<<" "<<name<<" "<<IDs<<" "<<pwds<<" "<<(int)whichboard;
    }
    return out;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/ICO.png"));
    initUserVec();

    MainWindow w;
    w.setWindowTitle("北邮人论坛");
    loginDialog login;
    login.show();
    if(login.exec() == loginDialog::Accepted)
    {
        login.close();
        qDebug()<<"after login.close";
        w.show();
    }

    return a.exec();
}

