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

    Node* L_rotate(Node *cur){
        Node *new_root = cur->right;
        cur->right     = new_root->left;
        new_root->left = cur;
        if(cur == Root)
            Root = new_root;
        return new_root;
    }
    Node* R_rotate(Node *cur){
        Node *new_root = cur->left;
        cur->left      = new_root->right;
        new_root->right= cur;
        if(cur == Root)
            Root = new_root;
        return new_root;
    }
    Node* ins(int x,Node *cur){
        /// recursive insert place
        if(cur == NULL)
            return new Node(x);
        if(x < cur->key)
            cur->left = ins(x,cur->left);
        else
            cur->right = ins(x,cur->right);
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
    Node* Search(int x){
        Node *cur = Root;
        while(cur != NULL)
        {
            if(x == cur->key)
                return cur;
            if(x > cur->key)
                cur = cur->right;
            else
                cur = cur->left;
        }
        return NULL;
    }


};

int main(){
    freopen("sample.txt","r",stdin);
    int T,n,mode,x;
    cin>>T;
    Node* tmp;
    while(T--){
        cin>>n;
        AVL avl= AVL();
        while(n--){
            cin>>mode>>x;
            switch (mode)
            {
                case 0:
                    avl.Insert(x);
                    break;
                case 1:
                    tmp = avl.Search(x);
                    avl.L_rotate(tmp);
                    break;
                case 2:
                    tmp = avl.Search(x);
                    avl.R_rotate(tmp);
                    break;
                case 4:
                    tmp = avl.Search(x);
//                    if(tmp->right != NULL)
                        tmp->right = avl.R_rotate(tmp->right);
                    avl.L_rotate(tmp);
                    break;
                case 3:
                    tmp = avl.Search(x);
//                    if(tmp->left != NULL)
                        tmp->left = avl.L_rotate(tmp->left);
                    avl.R_rotate(tmp);
                    break;
            }

        }
        avl.level_order();
    }
    return 0;
}
