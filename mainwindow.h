#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

#include "action.h"
#include "propertywindow.h"

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
    bool previous_action;
    //Action mark;
    PropertyWindow *propertyWindow;
    //int act;
    int decimalNumber;

private slots:
    //void pushButtonClicked();
    void pushButtonClicked();
    void on_lineEdit_textEdited(const QString &arg1);
    void on_number_button_clicked(QAbstractButton *button);
    void textChangedCE();
    void textChangedC();
    void textChangedDel();
    void operation(QString operation);
    void textChangedPlusMinus();
    void textChangedPercent();
    void textChangedRoot();
    void textChangedSquare();
    void textChangedOneDelOnX();
    void textChangedMC();
    void textChangedMR();
    void textChangedMPlus();
    void textChangedMMinus();

    void binaryActionClicked();
    void powOperation(double base, double power);
    void setNumberToInputPanel(double number);
    void on_actionExit_triggered();
    void on_actionProperties_triggered();

    void actvateAdditionalButtons();
    void deactivateAdditionalButtons();
    void changeDecimalNumbers();

};



#endif // MAINWINDOW_H
