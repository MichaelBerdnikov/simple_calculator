#include "propertywindow.h"

PropertyWindow::PropertyWindow(QWidget *parent) : QWidget(parent)
{
    label = new QLabel("Hi", this);
    label->show();
}
