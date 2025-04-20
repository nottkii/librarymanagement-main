#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username=="t"&& password=="t"){
        QMessageBox::information(this,"LOGIN","ADMIN LOGIN SUCCESS");
        hide();
        SecDialog = new secDialog(this);
        SecDialog ->show();
    }
    else{
        QMessageBox::warning(this,"LOGIN","Incorrect ID/Pass");
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"ADMIN","please enter ADMIN credientials");
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"USER","please enter USER credientials");
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file("A:\\qtprojects\\app1\\Team 71.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open file: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString teamInfo = in.readAll();
    file.close();

    // Display team information in a QMessageBox
    QMessageBox::information(this, "hassan and taqi ", teamInfo);
}
