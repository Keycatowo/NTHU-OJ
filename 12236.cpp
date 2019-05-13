#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int I[100];
int D[100];
int leng=0;
int O[100];
int max_lev=0;

class Node{
public:
    int Key;
    int level;
    Node* Left;
    Node* Right;

    Node(int Key)
    {
        this->Key = Key;
        level =0;
        Left = Right = NULL;
    }
};


void level_minus(Node* root)
{
    if(root!=NULL)
    {
        root->level-=1;

        level_minus(root->Left);
        level_minus(root->Right);
    }
}
void push(Node* now, int ins)
{
//    if(now=NULL)       // empty tree
//    {
//        now = new Node(ins);
//    }
//    else
//    {
//        if(ins == now->Key) return;
//        if(ins >  now->Key) return push(now->Right, ins);
//        if(ins <  now->Key) return push(now->Left , ins);
//    }
    if(ins == now->Key) return;

    if(ins >  now->Key)
    {
        if(now->Right == NULL)
        {
            now->Right = new Node(ins);
            now->Right->level = now->level+1;
        }

        else
            push(now->Right,ins);
    }

    if(ins < now->Key)
    {
        if(now->Left == NULL)
        {
            now->Left = new Node(ins);
            now->Left->level = now->level+1;
        }

        else
            push(now->Left,ins);
    }
}

Node* pop(Node* now, int del)
{
    if(now == NULL)
    {
        return NULL;
    }
    else
    {
        // not equal ,go left or right
        if(del < now->Key) return now->Left = pop(now->Left, del);
        if(del > now->Key) return now->Right= pop(now->Right,del);

        if(del == now->Key)
        {
            leng--;
            /// case 1: not child
            if(now->Left==NULL && now->Right==NULL)
            {
                delete now;
                return NULL;
            }

            /// case 2: only one child
            if(now->Right==NULL)
            {
                Node* temp = now;
                delete temp;
                level_minus(now->Left);
                return now->Left;
            }
            if(now->Left == NULL)
            {
                Node* temp = now;
                delete temp;
                level_minus(now->Right);
                return now->Right;
            }

            /// case 3: two child
            int right_side_min;
            for(Node* cur = now->Right; cur!=NULL; cur = cur->Left)
            {
                right_side_min = cur->Key;
            }
            //cout<<now->Key<<"to"<<right_side_min<<"\n";
            now->Key = right_side_min;
            pop(now->Right,right_side_min);
            return now;
        }
    }

}
void level_order(Node* root,int lev)
{
    //cout<<"!";
    if(root!=NULL)
    {
//        cout<<"in"<<root->Key<<"\n";
        if(root->level == lev)
            cout<<root->Key<<" ";

        level_order(root->Left, lev);
        level_order(root->Right,lev);
    }
}

int main(){
    freopen("12236.txt","r",stdin);
    /// input
    int I_n;
    cin>>I_n;
    for(int i=0;i<I_n;i++)
        cin>>I[i];
    int D_n;
    cin>>D_n;
    for(int i=0;i<D_n;i++)
        cin>>D[i];
    leng = I_n;
    /// insert
    Node* root = new Node(I[0]);
    for(int i=1;i<I_n;i++)
        push(root,I[i]);
    for(int i=0;i<D_n;i++)
        pop(root,D[i]);
    if(leng>0)
    {
        for(int i=0;i<I_n;i++)
        {
            level_order(root,i);
        }
        cout<<"\n";
    }
    else
    {
        cout<<"\n";
    }
//    level_order(root,1);
    cout<<root->Key<<"\n";
    cout<<root->Right->Key<<"\n";
    return 0;
}
