#include "action.h"

action::action() {}

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
