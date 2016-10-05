#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaMethod>



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
    QObject::connect(ui->pushButtonDevide, &QPushButton::clicked, this, &textChangedDevide);
    QObject::connect(ui->pushButtonMultiply, &QPushButton::clicked, this, &textChangedMultiply);
    QObject::connect(ui->pushButtonMinus, &QPushButton::clicked, this, &textChangedMinus);
    QObject::connect(ui->pushButtonPlus, &QPushButton::clicked, this, &textChangedPlus);
    QObject::connect(ui->pushButtonPlusMinus, &QPushButton::clicked, this, &textChangedPlusMinus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButtonClicked() {
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
            result = first / temp.toDouble();
        }
        ui->lineEdit->setText(QString::number(result));
    }
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
}

void MainWindow::on_number_button_clicked(QAbstractButton *button)
{
    QString letter = button->text();
    QString correct_text = ui->lineEdit->text();
    if (correct_text.contains(".") && letter == ".") {
        return;
    }
    correct_text += letter;
    ui->lineEdit->setText(correct_text.replace(',', '.'));
    ui->lineEdit->setFocus();    
}

void MainWindow::textChangedCE()
{
    ui->lineEdit->setText("0");
}

void MainWindow::textChangedC()
{
    first = 0;
    action = "";
    ui->lineEdit->setText("0");    
}

void MainWindow::textChangedDel()
{
    QString temp = ui->lineEdit->text();
    QString result;
    for (int i = 0; i < temp.size() - 1; i++) {
        result += temp[i];
    }
    ui->lineEdit->setText(result);
}

void MainWindow::textChangedDevide()
{
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "/";
}

void MainWindow::textChangedMultiply()
{
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "*";
}

void MainWindow::textChangedMinus()
{
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "-";
}

void MainWindow::textChangedPlus()
{
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "+";
}

void MainWindow::textChangedPlusMinus()
{
    QString temp = ui->lineEdit->text();
    QString result;
    if (temp[0] == '-') {
        for (int i = 1; i < temp.size(); i++) {
            result += temp[i];
        }
    } else {
        result[0] = '-';
        for (int i = 0; i < temp.size(); i++) {
            result += temp[i];
        }
    }
    ui->lineEdit->setText(result);
}


