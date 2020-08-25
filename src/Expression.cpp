#include "Expression.h"
#include <vector>

Expression::Expression(int[] array) {
    std::vector<TERM> internal;
    terms_ = std::make_unique<int[]>(array);

}

int[] Expression::getTerms() {
    return terms_.get();
}