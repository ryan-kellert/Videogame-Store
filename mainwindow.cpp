#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include "QPainter"
#include "iostream"
#include <QTextStream>
#include "QDebug"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gameEdit = new gameDialog;
    connect(this,SIGNAL(setTitle(QString,QString)),gameEdit,SLOT(setTitle(QString , QString )));
    connect(this,SIGNAL(setDescription(QString)),gameEdit,SLOT(setDescription(QString)));
    connect(this,SIGNAL(setCoverArt(QString)),gameEdit,SLOT(setCoverArt(QString)));
    ui->setupUi(this);
    //Initialize Values
    ownedRow = 0;
    ownedCol = 0;
    userDollars = 0.00;
    ui->labelDollars->setText("$ " +  QString::number(userDollars));
    ui->tabWidget->setCurrentIndex(0);

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);

    QLabel *Error = new QLabel;
    Error->setText("Currently don't own any games!");

    //Used to Disable Cancel Commands
    myFunction.hideElement(ui->errGame1);
    myFunction.hideElement(ui->errGame2);
    myFunction.hideElement(ui->errGame3);
    myFunction.hideElement(ui->errGame4);
    myFunction.hideElement(ui->errGame5);
    myFunction.hideElement(ui->errGame6);
    myFunction.hideElement(ui->pushButton_3);
    myFunction.hideElement(ui->pushButton_4);
    myFunction.hideElement(ui->pushButton_7);
    myFunction.hideElement(ui->pushButton_9);
    myFunction.hideElement(ui->pushButton_11);
    myFunction.hideElement(ui->pushButton_13);
    myFunction.hideElement(ui->pushButton_16);
    myFunction.hideElement(ui->pushButton_19);
    myFunction.hideElement(ui->pushButton_20);
    myFunction.hideElement(ui->pushButton_21);
    myFunction.hideElement(ui->pushButton_22);
    myFunction.hideElement(ui->pushButton_23);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Darts - Buy
void MainWindow::on_pushButton_clicked()
{
    if ( myFunction.tryPurchase(ui->pushButton,29.99,ui->pushButton_3,ui->errGame1, &userDollars)) {
         myFunction.addPurchases(ui->tableWidget,ownedRow,ownedCol,"Darts","game1.jpg",ui->label_7);
         myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
    }
}

//Darts - Cancel
void MainWindow::on_pushButton_3_clicked()
{
     myFunction.cancelBtn(ui->pushButton_3, ui->pushButton, ui->errGame1,"$29.99");
}

//Tennis - Buy
void MainWindow::on_pushButton_2_clicked()
{
     if ( myFunction.tryPurchase(ui->pushButton_2,39.99,ui->pushButton_4,ui->errGame2,&userDollars)){
           myFunction.addPurchases(ui->tableWidget,ownedRow,ownedCol,"Tennis","game2.jpg",ui->label_7);
           myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
     }
}

//Tennis - Cancel
void MainWindow::on_pushButton_4_clicked()
{
      myFunction.cancelBtn(ui->pushButton_4, ui->pushButton_2, ui->errGame2,"$39.99");
}

//Roulette - Cancel
void MainWindow::on_pushButton_7_clicked()
{
     myFunction.cancelBtn(ui->pushButton_7, ui->pushButton_8, ui->errGame3,"$29.99");
}

