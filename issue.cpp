#include "issue.h"
#include "ui_issue.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDate>

issue::issue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::issue)
{
    ui->setupUi(this);
}

issue::~issue()
{
    delete ui;
}

void issue::on_pushButton74_clicked()
{
    // Retrieve data from line edits
    QString bookId = ui->lineEdit71->text();
    QString bookName = ui->lineEdit_72->text();
    QString issuedTo = ui->lineEdit_73->text();
    QString semester = ui->lineEdit78->text();
    QString date = ui->dateEdit->date().toString("yyyy.MM.dd");

    // Open the CSV file to check for existing book ID
    QFile checkFile("issued_books.csv");
    if (checkFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&checkFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList data = line.split(",");
            if (data.size() >= 1 && data.at(0) == bookId) {
                QMessageBox::critical(this, "Error", "Book ID already exists. Cannot issue the same book twice.");
                checkFile.close();
                return; // Exit the function
            }
        }
        checkFile.close();
    }

    // Open the CSV file for writing
    QFile file("issued_books.csv");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file for writing");
        return;
    }

    // Write data to the file
    QTextStream out(&file);
    out << bookId << "," << bookName << "," << issuedTo << "," << semester << "," << date << "\n";
    QMessageBox::information(this, "Status", "Book Issue Successful");
    file.close();

    // Clear the line edits after storing the data
    ui->lineEdit71->clear();
    ui->lineEdit_72->clear();
    ui->lineEdit_73->clear();
    ui->lineEdit78->clear();
    ui->dateEdit->setDate(QDate::currentDate()); // Set date to current date
}
