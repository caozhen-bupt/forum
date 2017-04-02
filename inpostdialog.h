#ifndef INPOSTDIALOG_H
#define INPOSTDIALOG_H

#include <QDialog>

#include "post.h"
#include "comment.h"
#include "datastructure.h"

namespace Ui {
class inPostDialog;
}

class inPostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inPostDialog(std::vector<post> postvec, int index, QString postWriter,
                          QString title,  QString content, QString pubishtime,
                          std::vector<comment> postcomments, BoardType postkind, QWidget *parent);
    ~inPostDialog();
    int index;
    std::vector<post> postvec;
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    std::vector<comment> postcomments;
    BoardType postkind;

private slots:
    void on_confirm_clicked();
    void on_up_clicked();
    void on_deletePost_clicked();

private:
    Ui::inPostDialog *ui;
};

#endif // INPOSTDIALOG_H
