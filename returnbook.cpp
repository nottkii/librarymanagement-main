#include "returnbook.h"
#include "ui_returnbook.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

returnbook::returnbook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::returnbook)
{
    ui->setupUi(this);
}

returnbook::~returnbook()
{
    delete ui;
}

void returnbook::on_pushButton_clicked()
{
    QString bookId = ui->lineEditBookId->text().trimmed();
    QString rollNo =  ui-> lineEdit_4_y ->text();

    // Open the CSV file containing the issued books
    QFile file("issued_books.csv");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file for reading and writing");
        return;
    }

    // Read the file line by line, copying lines that do not match the search criteria
    QStringList lines;
    QTextStream in(&file);
    bool found = false; // Initialize found flag
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(",");
        if (data.size() >= 3 && data.at(0) == bookId && data.at(2) == rollNo) {
            // Matching row found, prompt the user for confirmation
            int ret = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to return this book?", QMessageBox::Yes | QMessageBox::No);
            if (ret == QMessageBox::Yes) {
                // If confirmed, set found flag and continue to next line
                found = true;
                continue;
            }
        }
        lines.append(line); // Add line to the list
    }

    file.seek(0);
    file.resize(0);

    // Write the filtered lines back to the file
    QTextStream out(&file);
    for (const QString& line : lines) {
        out << line << "\n";
    }

    file.close();

    // Display success message if a book was returned
    if (found) {
        QMessageBox::information(this, "Success", "Book returned successfully.");
    } else {
        QMessageBox::information(this, "No Book Found", "No book found matching the provided information.");
    }

    // Clear input fields
    ui->lineEditBookId->clear();
    ui->lineEdit_4_y->clear();
}