//Roulette - Buy
void MainWindow::on_pushButton_8_clicked()
{
    if ( myFunction.tryPurchase(ui->pushButton_8,29.99,ui->pushButton_7,ui->errGame3, &userDollars)) {
         myFunction.addPurchases(ui->tableWidget,ownedRow,ownedCol,"Roulette","game3.jpg",ui->label_7);
         myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
    }
}
//Billiards - Buy
void MainWindow::on_pushButton_6_clicked()
{
    if ( myFunction.tryPurchase(ui->pushButton_6,19.99,ui->pushButton_9,ui->errGame4, &userDollars)){
         myFunction.addPurchases(ui->tableWidget,ownedRow,ownedCol,"Billiards","game4.jpg",ui->label_7);
         myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
    }
}
//Billiards - Cancel
void MainWindow::on_pushButton_9_clicked()
{
     myFunction.cancelBtn(ui->pushButton_9, ui->pushButton_6, ui->errGame4,"$19.99");
}
//Dominoes - Buy
void MainWindow::on_pushButton_10_clicked()
{
    if ( myFunction.tryPurchase(ui->pushButton_10,19.99,ui->pushButton_11,ui->errGame5, &userDollars)) {
         myFunction.addPurchases(ui->tableWidget,ownedRow,ownedCol,"Dominoes","game5.jpg",ui->label_7);
         myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
    }
}
//Dominoes - Cancel
void MainWindow::on_pushButton_11_clicked()
{
     myFunction.cancelBtn(ui->pushButton_11, ui->pushButton_10, ui->errGame5,"$9.99");
}
//Blackjack - Buy
void MainWindow::on_pushButton_12_clicked()
{
    if ( myFunction.tryPurchase(ui->pushButton_12,9.99,ui->pushButton_13,ui->errGame6, &userDollars)) {
         myFunction.addPurchases(ui->tableWidget,ownedRow,ownedCol,"Blackjack","game6.jpg",ui->label_7);
         myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
    }

}
//Blackjack - Cancel
void MainWindow::on_pushButton_13_clicked()
{
     myFunction.cancelBtn(ui->pushButton_13, ui->pushButton_12, ui->errGame6,"$49.99");
}
//Add Funds link
void MainWindow::on_pushButton_17_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
}

//Add $5
void MainWindow::on_pushButton_18_clicked()
{
     myFunction.addCurrency(ui->pushButton_18, ui->pushButton_19, 5, &userDollars);
    myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
}

//Add $100
void MainWindow::on_add100_clicked()
{
     myFunction.addCurrency(ui->add100, ui->pushButton_23, 100, &userDollars);
    myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
}
//Add $50
void MainWindow::on_add50_clicked()
{
     myFunction.addCurrency(ui->add50, ui->pushButton_22, 50, &userDollars);
    myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
}
//Add $25
void MainWindow::on_add25_clicked()
{
     myFunction.addCurrency(ui->add25, ui->pushButton_21, 25, &userDollars);
    myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
}
//Add $10
void MainWindow::on_add10_clicked()
{
     myFunction.addCurrency(ui->add10, ui->pushButton_20, 10, &userDollars);
    myFunction.updateBalance(ui->labelDollars,ui->libBalance,ui->tabBalance, userDollars);
}

//Test Dialog
void MainWindow::on_pushButton_5_clicked()
{
    QDialog* edit = new editDetails;

    connect(edit,SIGNAL(selectedPicture(QString)),this,SLOT(setProfile(QString)));

    edit->exec();
}

//Grab the Avatar Name
void MainWindow::setProfile(QString string){
    ui->pushButton_14->setIcon(QIcon(":/Assets/Icons/"+string));
    ui->pushButton_30->setIcon(QIcon(":/Assets/Icons/"+string));
    ui->pushButton_32->setIcon(QIcon(":/Assets/Icons/"+string));
}

//Click Profile Picture
void MainWindow::on_pushButton_14_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

