#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaMethod>
#include <QMessageBox>


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
        ui->lineEdit->setText(QString::number(result));
    }
    action = "";
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
    if (action != "") {
        pushButtonClicked();
    }
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "/";
    action_clicked = true;
}

void MainWindow::textChangedMultiply()
{
    if (action != "") {
        pushButtonClicked();
    }
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "*";
    action_clicked = true;
}

void MainWindow::textChangedMinus()
{
    if (action != "") {
        pushButtonClicked();
    }
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "-";
    action_clicked = true;
}

void MainWindow::textChangedPlus()
{
    if (action != "") {
        pushButtonClicked();
    }
    QString temp = ui->lineEdit->text();
    first = temp.toDouble();
    action = "+";
    action_clicked = true;
}

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
}


