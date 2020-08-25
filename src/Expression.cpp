#include "Expression.h"
#include <vector>

Expression::Expression(TERM[] array) {
    std::vector<TERM> internal;
    terms_ = std::make_unique<TERM[]>(array);
}

Expression::Expression(TERM[] terms, char[] oprs) {

}

int[] Expression::getTerms() {
    return terms_.get();
}