#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX_SIZE 26
using namespace std;

char I2C(int i){
    return (char)(i+'a');
}
class Node{
public:
    Node* children[MAX_SIZE];
    int succ[MAX_SIZE];
    bool is_word;

    Node()
    {
        for(int i=0; i<MAX_SIZE; i++)
            children[i] = NULL;
        is_word = false;
    }

};

void Insert(string S, Node* root)
{
    Node* tmp = root;
    for(int i=0; i<S.size(); i++)
    {
        if(tmp->children[S[i]-'a'] != NULL)
            tmp = tmp->children[S[i]-'a'];
        else
        {
            Node* create = new Node();
            tmp->children[S[i]-'a'] = create;
            tmp = tmp->children[S[i]-'a'];
        }
    }
    tmp->is_word = true;
}

void opt(Node* node){
    int sum=0;
    for(int j=0;j<26;j++){
        if(node->children[j]!=NULL)
        {
            node->succ[sum] = j;
            sum++;
        }
    }
    node->succ[sum] = MAX_SIZE;
    for(int j=0;j<sum;j++){
        opt( node->children[node->succ[j]]);
    }
}
void DFS(Node* node, string S){
    if(node->is_word)
        cout<<S<<"\n";
    for(int i=0; i<MAX_SIZE; i++)
    {
        if(node->succ[i]<MAX_SIZE)
            DFS(node->children[node->succ[i]],S+I2C(node->succ[i]));
        else break;
    }
}

void Find_pre(Node* root, string s){
    Node* tmp = root;
    bool check = true;
    for(int i=0;i<s.size();i++)
    {
        if(tmp->children[s[i]-'a'] != NULL)
            tmp = tmp->children[s[i]-'a'];
        else
        {
            check = false;
            break;
        }
    }
    if(check) DFS(tmp,s);
    else cout<<"No match\n";
}

int main(){
    freopen("sample.txt","r",stdin);
    string s;
    int n,q;
    Node* root = new Node();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        Insert(s,root);
    }
    opt(root);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>s;
        Find_pre(root,s);
    }
    return 0;
}
