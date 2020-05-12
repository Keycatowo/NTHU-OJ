#include <bits/stdc++.h>
#include "function.h"


namespace oj{

class Circle : public Shape{
public:
  Circle(double arg[]){
    setArea(arg);
  }

  void setArea(double arg[]) override{
    if (arg[0]<0 || arg[1]<0)
      area = 0;
    else
      area = arg[0]*arg[0]*arg[1];
  }

  void print() override{
    using namespace std;
    cout<<"Circle("<<fixed<<setprecision(2)<<area<<")\n";
  }
};

class Square : public Shape{
public:
  Square(double arg[]){
    setArea(arg);
  }

  void setArea(double arg[]) override{
    if (arg[0]<0)
      area = 0;
    else
      area = arg[0] * arg[0];
  }

  void print() override{
    using namespace std;
    cout<<"Square("<<fixed<<setprecision(2)<<area<<")\n";
  }
};




void BST::insertNode(std::string& line){
  using namespace std;
  stringstream ss;
  ss<<line;
  string shape_name;
  ss>>shape_name;

  Node* new_node = new Node;
  double arg[2];
  if(shape_name=="Circle"){
    ss>>arg[0]>>arg[1];
    new_node->data = new Circle(arg);
  }
  else{
    ss>>arg[0];
    new_node->data = new Square(arg);
  }

  if (root == nullptr){
    root = new_node;
  }
  else{

    Node** cur = &root;
    while(*cur!=nullptr){
      if (new_node->data->getArea() < (*cur)->data->getArea())
        cur = & (*cur)->left;
      else if(new_node->data->getArea() > (*cur)->data->getArea())
        cur = & (*cur)->right;
      else
        return;
    }
    *cur = new_node;

  }
}


} // namespace oj
