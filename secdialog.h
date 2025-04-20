#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include"userreg.h"
#include "userinfo.h"
#include"issue.h"
#include"bookinfo.h"
#include"returnbook.h"
namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = nullptr);
    ~secDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::secDialog *ui;
    USERREG *userReg;
    USERINFO *userInfo;
    issue *Issue;
    BOOkinfo *bookinfo;
    returnbook *returnBook;
};

#endif // SECDIALOG_H
