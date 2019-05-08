#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;

    Node(int key) {
        this->key = key;
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
        root = NULL;
    }

    void destroy(Node *node) {
        if(node != NULL) {
            if(node->left != NULL) destroy(node->left);
            if(node->right != NULL) destroy(node->right);
            delete node;
        }
    }

    Node* push(Node *node, int key) {
        if(node == NULL) {
            return new Node(key);
        } else {
            if(key < node->key) {
                node->left = push(node->left, key);
            } else if(key > node->key) {
                node->right = push(node->right, key);
            }
            return node;
        }
    }

    Node* pop(Node *node, int key) {
        Node *returnNode = NULL;

        if(node != NULL) {
            if(key < node->key) {
                node->left = pop(node->left, key);
                returnNode = node;
            } else if(key > node->key) {
                node->right = pop(node->right, key);
                returnNode = node;
            } else {
                if(node->left != NULL && node->right != NULL) {
                    Node *succ;
                    for(succ = node->right; succ->left != NULL; succ = succ->left);
                    node->key = succ->key;
                    node->right = pop(node->right, succ->key);
                    returnNode = node;
                } else {
                    if(node->left != NULL)
                        returnNode = node->left;
                    if(node->right != NULL)
                        returnNode = node->right;
                    delete node;
                }
            }
        }

        return returnNode;
    }

    void preorder() {
        pre(root);
        cout << '\n';
    }

    void pre(Node *node) {
        if(node != NULL) {
            cout << node->key << ' ';
            if(node->left != NULL) pre(node->left);
            if(node->right != NULL) pre(node->right);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    BST *T = new BST();

    int I;
    cin >> I;
    for(int i=0, key; i<I; ++i) {
        cin >> key;
        T->root = T->push(T->root, key);
    }

    int D;
    cin >> D;
    for(int i=0, key; i<D; ++i) {
       cin >> key;
       T->root = T->pop(T->root, key);
    }

    T->preorder();

    delete T;

    return 0;
}
