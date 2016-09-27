#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    if (act == 3) {
        second = "0";
        act = 2;
    } else if (act == 2) {
        second = "0";
        action = "";
        act = 1;
    } else if (act == 1) {
        second = "0";
        action = "";
        first = "0";
        act = 0;
    } else {
        second = "0";
        action = "";
        first = "0";
        act = 0;
    }
    ui->lineEdit->setText("0");
}

void MainWindow::textChangedC()
{
    first = "0";
    second = "0";
    action = "";
    previousFirst = "0";
    previousSecond = "0";
    previousAction = "";
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
    }
}

void MainWindow::textChangedDevide()
{
    if (act == 3) {
        pushButtonClicked();
        first = "0";
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
        first = "0";
        act = 2;
    }
}

void MainWindow::textChangedMultiply()
{
    if (act == 3) {
        pushButtonClicked();
        first = "0";
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
        first = "0";
        act = 2;
    }

}

void MainWindow::textChangedMinus()
{
    if (act == 3) {
        pushButtonClicked();
        first = "0";
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
        first = "0";
        act = 2;
    }

}

void MainWindow::textChangedPlus()
{
    if (act == 3) {
        pushButtonClicked();
        first = "0";
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
        first = "0";
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
        first = "0";
        act = 1;
    }
}
