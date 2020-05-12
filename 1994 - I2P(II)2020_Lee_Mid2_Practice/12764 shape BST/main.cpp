#include <iostream>
#include "function.h"

using namespace oj;

int main()
{
    freopen("input.txt","r",stdin);
    int n, i;
    std::string s;

    BST tree;

    std::cin >> n;
    getline(std::cin, s);
    for (i=0; i<n; i++){
        getline(std::cin, s);
        tree.insertNode(s);
    }

    tree.print();
    return 0;
}
