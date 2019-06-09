#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int T,n;
int C;

int max(int a,int b)
{
    return (a>b)?a:b;
}


class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return(node);
}


Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}


Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;


    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{

    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),
                        height(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void level_order(Node *root)
{
    queue<Node*> Q;
    Q.push(root);


    Node* cur = Q.front();
    Q.pop();
    cout<<cur->key;
    if(cur->left  !=NULL) Q.push(cur->left );
    if(cur->right !=NULL) Q.push(cur->right);

    while(!Q.empty())
    {
        Node* cur = Q.front();
        Q.pop();

        cout<<" "<<cur->key;

        if(cur->left  !=NULL) Q.push(cur->left );
        if(cur->right !=NULL) Q.push(cur->right);
    }
}

int main()
{
    int k;
    cin>>T;
    while(T--)
    {
        Node* root = NULL;
        cin>>n;
        while(n--)
        {
            cin>>k;
            root = insert(root,k);
        }
        C = n;
        level_order(root);
        cout<<"\n";
    }

//    Node *root = NULL;
//
//
//    root = insert(root, 2);
//    root = insert(root, 6);
//    root = insert(root, 1);
//    root = insert(root, 7);
//    root = insert(root, 4);
//    root = insert(root, 3);
//    root = insert(root, 5);
//
//    level_order(root);

    return 0;
}

