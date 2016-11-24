#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QWindow>
#include "configuration.h"
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
    QCheckBox *activeAdditionalCheckBox;
    QSpinBox *decimalNumbers;
    QPushButton *openLogFile;
signals:
    void configurationChanged();
    void logFilePathChanged(const QString& newPath);
public slots:
    void saveChangeDecimalNumber(int newValue);
    void onActiveAdditionalCheckBoxStateChanged(int state);
    void chooseLogFile();

};

#endif // PROPERTYWINDOW_H
