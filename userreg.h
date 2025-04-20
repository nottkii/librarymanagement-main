#ifndef USERREG_H
#define USERREG_H
#include <QDialog>


namespace Ui {
class USERREG;
}

class USERREG : public QDialog
{
    Q_OBJECT

public:
    explicit USERREG(QWidget *parent = nullptr);
    ~USERREG();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::USERREG *ui;

};

#endif // USERREG_H
