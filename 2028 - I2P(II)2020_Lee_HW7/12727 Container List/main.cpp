#include <iostream>
#include <cstdlib>
using namespace std;

#include "function.h"

int main() {
  ios::sync_with_stdio(false); // this will make stdio faster

  int T;
  cin >> T;

  while (T--) {
    oj::list h;

    int N;
    cin >> N;
    while (N--) {
      int P;
      cin >> P;
      if (P == 1) {
        int X, C, V;
        cin >> X >> C >> V;
        h.insert(h.begin() + X, C, V);
      } else {
        int X, Y;
        cin >> X >> Y;
        h.erase(h.begin() + X, h.begin() + Y);
      }
    }

    if (!h.empty()) {
      cout << h.size() << "\n";
      for (oj::iterator it = h.begin(); it != h.end(); ++it) {
        cout << *it << " \n"[it + 1 == h.end()];
      }
    }

    if (rand() & 1) h.clear();
  }

  return 0;
}

