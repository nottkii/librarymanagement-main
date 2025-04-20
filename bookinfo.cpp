#include "bookinfo.h"
#include "ui_bookinfo.h"
#include "issue.h" // Include the issue dialog to access its data loading functionality
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QSortFilterProxyModel>

BOOkinfo::BOOkinfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BOOkinfo)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->tableView->setModel(model); // Set the model to the table view
    loadIssuedBooks(); // Load issued books data initially
}

BOOkinfo::~BOOkinfo()
{
    delete ui;
}

void BOOkinfo::loadIssuedBooks()
{
    model->clear(); // Clear the model before loading new data
    model->setColumnCount(5);
    model->setHorizontalHeaderLabels(QStringList() << "Book ID" << "Book Name" << "Issued To" << "Semester" << "Date");

    // Open the CSV file
    QFile file("issued_books.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file.");
        return;
    }

    // Read the data from the CSV file
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(",");
        if (data.size() == 5) {
            QList<QStandardItem *> rowItems;
            for (const QString &value : data) {
                rowItems.append(new QStandardItem(value));
            }
            model->appendRow(rowItems);
        }
    }
    file.close();
}

void BOOkinfo::on_pushButton_clicked()
{
    QString searchText = ui->lineEdit->text().trimmed();

    if (searchText.isEmpty()) {
        // If search text is empty, reload all data
        loadIssuedBooks();
    } else {
        // Otherwise, filter the data based on the search text
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->setFilterKeyColumn(-1); // Search all columns
        proxyModel->setFilterFixedString(searchText);
        ui->tableView->setModel(proxyModel);

        if (proxyModel->rowCount() == 0) {
            QMessageBox::information(this, "No records found", "No records matching the search criteria were found.");
            ui->tableView->setModel(model); // Restore original model
            loadIssuedBooks(); // Reload all records
        }
    }
}

