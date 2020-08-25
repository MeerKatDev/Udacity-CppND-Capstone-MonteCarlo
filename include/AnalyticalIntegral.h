#ifndef ANALYTICAL_INTEGRAL_H
#define ANALYTICAL_INTEGRAL_H

#include "Integral.h"
#include <string>

using std::string;
using std::to_string;

class AnalyticalIntegral : public Integral {
public:
    AnalyticalIntegral(Expression expr);
    string calculate();
private:
    string calculateSingleTerm(TERM* term);
};

#endif