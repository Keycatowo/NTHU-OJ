#include <string>
using namespace std;

namespace oj {
struct Node {
  int val;
  int cnt; // how many times has this value appeared
  Node *lc; // left child
  Node *rc; // right child
  Node(int v) : val(v), cnt(1), lc(nullptr), rc(nullptr) {} // init to null when created
};

class BST {
 private:
  Node *root;
  
 public:
  BST(); // constructor, does what needs to be done when created
  ~BST();  // destructor, doest what needs to be done when destroyed
  void insert(int);
  string inorder(); 
};
};  // namespace oj

