#ifndef NUMERICAL_INTEGRAL_H
#define NUMERICAL_INTEGRAL_H

#include "Integral.h"

class NumericalIntegral : public Integral<float> {
public:
    NumericalIntegral(const vector<TERM>& terms, const vector<char>& oprs, float upperBound, float lowerBound)
        : upper_(upperBound), lower_(lowerBound), Integral(terms, oprs) {};
    float calculate();
private:
    float withSign(float a, float b, char c);
    float calculateSingleTerm(TERM* term);
    float upper_;
    float lower_;
};

#endif