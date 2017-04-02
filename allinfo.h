#ifndef ALLINFO_H
#define ALLINFO_H
#include <QListView>
#include <QTableWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QDialog>

#include "setboardmanagerdialog.h"
#include "delboardmanagerdialog.h"

namespace Ui {
class allInfo;
}

class allInfo : public QDialog
{
    Q_OBJECT

public:
    explicit allInfo(QWidget *parent = 0);
    ~allInfo();

private slots:
    void setBM(const int &index);
    void delBM(const int &index);
    void on_info_clicked(const QModelIndex &index);
    void on_fresh_clicked();

private:
    Ui::allInfo *ui;
};

#endif // ALLINFO_H