//Edit Details Button
void MainWindow::on_pushButton_15_clicked()
{
    if(ui->pushButton_15->text() == "Edit") {
         myFunction.showElement(ui->pushButton_16);
        ui->lineEdit->setReadOnly(false);
        ui->lineEdit_2->setReadOnly(false);
        ui->lineEdit_3->setReadOnly(false);
        ui->lineEdit_4->setReadOnly(false);
        ui->lineEdit_5->setReadOnly(false);
        ui->pushButton_15->setText("Save");
        oldValues[0] = ui->lineEdit->text();
        oldValues[1] = ui->lineEdit_2->text();
        oldValues[2] = ui->lineEdit_3->text();
        oldValues[3] = ui->lineEdit_4->text();
        oldValues[4] = ui->lineEdit_5->text();

    }
    else if (ui->pushButton_15->text() =="Save"){
         myFunction.hideElement(ui->pushButton_16);
        ui->lineEdit->setReadOnly(true);
        ui->lineEdit_2->setReadOnly(true);
        ui->lineEdit_3->setReadOnly(true);
        ui->lineEdit_4->setReadOnly(true);
        ui->lineEdit_5->setReadOnly(true);
        ui->pushButton_15->setText("Edit");
    }

}

//Cancel Edit Details
void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit->setText(oldValues[0]);
    ui->lineEdit_2->setText(oldValues[1]);
    ui->lineEdit_3->setText(oldValues[2]);
    ui->lineEdit_4->setText(oldValues[3]);
    ui->lineEdit_5->setText(oldValues[4]);


    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->pushButton_15->setText("Edit");
     myFunction.hideElement(ui->pushButton_16);
}

//Cancel 10
void MainWindow::on_pushButton_20_clicked()
{
     myFunction.cancelBtn(ui->pushButton_20,ui->add10,"$10");
}
//Cancel 5
void MainWindow::on_pushButton_19_clicked()
{
      myFunction.cancelBtn(ui->pushButton_19,ui->pushButton_18,"$5");
}
//Cancel 25
void MainWindow::on_pushButton_21_clicked()
{
     myFunction.cancelBtn(ui->pushButton_21,ui->add25,"$25");
}
//Cancel 50
void MainWindow::on_pushButton_22_clicked()
{
     myFunction.cancelBtn(ui->pushButton_22,ui->add50,"$50");
}
//Cancel 100
void MainWindow::on_pushButton_23_clicked()
{
     myFunction.cancelBtn(ui->pushButton_23,ui->add100,"$100");
}
//Change Profile Picture
void MainWindow::on_pushButton_30_clicked()
{
    QDialog* edit = new editDetails;

    connect(edit,SIGNAL(selectedPicture(QString)),this,SLOT(setProfile(QString)));

    edit->exec();

}
//Go back to Profile
void MainWindow::on_pushButton_32_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

//Set Game Dialog Title
QString setTitle(QString Title){
    return Title;
}

//Set Game Dialog Description
QString setDescription(QString description, QString developer){
    return description;
    return developer;
}
//Set Game Dialog Cover Art
QString setCoverArt(QString CoverArt){
    return CoverArt;
}


//Darts Page
void MainWindow::on_pushButton_24_clicked()
{
    emit setTitle("Darts","1-2 Players");
    setCoverArt("game1_CA.jpg");
    setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pretium diam eget ullamcorper accumsan."
                   "Donec a sem nibh. Nunc egestas et libero pellentesque volutpat. Praesent erat neque, volutpat eget scelerisque"
                   "in, vehicula vel lorem. Mauris consectetur turpis risus, laoreet ultrices diam vestibulum mollis. Morbi lorem"
                   "ex, facilisis eget rhoncus iaculis, facilisis a elit. Quisque id orci consequat, viverra eros quis, elementum "
                   "magna. Praesent urna libero, varius sed ultricies tempor, ultricies et magna. Proin mauris felis, pellentesque "
                   "at vestibulum a, cursus in elit."
                   );
    gameEdit->exec();
}
//Tennis Page
void MainWindow::on_pushButton_25_clicked()
{
    setTitle("Tennis", "2 Players");
    setCoverArt("game2_CA.jpg");
    setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pretium diam eget ullamcorper accumsan."
                   "Donec a sem nibh. Nunc egestas et libero pellentesque volutpat. Praesent erat neque, volutpat eget scelerisque"
                   "in, vehicula vel lorem. Mauris consectetur turpis risus, laoreet ultrices diam vestibulum mollis. Morbi lorem"
                   "ex, facilisis eget rhoncus iaculis, facilisis a elit. Quisque id orci consequat, viverra eros quis, elementum "
                   "magna. Praesent urna libero, varius sed ultricies tempor, ultricies et magna. Proin mauris felis, pellentesque "
                   "at vestibulum a, cursus in elit."
                   );
    gameEdit->exec();
}

