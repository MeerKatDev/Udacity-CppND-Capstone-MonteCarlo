#include "AnalyticalIntegral.h"

AnalyticalIntegral::AnalyticalIntegral(Expression expr) {
    expression = expr;
}

string AnalyticalIntegral::calculate() {
    char[] oprs = expression.getOperators();
    TERM[] terms = expression.getTerms();
    string result = "";
    unsigned int opIdx = 0;
    vector<int>::iterator ptr;
    
    for (ptr = terms.begin(); ptr < terms.end(); ptr++) {
        result += calculateSingleTerm(ptr);
        result += oprs[opIdx];
        opIdx++;
    }
    return result;
}

string AnalyticalIntegral::calculateSingleTerm(TERM* term) {
    float pow =  term->power + 1;
    float coeff = term->coeff / pow;
    if(term->term_type = FUNCTION::fx) {
        return "(" + to_string(coeff) + ")" + "x^" + "(" + to_string(pow) + ")";
    } else if(term->term_type = FUNCTION::fsin) {
        return "(" + to_string(coeff) + ")" + "sin(x)^" + "(" + to_string(pow) + ")(-cos(x))";
    } else if(term->term_type = FUNCTION::fcos) {
        return "(" + to_string(coeff) + ")" + "cos(x)^" + "(" + to_string(pow) + ")(sin(x))";
    }
}