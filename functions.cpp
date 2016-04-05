#include "Functions.h"

Functions::Functions(){

}

Functions::~Functions(){

}

/*Update user balances*/
void Functions::updateBalance(QLabel *label1, QLabel *label2, QLabel *label3, double balance) {
    label1->setText("$ " +  QString::number(balance));
    label2->setText("$ " +  QString::number(balance));
    label3->setText("$ " +  QString::number(balance));
}

/*set the button*/
void Functions::setPurchased(QPushButton *btn){
    btn->setStyleSheet("background-color: #336699;"
                                  "border-style: solid;"
                                  "border-width: 2px;"
                                  "border-color: #204060;"
                                  "font: 12px;"
                                  "color: white;"
                                  "padding-top:8px;"
                                  "padding-bottom:8px;"
                                  "padding-left: 8px;"
                                  "padding-right: 8px;");
    btn->setText("Purchased");
    btn->setEnabled(false);
}

/*Overloaded Functions for hiding buttons*/
void Functions::hideElement(QPushButton *btn){
    btn->setFocusPolicy(Qt::NoFocus);
    btn->setEnabled(false);
    btn->setVisible(false);
}

/*Overloaded Functions for showing buttons*/
void Functions::showElement(QPushButton *btn){
    btn->setFocusPolicy(Qt::NoFocus);
    btn->setEnabled(true);
    btn->setVisible(true);
}

/*Overloaded Functions for showing labels*/
void Functions::showElement(QLabel *label){
    label->setFocusPolicy(Qt::NoFocus);
    label->setEnabled(true);
    label->setVisible(true);
}

/*Overloaded Functions for hiding labels*/
void Functions::hideElement(QLabel *label){
    label->setFocusPolicy(Qt::NoFocus);
    label->setEnabled(false);
    label->setVisible(false);
}

/*If the purchase is succesful, set labels*/
bool Functions::tryPurchase(QPushButton *buyBtn, double price, QPushButton *canBtn, QLabel *errLab, double* dollars){

    QString sPrice = QString::number(price);
    QString Confirm = "Confirm?";

    //If Showing price
    if(buyBtn->text() != Confirm){
        showElement(canBtn);
        buyBtn->setText(Confirm);
    }
    //If Confirming
    else if (buyBtn->text() != sPrice){

        //If we can afford it

        if(!(*dollars - price < 0)) {
            *dollars = *dollars - price;
            hideElement(canBtn);
            hideElement(errLab);
            setPurchased(buyBtn);
            return true;
        }
        else {
            //OUTPUT ERROR
           showElement(errLab);
           return false;
        }
    }
    return false;

}

/*Add currency*/
void Functions::addCurrency(QPushButton *valueBtn, QPushButton *cancelBtn ,double value, double* dollars){
    QString sValue = QString::number(value);
    QString Confirm = "Confirm";

    if(valueBtn->text() != Confirm){
        showElement(cancelBtn);
        valueBtn->setText(Confirm);
    }
    else if (valueBtn->text() != sValue){
        *dollars = *dollars + value;
        hideElement(cancelBtn);
        valueBtn->setText("$" +sValue);
    }
}

/*Overloaded Functions for cancel buttons*/
void Functions::cancelBtn(QPushButton *selfBtn, QPushButton *otherBtn, QLabel *Error, QString Text){
    hideElement(selfBtn);
    hideElement(Error);
    otherBtn->setText(Text);
}

/*Overloaded Functions for cancel buttons*/
void Functions::cancelBtn(QPushButton *selfBtn, QPushButton *otherBtn, QString Text){
    hideElement(selfBtn);
    otherBtn->setText(Text);
}

/*Add to owned games*/
void Functions::addPurchases(QTableWidget *purchased, int &row, int &col, QString title, QString coverArt, QLabel *Error){

    QPushButton *button =new QPushButton;
    QTableWidgetItem *gameTitle = new QTableWidgetItem;
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget* wdg = new QWidget;
    QLabel *label = new QLabel;
    QPixmap pixm (":/Assets/Activities/" +coverArt);

    title = " " + title;

    button->setStyleSheet("QPushButton {"
                                  "background-color: #336699;"
                                  "border-style: solid;"
                                  "border-width: 2px;"
                                  "border-color: #204060;"
                                  "font: 12px;"
                                  "color: white;"
                                  "padding-top:8px;"
                                  "padding-bottom:8px;"
                                  "padding-left: 8px;"
                                  "padding-right: 8px;}"
                          "QPushButton:hover {"
                            "border: 2px solid #26b7ff;"
                            "}"
                          "QPushButton:pressed {"
                            "color:white;"
                            "background-color:#204060;"
                            "}"
                          );

    button->setMaximumHeight(35);
    button->setMaximumWidth(135);
    button->setFocusPolicy(Qt::NoFocus);
    button->setText("Download");

    layout->addSpacing(6);
    layout->addWidget(button);
    layout->addSpacing(6);

    //Determine Color of Rows
    if ( row % 2 == 0 ){
       wdg->setStyleSheet("background-color: #34495e");
    }else {
      wdg->setStyleSheet("background-color: #2c3e50");
    }

    wdg->setLayout(layout);
    purchased->setRowCount(row + 1);
    purchased->setRowHeight(row,69);
    purchased->setColumnWidth(0,169);
    purchased->setColumnWidth(1,135);
    purchased->setRowHeight(2,69);
    purchased->setColumnWidth(2,173);
    purchased->setCellWidget(row,0,label);
    purchased->setColumnWidth(1,300);
    purchased->setItem(row, 1,gameTitle);
    purchased->setCellWidget(row, 2,wdg);

    label->setPixmap(pixm.scaled(169,69,Qt::KeepAspectRatio));

    gameTitle->setTextColor("#26b7ff");
    gameTitle->setFont(QFont( "Arial", 18, QFont::Bold));
    gameTitle->setText(title);

    Error->setEnabled(false);
    Error->setVisible(false);

    row +=1;
    col +=1;

}
