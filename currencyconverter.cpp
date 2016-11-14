#include "currencyconverter.h"

CurrencyConverter::CurrencyConverter(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    this->setLayout(layout);
    currencyName = new QLabel("Ruble");
    currencyName2 = new QLabel("Dollar");
    exchangeRate = new QLabel("Rubles for one dollar");
    sumCurrency = new QLineEdit();
    sumCurrency2 = new QLineEdit();
    exchangeRateEdit = new QLineEdit();
    layout->addWidget(currencyName, 0, 0);
    layout->addWidget(currencyName2, 0, 2);
    layout->addWidget(exchangeRate, 0, 4);
    layout->addWidget(sumCurrency, 2, 0);
    layout->addWidget(sumCurrency2, 2, 2);
    layout->addWidget(exchangeRateEdit, 2, 4);
    QObject::connect(sumCurrency, &QLineEdit::textEdited, this, &sumCurrencyEdit);
    QObject::connect(sumCurrency2, &QLineEdit::textEdited, this, &sumCurrency2Edit);
    QObject::connect(exchangeRateEdit, &QLineEdit::textEdited, this, &exchangeRateChange);
}

void CurrencyConverter::sumCurrencyEdit(QString newValue)
{
    sumCurrency->text() = newValue;
    if (exchangeRate->text().toDouble() != 0) {
    sumCurrency2->setText(QString::number(newValue.toDouble() / exchangeRate->text().toDouble()));
    } else {
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Error");
        box->setText("The exchange rate is not defined. Enter the exchange rate!");
        box->addButton(QMessageBox::Ok);
        box->show();
        return;
    }
}

void CurrencyConverter::sumCurrency2Edit(QString newValue2)
{
    sumCurrency2->text() = newValue2;
    if (exchangeRate->text().toDouble() != 0) {
        sumCurrency->setText(QString::number(newValue2.toDouble() * exchangeRate->text().toDouble()));
    } else {
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Error");
        box->setText("The exchange rate is not defined. Enter the exchange rate!");
        box->addButton(QMessageBox::Ok);
        box->show();
        return;
    }
}

void CurrencyConverter::exchangeRateChange(QString newRate)
{
    exchangeRateEdit->text() = newRate;
    if (exchangeRate->text().toDouble() != 0) {
        sumCurrency2->setText(QString::number(sumCurrency->text().toDouble() / (exchangeRateEdit->text().toDouble())));
    } else {
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Error");
        box->setText("The exchange rate is not defined. Enter the exchange rate!");
        box->addButton(QMessageBox::Ok);
        box->show();
        return;
    }

}

