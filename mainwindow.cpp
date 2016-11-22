#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaMethod>
#include <QMessageBox>
#include <math.h>
#include <QAction>
#include <QTime>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //mark = new Action (ui->lineEdit->text());

    using ButtonClickedSignalType = void(QButtonGroup::*)(QAbstractButton*);

    QObject::connect<ButtonClickedSignalType, decltype(&on_number_button_clicked)>
            (ui->buttonGroup, &QButtonGroup::buttonClicked, this, &on_number_button_clicked);
    QObject::connect(ui->pushButtonResult, &QPushButton::clicked, this, &pushButtonClicked);
    QObject::connect(ui->lineEdit, &QLineEdit::textEdited, this, &on_lineEdit_textEdited);
    QObject::connect(ui->pushButtonCE, &QPushButton::clicked, this, &textChangedCE);
    QObject::connect(ui->pushButtonC, &QPushButton::clicked, this, &textChangedC);
    QObject::connect(ui->pushButtonDel, &QPushButton::clicked, this, &textChangedDel);
    QObject::connect(ui->pushButtonDevide, &QPushButton::clicked, this, &binaryActionClicked);
    QObject::connect(ui->pushButtonMultiply, &QPushButton::clicked, this, &binaryActionClicked);
    QObject::connect(ui->pushButtonMinus, &QPushButton::clicked, this, &binaryActionClicked);
    QObject::connect(ui->pushButtonPlus, &QPushButton::clicked, this, &binaryActionClicked);
    QObject::connect(ui->pushButtonPlusMinus, &QPushButton::clicked, this, &textChangedPlusMinus);
    QObject::connect(ui->pushButtonPercent, &QPushButton::clicked, this, &textChangedPercent);
    QObject::connect(ui->pushButtonRoot, &QPushButton::clicked, this, &textChangedRoot);
    QObject::connect(ui->pushButtonSquare, &QPushButton::clicked, this, &textChangedSquare);
    QObject::connect(ui->pushButtonOneDelOnX, &QPushButton::clicked, this, &textChangedOneDelOnX);
    QObject::connect(ui->pushButtonMC, &QPushButton::clicked, this, &textChangedMC);
    QObject::connect(ui->pushButtonMR, &QPushButton::clicked, this, &textChangedMR);
    QObject::connect(ui->pushButtonMPlus, &QPushButton::clicked, this, &textChangedMPlus);
    QObject::connect(ui->pushButtonMMinus, &QPushButton::clicked, this, &textChangedMMinus);

    propertyWindow = new PropertyWindow();
    propertyWindow->setVisible(false);
    actionCurrency_Converter = new CurrencyConverter();
    actionCurrency_Converter->setVisible(false);

    QObject::connect(propertyWindow, &PropertyWindow::configurationChanged, this, &onConfigurationChanged);
    //Как сделать сигнал?
    onConfigurationChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete propertyWindow;
    delete actionCurrency_Converter;
    Configuration::save();
}

void MainWindow::pushButtonClicked() {
    QTime calculationTime;
    calculationTime.start();
    QString temp = ui->lineEdit->text();
    double result;
    if (first != 0 && action != "") {
        //Action::mark(action)
        if (action == "-") {
            result = first - temp.toDouble();
        } else if (action == "+") {
            result = first + temp.toDouble();
        } else if (action == "*") {
            result = first * temp.toDouble();
        } else {
            if (temp.toDouble() != 0) {
            result = first / temp.toDouble();
            } else {
                QMessageBox *box = new QMessageBox(this);
                box->setWindowTitle("Error");
                box->setText("Division by zero is not allowed");
                box->addButton(QMessageBox::Ok);
                box->show();
                return;
            }
        }

        setNumberToInputPanel(result);
    }
    if (ui->actionLogging->isChecked()) {
        QTime time = QTime::currentTime();
        QString log = "[INFO] " +
                      time.toString("hh:mm:ss.zzz") +
                      " " + "Calculator: " + QString::number(first) + " " +
                      action + " " + temp + " = " +
                      QString::number(result);
        QString duration;
        duration = "        Computation took " + QString::number(calculationTime.elapsed()) + " ms. ";
        //Почему показывает 0 миллисекунд?
        QString path = propertyWindow->chooseLogFile();
                /*QFileDialog::getSaveFileName(this,
                                                    QString("Save in log"),
                                                    QDir::currentPath(),
                                                    "*.txt");*/

        QFile file(path);
        file.open(QIODevice::Append);
        //Как не открывать диалоговое окно?
        QTextStream stream(&file);
        stream << log << '\n' << duration << '\n';
        //Почему не переносит строку???
        file.close();
    }


    action = "";
    action_clicked = true;
    previous_action = false;
   // if (first != 0 && action == "") {}
   // if (first == 0)
}

void MainWindow::on_lineEdit_textEdited(const QString &newText)
{
    QString correct_text;
    bool contains_dot = false;
    for (auto letter : newText) {
        if (letter.isNumber()) {
            correct_text += letter;
        }
        if (!contains_dot && (letter == '.' || letter == ',')) {
            correct_text += letter;
            contains_dot = true;
        }
    }
    ui->lineEdit->setText(correct_text.replace(',', '.'));
    previous_action = false;
}

