#include <bits/stdc++.h>
#include "function.h"
using namespace std;

vector <int> tree;

namespace oj{

BST::BST(){
}

BST::~BST(){
}

void BST::insert(int val){
  tree.push_back(val);
}

string BST::inorder(){
  sort(tree.begin(),tree.end());
  string S="";
  for(auto i=0;i<tree.size();i++){
    S += to_string(tree[i]);
    if (i!=tree.size()-1)
      S += " ";
  }
  return S;
}

}

