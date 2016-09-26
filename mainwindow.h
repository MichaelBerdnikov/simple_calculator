#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

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

private slots:
    //void pushButtonClicked();
    void pushButtonClicked();
    void on_lineEdit_textEdited(const QString &arg1);
    void on_number_button_clicked(QAbstractButton *button);
    void textChangedCE();
    void textChangedC();
    void textChangedDel();
    void textChangedDevide();
    void textChangedMultiply();
    void textChangedMinus();
    void textChangedPlus();
    void textChangedResult();
    void textChangedPlusMinus();
};



#endif // MAINWINDOW_H
