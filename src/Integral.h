#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "Expression.h"

template<typename T>
class Integral {
public:
  virtual T calculate() = 0;

private:
  virtual T calculateSingleTerm(TERM* term) = 0;

protected:
  Expression expression;
};

#endif