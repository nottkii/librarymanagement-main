#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class USERINFO;
}

class USERINFO : public QDialog
{
    Q_OBJECT

public:
    explicit USERINFO(QWidget *parent = nullptr);
    ~USERINFO();

private slots:
    void loadRegisteredInfo();
    void on_pushButton_clicked();

private:
    Ui::USERINFO *ui;
    QStandardItemModel *model; // Add a model to hold the data
};

#endif // USERINFO_H
