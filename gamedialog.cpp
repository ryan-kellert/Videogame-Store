#include "gamedialog.h"
#include "ui_gamedialog.h"

gameDialog::gameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameDialog)
{
    ui->setupUi(this);
}

gameDialog::~gameDialog()
{
    delete ui;
}

//Set Game Title
void gameDialog::setTitle(QString title, QString Developer){
   QFont t( "Arial", 20, QFont::Bold);
   QFont d( "Arial", 16);
   ui->label->setFont(t);
   ui->label->setText(title);
   QDialog::setWindowTitle(title);

   ui->label_4->setFont(d);
   ui->label_4->setText(Developer);
}
//Set Game Description
void gameDialog::setDescription(QString Description){
   ui->textEdit->setText(Description);
}
//Set Cover Art
void gameDialog::setCoverArt(QString coverArt){
    QPixmap pixm (":/Assets/Activities/" + coverArt);
    ui->label_3->setPixmap(pixm.scaled(230,100));
}
//Cancel Button
void gameDialog::on_pushButton_clicked()
{
    this->close();
}