//Roulette Page
void MainWindow::on_pushButton_26_clicked()
{
    setTitle("Roulette", "2-4 Players" );
    setCoverArt("game3_CA.jpg");
    setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pretium diam eget ullamcorper accumsan."
                   "Donec a sem nibh. Nunc egestas et libero pellentesque volutpat. Praesent erat neque, volutpat eget scelerisque"
                   "in, vehicula vel lorem. Mauris consectetur turpis risus, laoreet ultrices diam vestibulum mollis. Morbi lorem"
                   "ex, facilisis eget rhoncus iaculis, facilisis a elit. Quisque id orci consequat, viverra eros quis, elementum "
                   "magna. Praesent urna libero, varius sed ultricies tempor, ultricies et magna. Proin mauris felis, pellentesque "
                   "at vestibulum a, cursus in elit."
                   );
    gameEdit->exec();
}

//Billiards
void MainWindow::on_pushButton_27_clicked()
{
    setTitle("Billiards", "1-2 Players" );
    setCoverArt("game4_CA.jpg");
    setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pretium diam eget ullamcorper accumsan."
                   "Donec a sem nibh. Nunc egestas et libero pellentesque volutpat. Praesent erat neque, volutpat eget scelerisque"
                   "in, vehicula vel lorem. Mauris consectetur turpis risus, laoreet ultrices diam vestibulum mollis. Morbi lorem"
                   "ex, facilisis eget rhoncus iaculis, facilisis a elit. Quisque id orci consequat, viverra eros quis, elementum "
                   "magna. Praesent urna libero, varius sed ultricies tempor, ultricies et magna. Proin mauris felis, pellentesque "
                   "at vestibulum a, cursus in elit."
                   );
    gameEdit->exec();
}

//Dominoes
void MainWindow::on_pushButton_28_clicked()
{
    setTitle("Dominoes", "1-2 Players" );
    setCoverArt("game5_CA.jpg");
    setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pretium diam eget ullamcorper accumsan."
                   "Donec a sem nibh. Nunc egestas et libero pellentesque volutpat. Praesent erat neque, volutpat eget scelerisque"
                   "in, vehicula vel lorem. Mauris consectetur turpis risus, laoreet ultrices diam vestibulum mollis. Morbi lorem"
                   "ex, facilisis eget rhoncus iaculis, facilisis a elit. Quisque id orci consequat, viverra eros quis, elementum "
                   "magna. Praesent urna libero, varius sed ultricies tempor, ultricies et magna. Proin mauris felis, pellentesque "
                   "at vestibulum a, cursus in elit."
                   );
    gameEdit->exec();
}

//Blackjack
void MainWindow::on_pushButton_29_clicked()
{
    setTitle("Blackjack", "2-4 Players" );
    setCoverArt("game6_CA.jpg");
    setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pretium diam eget ullamcorper accumsan."
                   "Donec a sem nibh. Nunc egestas et libero pellentesque volutpat. Praesent erat neque, volutpat eget scelerisque"
                   "in, vehicula vel lorem. Mauris consectetur turpis risus, laoreet ultrices diam vestibulum mollis. Morbi lorem"
                   "ex, facilisis eget rhoncus iaculis, facilisis a elit. Quisque id orci consequat, viverra eros quis, elementum "
                   "magna. Praesent urna libero, varius sed ultricies tempor, ultricies et magna. Proin mauris felis, pellentesque "
                   "at vestibulum a, cursus in elit."
                   );
    gameEdit->exec();
}
