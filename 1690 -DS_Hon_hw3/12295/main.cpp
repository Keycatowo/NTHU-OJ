#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX_SIZE 26
using namespace std;

class Node{
public:
    bool is_word;
    int next[MAX_SIZE];
    Node *Ch[MAX_SIZE];

    Node(){
        memset(next,MAX_SIZE,MAX_SIZE);
//        memset(*Ch,MAX_SIZE,NULL);
        for(int i=0; i<MAX_SIZE; i++)
            Ch[i] = NULL;
        is_word = false;
    }

    ~Node(){
        for(int i=0; i<MAX_SIZE; i++)
            if(Ch[i]) delete Ch[i];
    }

    void build_next(){
        for(int i=0,j=0; i<MAX_SIZE; i++){
            if(Ch[i]){
                next[j++] = i;
                Ch[i]->build_next();
            }
        }
    }
};

class Trie{
public:
    Node *Root;

    Trie(){
        Root = new Node();
    }
    ~Trie(){
        delete Root;
    }
    void push(const string &s){
        Node *cur = Root;
        for(int i=0,index; i<s.length() ;i++)
        {
            index = s[i] - 'a';
            if(cur->Ch[index] == NULL)
                cur->Ch[index] = new Node();
            cur = cur->Ch[index];
        }
        cur->is_word = true;
    }
    bool match_prefix(const string &q){
        Node *cur =Root;
        for(int i=0,index; i<q.length(); i++)
        {
            index = q[i] - 'a' ;
            if(cur->Ch[index] == NULL)
                return false;
            else
                cur = cur->Ch[index];
        }
        string r;
        respond(cur, q, r, 0);
        return true;
    }
    void respond(Node *cur, const string &q, string r,int k){
        if(cur->is_word)
            cout<< q << r.substr(0,k) << '\n';

        for(int i=0; cur->next[i]<MAX_SIZE; i++){
            if(k < r.length())
                r[k] = 'a' + cur->next[i];
            else
                r += 'a' + cur->next[i];
            respond(cur->Ch[cur->next[i]], q, r, k+1);
        }
    }

};


int main(){
    freopen("sample.txt","r",stdin);

    int n,q;
    string S1,S2;
    Trie *T = new Trie();

    cin>>n;
    while(n--){
        cin>>S1;
        T->push(S1);
    }

    T->Root->build_next();

    cin>>q;
    while(q--){
        cin>>S2;
        if(!T->match_prefix(S2))
            cout<<"No match\n";
    }

    delete T;

    return 0;
}
