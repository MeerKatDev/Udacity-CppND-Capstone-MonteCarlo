#include "Expression.h"
#include <vector>

Expression::Expression(TERM terms[]) {
    terms_ = std::make_unique<TERM[]>(terms);
    oprs_ = std::make_unique<char[]>(terms.length());
}

Expression::Expression(TERM terms[], char oprs[]) {
    terms_ = std::make_unique<TERM[]>(terms);
    oprs_ = std::make_unique<char[]>(oprs);
}

TERM* Expression::getTerms() {
    return terms_.get();
}

char* Expression::getOperators {
    return oprs_.get();
}