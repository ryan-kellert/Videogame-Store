#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>

namespace Ui {
class gameDialog;
}

class gameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gameDialog(QWidget *parent = 0);
    ~gameDialog();

public slots:
    void setCoverArt(QString coverArt);
    void setTitle(QString title, QString Developer);
    void setDescription(QString description);

private slots:
    void on_pushButton_clicked();

private:
    Ui::gameDialog *ui;
};

#endif // GAMEDIALOG_H
