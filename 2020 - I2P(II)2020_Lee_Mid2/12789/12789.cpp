#include <bits/stdc++.h>
#include "function.h"




namespace oj{

void weakpal::setStr(const std::string &_str){
  str = _str;
}

void weakpal::setDis(){
  int len = this->str.size();
  dis = 0;
  for (int i=0;i<(len/2);i++){
    if(str[i] != str[len-1-i])
      dis++;
  }

#ifdef DEBUG
std::cout<<"string length is "<<len<<"\n";
std::cout<<"dis is "<<dis<<"\n";
#endif // DEBUG
}

bool weakpal::operator<(const weakpal &rhs){
#ifdef DEBUG
std::cout<<str<<"~"<<rhs.str<<"\n";
std::cout<<dis<<"~"<<rhs.dis<<"\n";
#endif // DEBUG

  if(dis<rhs.dis)
    return true;
  else if (dis > rhs.dis)
    return false;
  else
    return str<rhs.str;
}


void BST::insertNode(std::string &s){
#ifdef DEBUG
std::cout<<"insert["<<s<<"]\n";
#endif // DEBUG

  Node* new_node = new Node();
  new_node->data = new weakpal();
  new_node->data->setStr(s);
  new_node->data->setDis();

  if(root == nullptr)
    root = new_node;

  else{
    Node** cur_adress = &root;
    while((*cur_adress)!=nullptr){
      if((*(*cur_adress)->data) < *(new_node->data))
        cur_adress = & ( (*cur_adress)->right );
      else
        cur_adress = & ( (*cur_adress)->left);
    }
    (*cur_adress) = new_node;
  }
}


}


