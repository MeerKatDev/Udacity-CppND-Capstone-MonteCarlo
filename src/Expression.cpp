#include "Expression.h"
#include <vector>

Expression::Expression(TERM& terms) {
    terms_ = &terms;
    oprs_ = nullptr;
}

Expression::Expression(TERM& terms, char& oprs) {
    terms_ = &terms;
    oprs_ = &oprs;
}

TERM* Expression::getTerms() {
    return terms_;
}

char* Expression::getOperators() {
    return oprs_;
}