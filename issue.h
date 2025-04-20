#ifndef ISSUE_H
#define ISSUE_H

#include <QDialog>

namespace Ui {
class issue;
}

class issue : public QDialog
{
    Q_OBJECT

public:
    explicit issue(QWidget *parent = nullptr);
    ~issue();

private slots:
    void on_pushButton74_clicked();

private:
    Ui::issue *ui;
};

#endif // ISSUE_H
