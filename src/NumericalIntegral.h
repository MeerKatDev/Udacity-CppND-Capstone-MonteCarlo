/*
 - constructor takes expression
 - 
*/ 
#include "Integral.h"

class NumericalIntegral : public Integral {
public:
    NumericalIntegral(Expression expr, float upperBound, float lowerBound);
    float calculate();
private:
    float calculateSingleTerm(TERM* term);
    float upper_;
    float lower_;
};