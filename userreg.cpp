#include "userreg.h"
#include "ui_userreg.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include<QMessageBox>
#include <QRegularExpression>

USERREG::USERREG(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::USERREG)
{
    ui->setupUi(this);
}

USERREG::~USERREG()
{
    delete ui;
}

void USERREG::on_pushButton_clicked()
{
    QString NAME = ui-> lineEdit_4_x->text();
    QString FACULTY= ui-> lineEdit_4_y ->text();
    QString SEMISTER = ui-> lineEdit_41->text();
    QString ROLLNO = ui->lineEdit_4->text();
    QFile file("user_data.csv");
     QRegularExpression regex(""); // Ensure ROLLNO starts with "PUR" followed by digits
    if (!regex.match(ROLLNO).hasMatch()) {
        QMessageBox::warning(this, "Validation Error", "Invalid ROLLNO format. ROLLNO should start with 'PUR' followed by digits.");
        return; // Exit the function without further processing
    }
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        // Write the user registration data to the file in CSV format
        stream << NAME << "," << FACULTY << "," << SEMISTER << "," << ROLLNO << "\n";

        // Close the file
        file.close();

        QMessageBox::information(this, "Registration", "User registration successful. Data saved to user_data.csv");
        ui->lineEdit_4_x->clear();
        ui->lineEdit_4_y->clear();
        ui->lineEdit_41->clear();
        ui->lineEdit_4->clear();
    } else {
        QMessageBox::warning(this, "Error", "Unable to open or create the file.");
    }
}

void USERREG::on_pushButton_2_clicked()
{
    hide();
}

