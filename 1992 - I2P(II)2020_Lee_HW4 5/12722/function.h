#include <cstdint>
namespace oj {
  class Fib {
   private:
    int a0;
    int a1;
   public:
    Fib() {}
    void setBase(int, int);
    int64_t operator[](int);
  };
};

