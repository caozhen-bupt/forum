#ifndef DELBOARDMANAGERDIALOG_H
#define DELBOARDMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class delBoardManagerDialog;
}

class delBoardManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit delBoardManagerDialog(QWidget *parent = 0);
    ~delBoardManagerDialog();

    int index;

private slots:
    void on_confirm_clicked();

private:
    Ui::delBoardManagerDialog *ui;
};

#endif // DELBOARDMANAGERDIALOG_H
