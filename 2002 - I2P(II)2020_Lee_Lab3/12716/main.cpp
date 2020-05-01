#include <cstdio>
#include <cstring>
#include "function.h"
using namespace oj;

int main() {
  freopen("input.txt","r",stdin);
  static char s[1024];

  int T;
  std::scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    BigOdd B(s);

    int Q;
    std::scanf("%d", &Q);

    while (Q--) {
      char op[5];
      scanf("%s", op);
      if (!strcmp(op, "++B")) std::printf("%s\n", (++B).to_s());
      if (!strcmp(op, "B++")) std::printf("%s\n", (B++).to_s());
    }
  }

  return 0;
}
