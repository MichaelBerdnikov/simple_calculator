#include "propertywindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>

PropertyWindow::PropertyWindow(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    this->setLayout(layout);
    activeAdditionalCheckBox = new QCheckBox("Show additional buutons", this);
    activeAdditionalCheckBox->setChecked(Configuration::getInstance().isAdditionalButtonsDisplayed);
    label = new QLabel("Select a number of decimal numbers");
    openLogFile = new QPushButton("Select a log file");
    decimalNumbers = new QSpinBox();
    decimalNumbers->setRange(0, 10);
    decimalNumbers->setValue(Configuration::getInstance().numbersAfterPoint);
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
    layout->addWidget(activeAdditionalCheckBox, 0, 0);
    layout->addWidget(label, 2, 0);
    layout->addWidget(decimalNumbers, 2, 2);
    layout->addWidget(openLogFile, 4, 0);

    QObject::connect(PropertyWindow::decimalNumbers, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &saveChangeDecimalNumber);
    QObject::connect(activeAdditionalCheckBox, &QCheckBox::stateChanged, this, &onActiveAdditionalCheckBoxStateChanged);
    QObject::connect(openLogFile, &QPushButton::pressed, this, &chooseLogFile);

    //label = new QLabel("Hi", this);
    //label->show();
}

void PropertyWindow::saveChangeDecimalNumber(int newValue)
{
    Configuration::getInstance().numbersAfterPoint = newValue;
    /*
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
    */
}

void PropertyWindow::onActiveAdditionalCheckBoxStateChanged(int state)
{
    Configuration::getInstance().isAdditionalButtonsDisplayed = (state == Qt::Checked);
    emit configurationChanged();
}

void PropertyWindow::chooseLogFile()
{
    QString filename = QFileDialog::getSaveFileName(
                        this,
                        tr("Choose Document"),
                        QDir::currentPath(),
                        tr("Documents (*.txt)") );
            if(filename.isNull())
            {
                QMessageBox *box = new QMessageBox(this);
                box->setWindowTitle("Error");
                box->setText("File is not defined");
                box->addButton(QMessageBox::Ok);
                box->show();
                return;
            }
}





