#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QDialog>

namespace Ui {
class returnbook;
}

class returnbook : public QDialog
{
    Q_OBJECT

public:
    explicit returnbook(QWidget *parent = nullptr);
    ~returnbook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::returnbook *ui;
};

#endif // RETURNBOOK_H
