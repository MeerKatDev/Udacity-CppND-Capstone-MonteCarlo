#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "Expression.h"
#include <memory>

template<typename T>
class Integral {
public:
  virtual T calculate() = 0;
  virtual ~Integral() {}

private:
  virtual T calculateSingleTerm(TERM* term) = 0;

protected:
  Integral(Expression& e) : expression(std::move(e)) { } 
  Expression expression;
};

#endif