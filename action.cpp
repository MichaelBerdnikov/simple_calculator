#include "action.h"

Action::Action(QString str) {
   arithmeticOperation = str;
}

char Action::act() {
    if (arithmeticOperation == "*") {
        return '*';
    } else if (arithmeticOperation == "/") {
        return '/';
    } else if (arithmeticOperation == "+") {
        return '+';
    } else if (arithmeticOperation == "-") {
        return '-';
    }
}
