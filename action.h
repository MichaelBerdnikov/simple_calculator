#ifndef ACTION_H
#define ACTION_H

#include <QString>


class Action
{
private:
    QString arithmeticOperation;
public:
    Action(QString str);
    char act();
};

#endif // ACTION_H
