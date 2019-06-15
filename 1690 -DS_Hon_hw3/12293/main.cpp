#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define max(a,b) (a>b?a:b)
using namespace std;

class Node {
public:
    int key,height;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        height = 1;
        left = right = NULL;
    }

};

class AVL {
public:
    Node* Root;
    char dir[3];
    /// basic
    AVL(){
        Root = NULL;
    }
    ~AVL(){
        dir[0] = dir[1] = dir[2] = '\0';
        destroy(Root);
        Root = NULL;
    }
    void destroy(Node *cur){
        if(cur == NULL) return;
        destroy(cur->left);
        destroy(cur->right);
        delete cur;
    }
    void update_height(Node *cur){
        int L_height = (cur->left==NULL)?  0: cur->left->height;
        int R_height = (cur->right==NULL)? 0: cur->right->height;
        cur->height  = 1+ max(L_height,R_height);
    }
    Node* L_rotate(Node *cur){
        Node *new_root = cur->right;
        cur->right     = new_root->left;
        new_root->left = cur;
        update_height(cur);
        update_height(new_root);
        return new_root;
    }
    Node* R_rotate(Node *cur){
        Node *new_root = cur->left;
        cur->left      = new_root->right;
        new_root->right= cur;
        update_height(cur);
        update_height(new_root);
        return new_root;
    }
    Node* Rot(Node *cur){
        if(dir[0] == 'L' && dir[1] == 'L')
            cur = R_rotate(cur);
        if(dir[0] == 'R' && dir[1] == 'R')
            cur = L_rotate(cur);
        if(dir[0] == 'L' && dir[1] == 'R'){
            cur->left = L_rotate(cur->left);
            cur = R_rotate(cur);
        }
        if(dir[0] == 'R' && dir[1] == 'L'){
            cur->right = R_rotate(cur->right);
            cur = L_rotate(cur);
        }
        return cur;
    }
    Node* ins(int x,Node *cur){
        /// recursive insert place
        if(cur == NULL)
            return new Node(x);
        if(x < cur->key)
            cur->left = ins(x,cur->left);
        else
            cur->right = ins(x,cur->right);

        /// update height
        int L_height = (cur->left==NULL)?  0: cur->left->height;
        int R_height = (cur->right==NULL)? 0: cur->right->height;
        cur->height  = 1+ max(L_height,R_height);

        /// check balance factor
        int BF = L_height - R_height;
        if(BF>1)// left too high
        {
            dir[0] = 'L';
            if(x < cur->left->key)
                dir[1] = 'L';
            else
                dir[1] = 'R';
            return Rot(cur);
        }
        else if(BF<-1)
        {
            dir[0] = 'R';
            if(x > cur->right->key)
                dir[1] = 'R';
            else
                dir[1] = 'L';
            return Rot(cur);
        }
        else    // no rotation
            return cur;

    }
    void Insert(int x){
        Root = ins(x,Root);
    }
    void level_order(){
        queue<Node*> Q;
//        Q.clear();
        if(Root != NULL)
            Q.push(Root);
        while(!Q.empty())
        {
            Node *cur = Q.front();
            Q.pop();

            if(cur->left != NULL) Q.push(cur->left);
            if(cur->right!= NULL) Q.push(cur->right);

            if(!Q.empty())
                cout<<cur->key<<" ";
            else
                cout<<cur->key<<"\n";
        }
    }
    bool Search(int x){
        Node *cur = Root;
        while(cur != NULL)
        {
            if(x == cur->key)
                return true;
            if(x > cur->key)
                cur = cur->right;
            else
                cur = cur->left;
        }
        return false;
    }
    Node* pop(Node* cur,int key){

    }

};

int main(){
    freopen("sample.txt","r",stdin);
    int T,n,a;
    cin>>T;
    while(T--){
        AVL avl;
        cin>>n;
        while(n--){
            cin>>a;
            avl.Insert(a);
        }
        avl.level_order();
    }
    return 0;
}
