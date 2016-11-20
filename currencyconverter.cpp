#include "currencyconverter.h"

CurrencyConverter::CurrencyConverter(QWidget *parent) : QWidget(parent)
{
    converterLayout = new QGridLayout(this);
    this->setLayout(converterLayout);
    currencyName = new QLabel("Ruble");
    currencyName2 = new QLabel("Dollar");
    exchangeRate = new QLabel("Rubles for one dollar");
    sumCurrency = new QLineEdit();
    sumCurrency2 = new QLineEdit();
    exchangeRateEdit = new QDoubleSpinBox();
    exchangeRateEdit->setDecimals(4);
    exchangeRateEdit->setMinimum(0.0001);
    exchangeRateEdit->setSingleStep(0.0001);
    converterLayout->addWidget(currencyName, 0, 0);
    converterLayout->addWidget(currencyName2, 0, 2);
    converterLayout->addWidget(exchangeRate, 0, 4);
    converterLayout->addWidget(sumCurrency, 2, 0);
    converterLayout->addWidget(sumCurrency2, 2, 2);
    converterLayout->addWidget(exchangeRateEdit, 2, 4);
    QObject::connect(sumCurrency, &QLineEdit::textEdited, this, &sumCurrencyEdit);
    QObject::connect(sumCurrency2, &QLineEdit::textEdited, this, &sumCurrency2Edit);
    QObject::connect(exchangeRateEdit,
                     static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
                     this,
                     &exchangeRateChange);
}

void CurrencyConverter::sumCurrencyEdit(QString newValue)
{
    sumCurrency2->setText(QString::number(newValue.toDouble() / exchangeRateEdit->value()));
}

void CurrencyConverter::sumCurrency2Edit(QString newValue2)
{
    sumCurrency->setText(QString::number(newValue2.toDouble() * exchangeRateEdit->value()));
}

void CurrencyConverter::exchangeRateChange(double newRate)
{
    sumCurrencyEdit(sumCurrency->text());
}

