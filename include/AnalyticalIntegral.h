#ifndef ANALYTICAL_INTEGRAL_H
#define ANALYTICAL_INTEGRAL_H

#include "Integral.h"
#include <string>

using std::string;
using std::to_string;

class AnalyticalIntegral : public Integral<string> {
public:
    AnalyticalIntegral(const vector<TERM>& terms, const vector<char>& oprs): Integral(terms, oprs) {};
    string calculate();
private:
    string calculateSingleTerm(TERM* term);
};

#endif