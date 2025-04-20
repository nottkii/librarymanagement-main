#include "userinfo.h"
#include "ui_userinfo.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QSortFilterProxyModel>

USERINFO::USERINFO(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::USERINFO)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->tableView->setModel(model); // Set the model to the table view
    loadRegisteredInfo();
}

USERINFO::~USERINFO()
{
    delete ui;
}

void USERINFO::loadRegisteredInfo()
{
    model->clear(); // Clear the model before loading new data
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(QStringList() << "Name" << "Faculty" << "Semester" << "Roll No");

    // Open the CSV file
    QFile file("user_data.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file.");
        return;
    }

    // Read the data from the CSV file
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(",");
        if (data.size() == 4) {
            QList<QStandardItem *> rowItems;
            for (const QString &value : data) {
                rowItems.append(new QStandardItem(value));
            }
            model->appendRow(rowItems);
        }
    }
    file.close();
}

void USERINFO::on_pushButton_clicked()
{
    QString searchText = ui->lineEdit->text().trimmed();

    if (searchText.isEmpty()) {
        // If search text is empty, reload all data
        loadRegisteredInfo();
    } else {
        // Otherwise, filter the data based on the search text
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);
        proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyModel->setFilterKeyColumn(3); // Assuming Roll No is in the 4th column
        proxyModel->setFilterFixedString(searchText);
        ui->tableView->setModel(proxyModel);

        if (proxyModel->rowCount() == 0) {
            QMessageBox::information(this, "No records found", "No records matching the search criteria were found.");
            ui->tableView->setModel(model); // Restore original model
            loadRegisteredInfo(); // Reload all records
        }
    }
}
