#include <iostream>
#include <string>
#define DEBU

namespace oj {

    class weakpal {
     private:
      std::string str;
      int dis;

     public:
      ~weakpal(){};

      void setStr(const std::string & _str);
      void setDis();

      inline void print(){std::cout<<str<<'\n';};

      bool operator<( const weakpal & rhs );
    };

    // ----------- Node -------------
    struct Node {
      weakpal* data;
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
      void insertNode(std::string& s);

      void print() { print(root); }
    };
}  // namespace oj
