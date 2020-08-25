#ifndef CONSTANTS_H
#define CONSTANTS_H

enum FUNCTION { fx, fsin, fcos };

struct TERM {
  float coeff;
  FUNCTION term_type;
  float power;
};

#endif