#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Constants.h"
#include <memory>

class Expression {
public:
  Expression(TERM terms[]);
  Expression(TERM terms[], char oprs[]);
  TERM* getTerms();
  char* getOperators();

private:
  unsigned int numberOfTerms_;
  std::unique_ptr<TERM[]> terms_;
};

#endif