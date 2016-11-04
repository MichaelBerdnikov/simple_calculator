#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

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
    QPushButton* activateAdditionalButtons;
    QPushButton* deacivateAdditionalButtons;
    QSpinBox *decimalNumbers;

signals:

private slots:
    void saveChangeDecimalNumber();



public slots:

};

#endif // PROPERTYWINDOW_H
