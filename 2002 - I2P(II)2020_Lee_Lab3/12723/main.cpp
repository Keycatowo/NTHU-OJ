#include <iostream>
using namespace std;

#include "function.h"

int main() {
  freopen("input.txt","r",stdin);
  oj::BST bst;

  int Q;
  cin >> Q;

  while (Q--) {
    int P, V;
    cin >> P;

    if (P == 0) {
      cin >> V;
      bst.insert(V);
    } else {
      cout << bst.inorder() << endl;
    }
  }

  return 0;
}
