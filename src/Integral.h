/* 
  constructor takes the expression.
  decides whether it will be an analytical or numerical calculation

*/
#include "Expression.h"

template<typename T>
class Integral {
public:
  Integral(Expression expr);
  virtual T calculate() = 0;

private:
  virtual T calculateSingleTerm(TERM* term) = 0;

protected:
  Expression expression;

};
