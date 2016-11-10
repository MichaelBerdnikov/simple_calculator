#include "propertywindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>

PropertyWindow::PropertyWindow(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    this->setLayout(layout);
    activAdditionalButtons = new QPushButton("Additional buttons activation");
    deactivAdditionalButtons = new QPushButton("Additional buttons deactivation");
    label = new QLabel("Select a number of decimal numbers");
    decimalNumbers = new QSpinBox();
    decimalNumbers->setRange(0, 10);
    decimalNumbers->setValue(0);
    /*QString path = QFileDialog::getOpenFileName(this,
                                                QString("Load File"),
                                                QDir::homePath(),
                                                "*.txt");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();
    decimalNumbers->setValue(content.toInt());
    */
    layout->addWidget(activAdditionalButtons, 0, 0);
    layout->addWidget(deactivAdditionalButtons, 0, 2);
    layout->addWidget(label, 2, 0);
    layout->addWidget(decimalNumbers, 2, 2);

    //QObject::connect(PropertyWindow::decimalNumbers, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &saveChangeDecimalNumber);

    //label = new QLabel("Hi", this);
    //label->show();
}

void PropertyWindow::saveChangeDecimalNumber(int newValue)
{
    QString content = QString::number(newValue);
    QString path = QFileDialog::getSaveFileName(this,
                                                QString("Save File"),
                                                QDir::homePath(),
                                                "*.txt");

    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    stream << content;
    file.close();
}



