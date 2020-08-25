#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Constants.h"
#include <vector>

class Expression {
public:
  Expression(TERM& terms);
  Expression(TERM& terms, char& oprs);
  TERM* getTerms();
  char* getOperators();

private:
  unsigned int numberOfTerms_;
  TERM* terms_;
  char* oprs_;
};

#endif