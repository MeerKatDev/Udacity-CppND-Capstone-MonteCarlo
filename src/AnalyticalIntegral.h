#include "Integral.h"
#include <string>

class AnalyticalIntegral : public Integral {
public:
    AnalyticalIntegral(Expression expr);
    std::string calculate();
private:
    float calculateSingleTerm(TERM* term);
};