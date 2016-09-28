#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaMethod>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    if (act == 3) {
        if (action == "*") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN * firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        } else if (action == "/") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN / firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        } else if (action == "+") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN + firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        } else if (action == "-") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN - firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        }
        act = 1;
    } else if (act == 2) {
        second = first;
        if (action == "*") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN * firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        } else if (action == "/") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN / firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        } else if (action == "+") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN + firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        } else if (action == "-") {
            double firstN = first.toDouble();
            double secondN = second.toDouble();
            double result = secondN - firstN;
            QString resultStr = QString::number(result);
            ui->lineEdit->setText(resultStr);
        }
        act = 1;
    }
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
    if (act == 0 || act == 1) {
    QString letter = button->text();
    QString correct_text = ui->lineEdit->text();
    if (correct_text.contains(".") && letter == ".") {
        return;
    }
    correct_text += letter;
    ui->lineEdit->setText(correct_text.replace(',', '.'));
    ui->lineEdit->setFocus();
    act = 1;
    } else if (act == 2) {
        QString letter = button->text();
        QString correct_text = ui->lineEdit->text();
        if (correct_text.contains(".") && letter == ".") {
            return;
        }
        correct_text += letter;
        ui->lineEdit->setText(correct_text.replace(',', '.'));
        ui->lineEdit->setFocus();
        act = 3;
    } else {
        QString letter = button->text();
        QString correct_text = ui->lineEdit->text();
        if (correct_text.contains(".") && letter == ".") {
            return;
        }
        correct_text += letter;
        ui->lineEdit->setText(correct_text.replace(',', '.'));
        ui->lineEdit->setFocus();
        act = 3;
    }
}

void MainWindow::textChangedCE()
{
    if (act == 3) {
        second = "";
        act = 2;
    } else if (act == 2) {
        second = "";
        action = "";
        act = 1;
    } else if (act == 1) {
        second = "";
        action = "";
        first = "";
        act = 0;
    } else {
        second = "";
        action = "";
        first = "";
        act = 0;
    }
    ui->lineEdit->setText("0");
}

void MainWindow::textChangedC()
{
    first = "";
    second = "";
    action = "";
    ui->lineEdit->setText("0");
    act = 0;
}

void MainWindow::textChangedDel()
{
    if (act == 3) {
        if (second.size() != 0) {
            QString temp = second;
            second = "";
            for (int i = 0; i < temp.size() - 1; i++) {
                second += temp[i];
            }
        }
        ui->lineEdit->setText(second);
    }
    else if (act == 1) {
        second = "0";
        action = "";
        if (first.size() != 0) {
            QString temp = first;
            first = "";
            for (int i = 0; i < temp.size() - 1; i++) {
                first += temp[i];
            }
        }
        act = 1;
        ui->lineEdit->setText(first);
    }
}

void MainWindow::textChangedDevide()
{
    if (act == 3) {
        pushButtonClicked();
        first = "";
        action = "/";
        second = "";
        act = 2;
    } else if (act == 2) {
        action = "/";
        act = 2;
    } else if (act == 1) {
        first = ui->lineEdit->text();
        action = "/";
        act = 2;
    } else {
        second = "";
        action = "/";
        first = "";
        act = 2;
    }
}

void MainWindow::textChangedMultiply()
{
    if (act == 3) {
        pushButtonClicked();
        first = "";
        action = "*";
        second = "";
        act = 2;
    } else if (act == 2) {
        action = "*";
        act = 2;
    } else if (act == 1) {
        first = ui->lineEdit->text();
        action = "*";
        act = 2;
    } else {
        second = "";
        action = "*";
        first = "";
        act = 2;
    }

}

void MainWindow::textChangedMinus()
{
    if (act == 3) {
        pushButtonClicked();
        first = "";
        action = "-";
        second = "";
        act = 2;
    } else if (act == 2) {
        action = "-";
        act = 2;
    } else if (act == 1) {
        first = ui->lineEdit->text();
        action = "-";
        act = 2;
    } else {
        second = "";
        action = "-";
        first = "";
        act = 2;
    }

}

void MainWindow::textChangedPlus()
{
    if (act == 3) {
        pushButtonClicked();
        first = "";
        action = "+";
        second = "";
        act = 2;
    } else if (act == 2) {
        action = "+";
        act = 2;
    } else if (act == 1) {
        first = ui->lineEdit->text();
        action = "+";
        act = 2;
    } else {
        second = "";
        action = "+";
        first = "";
        act = 2;
    }
}

void MainWindow::textChangedPlusMinus()
{
    if (act == 3) {
        if (second[0] == '-') {
            QString temp = second;
            second = "";
            for (int i = 1; i < temp.size(); i++) {
                second += temp[i];
            }
        } else {
            second = "-" + second;
        }
    } else if (act == 2) {
        if (first[0] == '-') {
            QString temp = first;
            second = "";
            for (int i = 1; i < temp.size(); i++) {
                second += temp[i];
            }
        } else {
            second = "-" + first;
        }
        act = 3;
    } else if (act == 1) {
        if (first[0] == '-') {
            QString temp = first;
            first = "";
            for (int i = 1; i < temp.size(); i++) {
                first += temp[i];
            }
        } else {
            first = "-" + first;
        }
    } else {
        first = "";
        act = 1;
    }
}
