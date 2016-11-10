#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QWindow>
//#include <QBoxLayout>
//#include <QAbstractButton>

class PropertyWindow : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* layout;

    QLabel *label;


public:
    explicit PropertyWindow(QWidget *parent = 0);
    QPushButton* activAdditionalButtons;
    QPushButton* deactivAdditionalButtons;
    QSpinBox *decimalNumbers;

signals:

private slots:




public slots:
    void saveChangeDecimalNumber(int newValue);

};

#endif // PROPERTYWINDOW_H
