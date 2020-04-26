#include <iostream>
#include <cmath>
using namespace std;

#include "function.h"

int main() {
    freopen("input.txt","r",stdin);
    oj::Fib fib;

    int Q;
    cin >> Q;

    while (Q--) {
    int P, A, B;
    cin >> P;
    if (P == 0) {
      cin >> A >> B;
      fib.setBase(A, B);
    } else {
      cin >> A;
      cout << fib[A] << endl;
    }
    }




    return 0;
}
