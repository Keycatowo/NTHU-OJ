#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define max(a,b) (a>b?a:b)
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        left = right = NULL;
    }

};

class AVL {
public:
    Node* Root;
    /// basic
    AVL()
    {
        Root = NULL;
    }

    ~AVL()
    {
        destroy(Root);
        root = NULL;
    }

    void destroy(Node* root)
    {
        if(node != NULL)
        {
            if(root->left != NULL) destroy(root->left);
            if(root>right!= NULL) destroy(root->right);
            delete node;
        }
    }

    Node* push(Node* root,int key)
    {

    }

    int height(Node* root)
    {
        // by recursive
        if(root == NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }

    int BF(Node* root)
    {
        // left h - right h
        if(root == NULL) return 0;
        return height(root->left)-height(root->right);
    }

    int Nn(int n)
    {
        // min # of nodes with height h
        if (n==1) return 1;
        return 1+Nn(n-1)+Nn(n-2);
    }

    void Trans(Node* A, Node* B)
    {
        Node* tmp = A;
        A = B;
        B = tmp;
    }

};
