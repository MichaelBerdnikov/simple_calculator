#include "action.h"

action::action(QString text) {
    arithmeticOperation = text;
}

char act() {
    if (arithmeticOperation == "*") {
        return '*';
    } else if (arithmeticOperation == "/") {
        return '/';
    } else if (arithmeticOperation == "+") {
        return '+';
    } else if (action == "-") {
        return '-';
    }
}
