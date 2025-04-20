#include "secdialog.h"
#include "ui_secdialog.h"
#include "userreg.h"
#include<QMessageBox>

secDialog::secDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secDialog)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_pushButton_clicked()
{
    userInfo = new USERINFO(this);
    userInfo->show();
}


void secDialog::on_pushButton_2_clicked()
{
    bookinfo = new BOOkinfo(this);
    bookinfo->show();
}



void secDialog::on_pushButton_3_clicked()
{
    Issue = new issue(this);
    Issue->show();
}


void secDialog::on_pushButton_4_clicked()
{
    userReg = new USERREG(this);
    userReg->show();
}


void secDialog::on_pushButton_5_clicked()
{
    returnBook = new returnbook(this);
    returnBook->show();
}

