#ifndef SETBOARDMANAGERDIALOG_H
#define SETBOARDMANAGERDIALOG_H

#include <QDialog>

#include "datastructure.h"
#include "user.h"

namespace Ui {
class setBoardManagerDialog;
}

class setBoardManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setBoardManagerDialog(QWidget *parent = 0);
    ~setBoardManagerDialog();

    int index;

private:
    Ui::setBoardManagerDialog *ui;

private slots:
    void on_confirm_clicked();
};

#endif // SETBOARDMANAGERDIALOG_H
