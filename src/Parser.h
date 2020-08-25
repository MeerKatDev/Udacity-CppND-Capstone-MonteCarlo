/*
 - constructor takes as input a string argument or a file
 - it parses the expression to the complete mathematical expressions.
*/

#include "Expression.h"
#include <string>
#include <fstream>
#include <vector>

class Parser {
public:
  // TODO implement multiple constr
  Parser(std::ifstream filestream);
  Parser(std::string expr);
  Expression generateExpression();
private:
  std::vector<TERM> terms_;
  std::vector<char> oprs_;
  TERM decompose_term(std::string term);
};