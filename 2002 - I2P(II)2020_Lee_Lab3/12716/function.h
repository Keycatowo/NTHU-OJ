#ifndef FUNCTION_H
#define FUNCTION_H

namespace oj {
class BigOdd {
  char *_val;
 public:
  BigOdd(char *s);
  ~BigOdd();
  BigOdd& operator++();
  BigOdd operator++(int);
  BigOdd& operator--();
  BigOdd operator--(int);
  char* to_s();
};
}  // namespace oj

#endif
