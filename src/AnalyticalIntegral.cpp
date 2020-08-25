#include "AnalyticalIntegral.h"
#include <vector>

string AnalyticalIntegral::calculate() {
    // char* oprs = expression.getOperators();
    // char aoprs[strlen(oprs) + 1];
    // TERM* terms = (expression.getTerms());
    // TERM aterms[sizeof(terms)*strlen(oprs) + 1];
    string result = "";
    unsigned int opIdx = 0;
    
    for(TERM term : terms_) {
        result += calculateSingleTerm(&term);
        result += oprs_[opIdx];
        opIdx++;
    }
    
    return result;
};

string AnalyticalIntegral::calculateSingleTerm(TERM* term) {
    float pow =  term->power + 1;
    float coeff = term->coeff / pow;
    if(term->term_type == FUNCTION::fx) {
        return "(" + to_string(coeff) + ")" + "x^" + "(" + to_string(pow) + ")";
    } else if(term->term_type == FUNCTION::fsin) {
        return "(" + to_string(coeff) + ")" + "sin(x)^" + "(" + to_string(pow) + ")(-cos(x))";
    } else if(term->term_type == FUNCTION::fcos) {
        return "(" + to_string(coeff) + ")" + "cos(x)^" + "(" + to_string(pow) + ")(sin(x))";
    } else 
        return "";
};