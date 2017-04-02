#ifndef USER_H
#define USER_H
#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>
#include <QFile>
#include <QDialog>

#include "logindialog.h"
#include "post.h"


class User
{
public:
    User();
    User(const int &flag, const QString &names, const QString &IDs, const QString &pwds);
    virtual ~User();
    virtual void getboard(BoardType &BM);
    virtual void addBoardManager(int uservecIndex, BoardType BM) = 0;
    virtual void delBoardManager(int uservecIndex) = 0;
    virtual void delpost(BoardType BT, std::vector<post> &postvec, int postvecIndex);
    virtual void up(BoardType BT, std::vector<post> &postvec, int postvecIndex);
    void checkUserInfo(int i, int &flag, QString &nametxt, QString &IDstxt, BoardType &BM);
    void getUser(int &Flag, QString &name, QString &IDs, QString &pwds);
    void setUser(int &Flag, QString &name, QString &IDs, QString &pwds);
    void scanIntoBoard(const BoardType &BT, std::vector<post> &postvec);
    void scanIntoBoard(QString searchfor, int searchtype, std::vector<post> &targetPost);
    bool logout();
    bool login(const QString &inputname, const QString &inputpassword);
    void sendpost(post thePost);
    void makecomment(std::vector<post> &postvec, comment theComment, int postvecIndex);


protected:
    int flag;//0:admin,1:common,2:BM
    QString userName;
    QString id;
    QString password;

friend void initUserVec();
friend QTextStream& operator >>(QTextStream &input, User *&C);
friend QTextStream& operator <<(QTextStream &output, User *&C);
};


class commonUser: public User
{
public:
    commonUser();
    commonUser(const int &flag, const QString &names, const QString &IDs, const QString &pwds);
    ~commonUser();
    virtual void addBoardManager(int uservecIndex, BoardType BM);
    virtual void delBoardManager(int uservecIndex);


};



class administor: public User
{
public:
    //administor();
    administor(const int &flag, const QString &names, const QString &IDs, const QString &pwds);
    ~administor();
    void addBoardManager(int uservecIndex, BoardType BM);
    void delBoardManager(int uservecIndex);

};




class boardManager: public commonUser
{
public:
    //boardManager();
    boardManager(const int &flag, const QString &names, const QString &IDs, const QString &pwds, const BoardType &BMBoard);
    ~boardManager();
    virtual void delpost(BoardType BT, std::vector<post> &postvec, int postvecIndex) override;
    virtual void getboard(BoardType &BT) override;
    virtual void up(BoardType BT, std::vector<post> &postvec, int postvecIndex) override;
    void getUser(int &Flag, QString &name, QString &IDs, QString &pwds, BoardType &BT);
    void setUser(int &Flag, QString &name, QString &IDs, QString &pwds, BoardType &BT);
private:
    BoardType manageWhichBoard;
};



#endif // USER_H
