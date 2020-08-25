#include "NumericalIntegral.h"
#include <math.h> 
#include <iterator>
#include <functional> 

float NumericalIntegral::calculate() {
    // distinction between prev and result would be useful in case 
    // there were subexpressions
    float prev = 0;
    float result = 0;
    float current = 0;
    unsigned int opIdx = 0;
    vector<int>::iterator ptr;

    for(TERM term : terms_) {
        result += calculateSingleTerm(&term);
        result += oprs_[opIdx];
        opIdx++;
    }
    
    return result;
};

float NumericalIntegral::withSign(float a, float b, char c) {
    switch(c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
};

float NumericalIntegral::calculateSingleTerm(TERM* term) {
    float power =  term->power + 1;
    float coeff = term->coeff / power;
    if(term->term_type == FUNCTION::fx) {
        return coeff * (pow(upper_, power) - pow(lower_, power));
    } else if(term->term_type == FUNCTION::fsin) {
        return coeff * (pow(sin(upper_), power) * (-cos(upper_)) - pow(sin(lower_), power) * (-cos(lower_)));
    } else if(term->term_type == FUNCTION::fcos) {
        return coeff * (pow(cos(upper_), power) * (sin(upper_)) - (pow(cos(lower_), power) * (sin(lower_))));
    } else 
        return 0;
};