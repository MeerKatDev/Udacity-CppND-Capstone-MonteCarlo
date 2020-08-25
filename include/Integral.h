#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "Constants.h"
#include <vector>

using std::vector;

template<typename T>
class Integral {
public:
  virtual ~Integral() {}
  virtual T calculate() = 0;

private:
  virtual T calculateSingleTerm(TERM* term) = 0;

protected:
  Integral(const vector<TERM>& terms, const vector<char>& oprs) : terms_(terms), oprs_(oprs) { } 
  const vector<TERM> terms_;
  const vector<char> oprs_;
};

#endif