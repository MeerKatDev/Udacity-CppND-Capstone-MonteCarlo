#include "Integral.h"
#include <string>

using std::string;
using std::to_string;

class AnalyticalIntegral : public Integral {
public:
    AnalyticalIntegral(Expression expr);
    string calculate();
private:
    float calculateSingleTerm(TERM* term);
};