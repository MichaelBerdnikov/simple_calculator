#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &pushButtonClicked);
    QObject::connect(ui->lineEdit, &QLineEdit::textEdited, this, &on_lineEdit_textEdited);
    QObject::connect(ui->pushButtonCE, &QPushButton::clicked, this, &textChangedCE);
    QObject::connect(ui->pushButtonC, &QPushButton::clicked, this, &textChangedC);
    QObject::connect(ui->pushButtonDel, &QPushButton::clicked, this, &textChangedDel);
    QObject::connect(ui->pushButtonDevide, &QPushButton::clicked, this, &textChangedDevide);
    QObject::connect(ui->pushButtonMultiply, &QPushButton::clicked, this, &textChangedMultiply);
    QObject::connect(ui->pushButtonMinus, &QPushButton::clicked, this, &textChangedMinus);
    QObject::connect(ui->pushButtonPlus, &QPushButton::clicked, this, &textChangedPlus);
    QObject::connect(ui->pushButtonResult, &QPushButton::clicked, this, &textChangedResult);
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

}

void MainWindow::textChangedC()
{

}

void MainWindow::textChangedDel()
{

}

void MainWindow::textChangedDevide()
{

}

void MainWindow::textChangedMultiply()
{

}

void MainWindow::textChangedMinus()
{

}

void MainWindow::textChangedPlus()
{

}

void MainWindow::textChangedResult()
{

}

void MainWindow::textChangedPlusMinus()
{

}
