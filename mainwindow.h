#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

#include "action.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double first;
    double memory;
    QString action;
    bool action_clicked;
    //Action mark;

    //int act;

private slots:
    //void pushButtonClicked();
    void pushButtonClicked();
    void on_lineEdit_textEdited(const QString &arg1);
    void on_number_button_clicked(QAbstractButton *button);
    void textChangedCE();
    void textChangedC();
    void textChangedDel();
    void operation(QString operation);
    void textChangedDevide();
    void textChangedMultiply();
    void textChangedMinus();
    void textChangedPlus();
    void textChangedPlusMinus();
    void textChangedPercent();
    void textChangedRoot();
    void textChangedSquare();
    void textChangedOneDelOnX();
    void textChangedMC();
    void textChangedMR();
    void textChangedMPlus();
    void textChangedMMinus();
};



#endif // MAINWINDOW_H
