/*
 - constructor takes as input a string argument or a file
 - it parses the expression to the complete mathematical expressions.
*/

#include "Expression.h"
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

class Parser {
public:
  Parser(std::ifstream filestream);
  Parser(string expr);
  Expression generateExpression();
private:
  vector<TERM> terms_;
  vector<char> oprs_;
  TERM decompose_term(string term);
};