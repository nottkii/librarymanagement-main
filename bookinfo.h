#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class BOOkinfo;
}

class BOOkinfo : public QDialog
{
    Q_OBJECT

public:
    explicit BOOkinfo(QWidget *parent = nullptr);
    ~BOOkinfo();
private slots:
    void loadIssuedBooks();
    void on_pushButton_clicked();

private:
    Ui::BOOkinfo *ui;
     QStandardItemModel *model;
};

#endif // BOOKINFO_H
