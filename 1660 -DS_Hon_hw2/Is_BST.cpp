#include <bits/stdc++.h>
#include <cstdbool>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MIN INT_MIN
#define MAX INT_MAX



using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right= NULL;
    }
};

bool is_BST(node*);
bool BST_property(node*,int,int);



int main() { _
    node *root  = new node(4);
    root->left  = new node(2);
    root->right = new node(5);
    root->left->left    = new node(1);
    root->left->right   = new node(4);

    if(is_BST(root))
        cout<<"yes";
    else
        cout<<"no";

	return 0;
}

bool is_BST(node* node)
{
    /**用遞迴方式判斷**/
    /*先從root和無限大及無限小開始*/
    return BST_property(node,MIN,MAX);
}

bool BST_property(node* node,int Min,int Max)
{
    /*empty tree is BST*/
    if(node==NULL) return true;
    /*left<node.data<right for BST*/
    if(node->data >Max) return false;
    if(node->data <Min) return false;
    /*go left and right subtree*/
    return
        BST_property(node->left,Min,(node->data)-1)
        &&
        BST_property(node->right,(node->data)+1,Max);
}



