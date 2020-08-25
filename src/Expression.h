#include <memory>

enum FUNCTION { fx, fsin, fcos };

struct TERM {
  float coeff;
  FUNCTION term_type;
  float power;
};

class Expression {
public:
  Expression(TERM[] terms);
  Expression(TERM[] terms, char[] oprs);
  TERM[] getTerms();
  char[] getOperators();

private:
  unsigned int numberOfTerms_;
  std::unique_ptr<TERM[]> terms_;
};