#include "action.h"

Action::action(QString text) {
    str = text;
}

char act() {
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
