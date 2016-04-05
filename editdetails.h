#ifndef EDITDETAILS_H
#define EDITDETAILS_H

#include <QDialog>

namespace Ui {
class editDetails;
}

class editDetails : public QDialog
{
    Q_OBJECT

public:
    explicit editDetails(QWidget *parent = 0);
    ~editDetails();

signals:
    QString selectedPicture(QString img);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::editDetails *ui;
};

#endif // EDITDETAILS_H
