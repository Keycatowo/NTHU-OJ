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
    AVL(){
        Root = NULL;
    }
    ~AVL(){
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
        return new_root;
    }
    Node* R_rotate(Node *cur){
        Node *new_root = cur->left;
        cur->left      = new_root->right;
        new_root->right= cur;
        return new_root;
    }
    Node* LR_rotate(Node *cur){
        cur->left =  L_rotate(cur->left);
        cur = R_rotate(cur);
        return cur;
    }
    Node* RL_rotate(Node *cur){
        cur->right= R_rotate(cur->right);
        cur = L_rotate(cur);
        return cur;
    }

    Node* L(Node *target){
        Node *cur = Root;
        // if rotate axis the root
        if(cur == target)
            return Root = L_rotate(target);
        // if not in the root
        while(1)
        {
            /// in the next level
            if(cur->right == target)
                return cur->right = L_rotate(target);
            if(cur->left == target)
                return cur->left = L_rotate(target);

            /// if not in the next level, go down
            if(target->key > cur->key)
                cur = cur->right;
            else if (target->key < cur->key)
                cur = cur->left;
        }

    }
    Node* R(Node *target){
        Node *cur = Root;
        // if rotate axis the root
        if(cur == target)
            return Root = R_rotate(target);
        // if not in the root
        while(1)
        {
            /// in the next level
            if(cur->right == target)
                return cur->right = R_rotate(target);
            if(cur->left == target)
                return cur->left = R_rotate(target);

            /// if not in the next level, go down
            if(target->key > cur->key)
                cur = cur->right;
            else if (target->key < cur->key)
                cur = cur->left;
        }

    }
    Node* LR(Node *target){
        Node *cur = Root;
        // if rotate axis the root
        if(cur == target)
            return Root = LR_rotate(target);
        while(1){
            /// in the next level
            if(cur->right == target)
                return cur->right = LR_rotate(target);
            if(cur->left  == target)
                return cur->left  = LR_rotate(target);
            /// if not in the next level, go down
            if(target->key > cur->key)
                cur = cur->right;
            else if (target->key < cur->key)
                cur = cur->left;
        }
    }
    Node* RL(Node *target){
        Node *cur = Root;
            // if rotate axis the root
            if(cur == target)
                return Root = RL_rotate(target);
            while(1){
                /// in the next level
                if(cur->right == target)
                    return cur->right = RL_rotate(target);
                if(cur->left  == target)
                    return cur->left  = RL_rotate(target);
                /// if not in the next level, go down
                if(target->key > cur->key)
                    cur = cur->right;
                else if (target->key < cur->key)
                    cur = cur->left;
            }
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

int main(){ _
    freopen("sample.txt","r",stdin);
    int T,n,mode,x;
    cin>>T;
    Node* tmp;
    while(T--){
        cin>>n;
        AVL *avl= new AVL();
        while(n--){
            cin>>mode>>x;
            switch (mode)
            {
                case 0:
                    avl->Insert(x);
                    break;
                case 1:
                    tmp = avl->Search(x);
                    avl->L(tmp);
                    break;
                case 2:
                    tmp = avl->Search(x);
                    avl->R(tmp);
                    break;
                case 3:
                    tmp = avl->Search(x);
                    avl->LR(tmp);
                    break;
                case 4:
                    tmp = avl->Search(x);
                    avl->RL(tmp);
                    break;
            }

        }
        avl->level_order();
        delete avl;
    }
    return 0;
}
