#include "editdetails.h"
#include "ui_editdetails.h"

editDetails::editDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDetails)
{
    ui->setupUi(this);
}

editDetails::~editDetails()
{
    delete ui;
}

QString selectedPicture(QString img){
    return img;
}
//Avatar Set
void editDetails::on_pushButton_clicked()
{
    selectedPicture("avatar.jpg");
    this->close();
}
//Cancel Button
void editDetails::on_pushButton_5_clicked()
{
    this->close();
}
//Avatar 1 Set
void editDetails::on_pushButton_2_clicked()
{
    selectedPicture("avatar1.jpg");
    this->close();
}
//Avatar 2 Set
void editDetails::on_pushButton_3_clicked()
{
    selectedPicture("avatar2.jpg");
    this->close();
}
//Avatar 3 Set
void editDetails::on_pushButton_4_clicked()
{
    selectedPicture("avatar3.jpg");
    this->close();
}
