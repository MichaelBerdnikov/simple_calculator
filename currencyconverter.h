#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QWindow>

class CurrencyConverter : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* converterLayout;
    QLabel *currencyName;
    QLabel *currencyName2;
    QLabel *exchangeRate;
    QLineEdit *sumCurrency;
    QLineEdit *sumCurrency2;
    QDoubleSpinBox *exchangeRateEdit;


public:
    explicit CurrencyConverter(QWidget *parent = 0);

public slots:
    void sumCurrencyEdit(QString newValue);
    void sumCurrency2Edit(QString newValue2);
    void exchangeRateChange(double newRate);
    void saveToLog();

};

#endif // CURRENCYCONVERTER_H
