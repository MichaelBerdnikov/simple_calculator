#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QWindow>

class PropertyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyWindow(QWidget *parent = 0);
    QLabel *label;
signals:

public slots:
};

#endif // PROPERTYWINDOW_H
