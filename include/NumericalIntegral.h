#ifndef NUMERICAL_INTEGRAL_H
#define NUMERICAL_INTEGRAL_H

#include "Integral.h"

class NumericalIntegral : public Integral<float> {
public:
    NumericalIntegral(Expression expr, float upperBound, float lowerBound);
    float calculate();
private:
    float withSign(float a, float b, char c);
    float calculateSingleTerm(TERM* term);
    float upper_;
    float lower_;
};

#endif