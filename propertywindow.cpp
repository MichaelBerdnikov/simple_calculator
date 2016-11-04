#include "propertywindow.h"

PropertyWindow::PropertyWindow(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    this->setLayout(layout);
    QPushButton* activateAdditionalButtons = new QPushButton("Additional buttons activation");
    QPushButton* deactivateAdditionalButtons = new QPushButton("Additional buttons deactivation");
    label = new QLabel("Select a number of decimal numbers");
    decimalNumbers = new QSpinBox();
    decimalNumbers->setRange(0, 10);
    decimalNumbers->setValue(4);
    layout->addWidget(activateAdditionalButtons, 0, 0);
    layout->addWidget(deactivateAdditionalButtons, 0, 2);
    layout->addWidget(label, 2, 0);
    layout->addWidget(decimalNumbers, 2, 2);

    //label = new QLabel("Hi", this);
    //label->show();
}



