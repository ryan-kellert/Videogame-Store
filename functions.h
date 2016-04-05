#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "string"
#include "QPainter"
#include <QLabel>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QtCore>

class Functions {
    public:
        ~Functions();
        Functions();
        bool tryPurchase(QPushButton *buyBtn, double price, QPushButton *canBtn, QLabel *errLab, double* dollars);
        void updateBalance(QLabel *label1, QLabel *label2, QLabel *label3, double balance);
        void hideElement(QPushButton *btn);
        void hideElement(QLabel *label);
        void showElement(QPushButton *btn);
        void showElement(QLabel *label);
        void setPurchased(QPushButton *btn);
        void addCurrency(QPushButton *valueBtn, QPushButton *cancelBtn, double value, double* dollars);
        void cancelBtn(QPushButton *selfBtn, QPushButton *otherBtn, QLabel *Error, QString Text);
        void cancelBtn(QPushButton *selfBtn, QPushButton *otherBtn, QString Text);
        void addPurchases(QTableWidget *purchased, int &row, int &col, QString title, QString coverArt, QLabel *Error);
    };
#endif // FUNCTIONS_H
