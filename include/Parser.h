#include "Expression.h"
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

class Parser {
public:
  Parser(std::ifstream filestream);
  Parser(string expr);
  Parser();
  std::pair<vector<TERM>*, vector<char>*> getExpression();

private:
  vector<TERM> terms_;
  vector<char> oprs_;
  TERM decomposeTerm(string term);
};