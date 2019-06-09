#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ALPHABET_SIZE 26
using namespace std;
char S[256][8];
int N,Q;

typedef struct trie_node
{
    int count;
    trie_node *children[ALPHABET_SIZE];
}*trie;

trie_node* create_trie_node()
{
    trie_node* pNode = new trie_node();
    pNode->count = 0;
    for(int i=0; i<ALPHABET_SIZE; ++i)
        pNode->children[i] = NULL;
    return pNode;
}

void trie_insert(trie root, char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p)
    {
        if(node->children[*p-'a'] == NULL)
        {
            node->children[*p-'a'] = create_trie_node();
        }
        node = node->children[*p-'a'];
        ++p;
    }
    node->count += 1;
}


int trie_search(trie root, char* key)
{

    trie_node* node = root;
    char* p = key;
    while(*p && node!=NULL)
    {
        node = node->children[*p-'a'];
        ++p;
    }

    if(node == NULL)
        return 0;
    else
        return node->count;
}

void show(trie root)
{
    trie_node* node = root;
    if(node == NULL) return;
    if(node->count>0)
        cout<<"yes\n";
    if(node)
    {
        for(int i=0;i<ALPHABET_SIZE;i++)
            show(node->children[i]);
    }
}

void find_all(trie root,char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p && node!=NULL)
    {
        node = node->children[*p-'a'];
        ++p;
    }
    if(node == NULL)
        cout<<"no match\n";
    else
        show(node);
}

int main()
{
    freopen("sample.txt","r",stdin);

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>S[i];

    trie root = create_trie_node();
    for(int i = 0; i < N; i++)
        trie_insert(root, S[i]);

    cin>>Q;
    char qi[8];
    for(int i=0;i<Q;i++)
    {
        cin>>qi;
        find_all(root,qi);
    }

    return 0;
}
