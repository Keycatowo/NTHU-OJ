#include <iostream>
using namespace std;

class Node {
public:
    unsigned int key;
    Node *next;

    Node(unsigned int key) {
        this->key = key;
        next = NULL;
    }
};

class List {
public:
    Node *head, *tail;

    List() {
        head = tail = NULL;
    }

    ~List() {
        Node *temp;
        while(head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(unsigned int key) {
        if(head) {
            tail = tail->next = new Node(key);
        } else {
            head = tail = new Node(key);
        }
    }

    void print() {
        if(head) {
            Node *cur = head;
            while(cur != tail) {
                cout << cur->key << ' ';
                cur = cur->next;
            }
            cout << cur->key << '\n';
        } else {
            cout << '\n';
        }
    }
};

class Hash {
public:
    unsigned int m, n;
    List *L;

    Hash(unsigned int m, unsigned int n) {
        this->m = m;
        this->n = n;
        L = new List[n];
    }

    ~Hash() {
        delete [] L;
    }

    void push(unsigned int x) {
        unsigned int p = m * x;
        unsigned int k = p % n;
        L[k].push(x);
    }

    void print() {
        for(unsigned int i=0; i<n; ++i)
            L[i].print();
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    unsigned int T, m, n;
    Hash *H;

    cin >> T;
    while(T--) {
        cin >> m >> n;
        H = new Hash(m, n);

        for(unsigned int i=0, x; i<n; ++i) {
            cin >> x;
            H->push(x);
        }

        H->print();

        delete H;
    }

    return 0;
}
