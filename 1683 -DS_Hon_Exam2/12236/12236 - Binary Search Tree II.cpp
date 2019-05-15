#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int I[100],D[100];
int L;
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
void Insert(node* root,int InsertData);
node* Search_BST(node* root,int what);
void preorder(node *root);
node* FindMin(node *root);
node* Del(node* root,int target);
void level_order(node *root);


int main() { _

    //freopen("sample input.txt","r",stdin);
    /// input
    int to_insert_length,to_delete_length;
    cin>>to_insert_length;
    for(int i=0;i<to_insert_length;i++)
        cin>>I[i];
    cin>>to_delete_length;
    for(int i=0;i<to_delete_length;i++)
        cin>>D[i];
    L=to_insert_length;

    /// Build
    node* root =new node(I[0]);
    for(int i=1;i<to_insert_length;i++)
        Insert(root,I[i]);
    /// Delete
    for(int i=0;i<to_delete_length;i++)
        Del(root,D[i]);
    /// Show
    if(L==0) cout<<"\n";
    else
    {
        level_order(root);
        cout<<"\n";
    }

	return 0;
}

void Insert(node* root,int InsertData)
{
    /* Already exist, do nothing. */
    if(InsertData==root->data) return;

    if(InsertData>root->data)// bigger, go right
        if(root->right==NULL)// is leaf, add directly
            root->right = new node(InsertData);
        else// not leaf, go through.
            Insert(root->right,InsertData);
    else
        if(root->left==NULL)
            root->left  = new node(InsertData);
        else
            Insert(root->left,InsertData);

}
node* Search_BST(node* root,int what)
{
    if(what == root->data) return root;
    if(what >  root->data)
        if(root->right==NULL)
            return NULL;
        else
            Search_BST(root->right,what);
    else
        if(root->left==NULL)
            return NULL;
        else
            Search_BST(root->left,what);
}
void preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
node* FindMin(node *root)
{
    if(root->left==NULL) return root;
    else return FindMin(root->left);
}
node* Del(node* root,int target)
{
    // no exist ,delete failed.
    if (root==NULL) return root;
    else if(target > root->data) root->right = Del(root->right,target);
    else if(target < root->data) root->left  = Del(root->left ,target);
    else    // Find target.
    {
        L--;
        /// case 1: No child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root =NULL;
            return root;
        }
        /// case 2: One child
        else if(root->left == NULL)
        {
            node* tmp=root;
            root = root->right;
            delete tmp;
            return root;
        }
        else if(root->right == NULL)
        {
            node* tmp=root;
            root = root->left;
            delete tmp;
            return root;
        }
        /// case 3: Two children
        else{
            node* tmp = FindMin(root->right);
            root->data =tmp->data;
            root->right=Del(root->right,tmp->data);
        }
    }
    return root;
}

void level_order(node* root)
{
    queue<node*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        node* cur = Q.front();
        Q.pop();

        cout<<cur->data<<" ";

        if(cur->left  !=NULL) Q.push(cur->left );
        if(cur->right !=NULL) Q.push(cur->right);
    }
}