void MainWindow::on_number_button_clicked(QAbstractButton *button)
{
    QString letter = button->text();
    if (action_clicked || (ui->lineEdit->text() == "0" && letter != ".")) {
        ui->lineEdit->setText("");
        action_clicked = false;
    }
    QString correct_text = ui->lineEdit->text();
    if (correct_text.contains(".") && letter == ".") {
        return;
    }
    correct_text += letter;
    // always
    ui->lineEdit->setText(correct_text.replace(',', '.'));
    ui->lineEdit->setFocus();
    previous_action = false;
}

void MainWindow::textChangedCE()
{
    ui->lineEdit->setText("0");
    previous_action = false;
}

void MainWindow::textChangedC()
{
    first = 0;
    action = "";
    ui->lineEdit->setText("0");
    previous_action = false;
}

void MainWindow::textChangedDel()
{
    QString temp = ui->lineEdit->text();
    QString result;
    result = temp.left(temp.size() - 1);
    ui->lineEdit->setText(result);
    previous_action = false;
}

void MainWindow::operation(QString operation)
{
    if (!previous_action) {
        if (action != "") {
            pushButtonClicked();
        }
        QString temp = ui->lineEdit->text();
        first = temp.toDouble();
    }
    action = operation;
    action_clicked = true;
    previous_action = true;
}

//Что-то не так, когда  последовательность 8 * = = = Результат дает только первый раз при нажатии = !!!

void MainWindow::textChangedPlusMinus()
{
    QString temp = ui->lineEdit->text();
    if (temp == "0") {
        return;
    }
    QString result;
    if (temp[0] == '-') {
        result = temp.mid(1);
    } else {
        result = '-' + temp;
    }
    ui->lineEdit->setText(result);
    previous_action = false;
}

void MainWindow::textChangedPercent()
{
    QString temp = ui->lineEdit->text();
    double result;
    if (first != 0 && action != "") {
        result = 100 * (first / temp.toDouble());
        setNumberToInputPanel(result);
    }
    action = "";
    previous_action = false;
}

void MainWindow::textChangedRoot()
{
    QString temp = ui->lineEdit->text();
    double result = temp.toDouble();
    powOperation(result, 0.5);
}

void MainWindow::textChangedSquare()
{
    QString temp = ui->lineEdit->text();
    double result = temp.toDouble();
    powOperation(result, 2.0);
}

void MainWindow::textChangedOneDelOnX()
{
    QString temp = ui->lineEdit->text();
    double result = temp.toDouble();
    if (result != 0) {
        result = 1.0 / result;
    }  else {
                    QMessageBox *box = new QMessageBox(this);
                    box->setWindowTitle("Error");
                    box->setText("Division by zero is not allowed");
                    box->addButton(QMessageBox::Ok);
                    box->show();
                    return;
    }
    setNumberToInputPanel(result);
    action = "";
    previous_action = false;
}

void MainWindow::textChangedMC()
{
    memory = 0;    
}

void MainWindow::textChangedMR()
{
    setNumberToInputPanel(memory);
    action_clicked = true;
    previous_action = false;
}

void MainWindow::textChangedMPlus()
{
    memory = memory + (ui->lineEdit->text()).toDouble();
    action_clicked = true;
}

void MainWindow::textChangedMMinus()
{
    memory = memory - (ui->lineEdit->text()).toDouble();
    action_clicked = true;
}

void MainWindow::binaryActionClicked()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    operation(button->text());
}

void MainWindow::powOperation(double base, double power)
{
    double result = pow(base, power);
    setNumberToInputPanel(result);
    action = "";
    previous_action = false;
}

void MainWindow::setNumberToInputPanel(double number)
{
    static const int maxVisibleSymbols = 58;
    QString text = QString::number(number, 'f', Configuration::getInstance().numbersAfterPoint);
    if (text.length() < maxVisibleSymbols) {
        ui->lineEdit->setText(text);
    } else {
        ui->lineEdit->setText(QString::number(number, 'e'));
    }
}



void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionProperties_triggered()
{
    propertyWindow->show();
}

void MainWindow::onConfigurationChanged()
{
    ui->pushButtonPercent->setVisible(Configuration::getInstance().isAdditionalButtonsDisplayed);
    ui->pushButtonRoot->setVisible(Configuration::getInstance().isAdditionalButtonsDisplayed);
    ui->pushButtonSquare->setVisible(Configuration::getInstance().isAdditionalButtonsDisplayed);
    ui->pushButtonOneDelOnX->setVisible(Configuration::getInstance().isAdditionalButtonsDisplayed);
}
/*
void MainWindow::actvateAdditionalButtons()
{
    ui->pushButtonPercent->setVisible(true);
    ui->pushButtonRoot->setVisible(true);
    ui->pushButtonSquare->setVisible(true);
    ui->pushButtonOneDelOnX->setVisible(true);
}

void MainWindow::deactivateAdditionalButtons()
{
    ui->pushButtonPercent->setVisible(false);
    ui->pushButtonRoot->setVisible(false);
    ui->pushButtonSquare->setVisible(false);
    ui->pushButtonOneDelOnX->setVisible(false);
}

void MainWindow::changeDecimalNumbers()
{
    decimalNumber = propertyWindow->decimalNumbers->value();
}

[INFO] 14:59:52.453 Calculator: 8 + 5 = 13
        Computation took 34 ms.
[INFO] ...
*/

void MainWindow::on_actionCurrency_Converter_triggered()
{
    actionCurrency_Converter->show();
}
