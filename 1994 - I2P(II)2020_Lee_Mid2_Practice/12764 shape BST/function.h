#include <iomanip>  //setprecision會用到的函式庫
#include <iostream>
#include <string>

namespace oj {
// Here have three classes: Shape, Node, and BST

// ----------- Shape-------------
// Shape is an abstract class
class Shape {
 protected:
  double area;

 public:
  virtual ~Shape(){};

  // pure virtual functions
  // set the area
  virtual void setArea(double[]) = 0;

  // print the shape information
  virtual void print() = 0;
  // the output format for each shape should be like
  // Circle(3.14)
  // Square(4.00)
  // use fixed and setprecision(...) with cout to control the format of double

  inline double getArea() const { return area; }
};

// ----------- Node -------------
struct Node {
  Shape* data;
  Node *left, *right;

  Node() : data(nullptr), left(nullptr), right(nullptr) {}
  ~Node() {
    if (data != nullptr) delete data;
  }
};

// ----------- BST -------------
class BST {
 private:
  Node* root;

  // print the tree using in-order
  void print(Node* r) {
    if (r != nullptr) {
      print(r->left);
      r->data->print();
      print(r->right);
    }
  }
  // delete the tree using post-order
  void sanitize(Node* r) {
    if (r != nullptr) {
      sanitize(r->left);
      sanitize(r->right);
      delete r->data;
    }
  }

 public:
  BST() : root(nullptr) {}
  ~BST() { sanitize(root); }

  // your only need to implement insertNode
  void insertNode(std::string&);

  void print() { print(root); }
};
}  // namespace oj
