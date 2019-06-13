#include <iostream>
#include <string>
#define SIGMA 26
using namespace std;

class Node {
public:
    bool isEnd;
    int next[SIGMA];
    Node *ch[SIGMA];

    Node() {
        for(int i=0; i<SIGMA; ++i) {
            next[i] = SIGMA;
            ch[i] = NULL;
        }
        isEnd = false;
    }

    ~Node() {
        for(int i=0; i<SIGMA; ++i)
            if(ch[i]) delete ch[i];
    }

    void buildNext() {
        for(int i=0, j=0; i<SIGMA; ++i) {
            if(ch[i]) {
                next[j++] = i;
                ch[i]->buildNext();
            }
        }
    }
};

class Trie {
public:
    Node *root;

    Trie() { root = new Node(); }
    ~Trie() { delete root; }

    void push(const string &s) {
        Node *cur = root;
        for(int i=0, j; i<s.length(); ++i) {
            j = s[i]-'a';
            if(cur->ch[j] == NULL)
                cur->ch[j] = new Node();
            cur = cur->ch[j];
        }
        cur->isEnd = true;
    }

    void buildNext() {
        root->buildNext();
    }

    void matchPrefix(const string &q) {
        Node *cur = root;
        for(int i=0, j; i<q.length(); ++i) {
            j = q[i]-'a';
            if(cur->ch[j]) {
                cur = cur->ch[j];
            } else {
                cout << "No match\n";
                return;
            }
        }

        string r;
        respond(cur, q, r, 0);
    }

    void respond(Node *node, const string &q, string r, int k) {
        if(node->isEnd)
            cout << q << r.substr(0, k) << '\n';

        for(int i=0; node->next[i]<SIGMA; ++i) {
            if(k < r.length()) {
                r[k] = 'a'+node->next[i];
            } else {
                r += 'a'+node->next[i];
            }
            respond(node->ch[node->next[i]], q, r, k+1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, Q;
    string s, q, r;
    Trie *T = new Trie();

    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> s;
        T->push(s);
    }

    T->buildNext();

    cin >> Q;
    for(int i=0; i<Q; ++i) {
        cin >> q;
        T->matchPrefix(q);
    }

    delete T;

    return 0;
}
