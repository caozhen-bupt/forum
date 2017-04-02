#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "comment.h"
#include "datastructure.h"
#include "post.h"
extern int curUserIndex;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<post> targetPost;

private slots:
    void personalInfo();
    void AllTheInfo();
    void on_logout_clicked();
    void on_userInfo_clicked();
    void inThePost(std::vector<post> postvec, int index, QString postWriter, QString title,
                   QString content,  QString pubishtime,
                   std::vector<comment> postcomments,  BoardType postkind);
    void tabAca();
    void tabInfo();
    void tabEmo();
    void tabsearch(QString searchfor, int searchtype);
    void on_sendpost_clicked();
    void on_listWidget_aca_clicked();
    void on_listWidget_info_clicked();
    void on_listWidget_emo_clicked();
    void on_tabWidget_tabBarClicked();
    void on_searchconfirm_clicked();
    void on_listWidget_search_clicked();
};

#endif // MAINWINDOW_H
