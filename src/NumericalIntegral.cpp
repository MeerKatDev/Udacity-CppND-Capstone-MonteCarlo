#include "NumericalIntegral.h"
#include <math.h> 
#include <iterator>
#include <functional> 

NumericalIntegral::NumericalIntegral(Expression expr, float upperBound, float lowerBound) {
    expression = expr;
    upper_ = upperBound;
    lower_ = lowerBound;
}

float NumericalIntegral::calculate() {
    char[] oprs = expression.getOperators();
    TERM[] terms = expression.getTerms();
    // distinction between prev and result would be useful in case 
    // there were subexpressions
    float prev = 0;
    float result = 0;
    float current = 0;
    unsigned int opIdx = 0;
    vector<int>::iterator ptr;

    for (ptr = terms.begin(); ptr < terms.end(); ptr++) {
        current = calculateSingleTerm(ptr);
        result = withSign(prev, current, opIdx);
        opIdx++;
    }
    
    return result;
}

NumericalIntegral::withSign(float a, float b, char c) {
    switch(c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

float NumericalIntegral::calculateSingleTerm(TERM* term) {
    float pow =  term->power + 1;
    float coeff = term->coeff / pow;
    if(term->term_type = FUNCTION::fx) {
        return coeff * ((upper_ ** pow) - (lower_ ** pow));
    } else if(term->term_type = FUNCTION::fsin) {
        return coeff * ((sin(upper_) ** pow) * (-cos(upper_)) - (sin(lower_) ** pow) * (-cos(lower_)));
    } else if(term->term_type = FUNCTION::fcos) {
        return coeff * ((cos(upper_) ** pow) * (sin(upper_)) - (cos(lower_) ** pow) * (sin(lower_)));
    }
}