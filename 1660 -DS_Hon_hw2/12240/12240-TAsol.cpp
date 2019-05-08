#include <iostream>
using namespace std;

class ListNode {
public:
    int key;
    ListNode *next;

    ListNode(int key) {
        this->key = key;
        next = NULL;
    }
} ;

class List {
public:
    ListNode *head;
    ListNode *tail;

    List() {
        head = tail = NULL;
    }

    ~List() {
        ListNode *temp;
        while(head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = NULL;
    }

    void push_back(int key) {
        if(head == NULL) {
            head = tail = new ListNode(key);
        } else {
            tail = tail->next = new ListNode(key);
        }
    }

    void print() {
        for(ListNode *cur = head; cur != NULL; cur = cur->next)
            cout << cur->key << ((cur->next == NULL)? '\n' : ' ');
    }
};

class Heap {
public:
    int size;
    int *elements;

    Heap(int V) {
        size = 0;
        elements = new int[V];
    }

    ~Heap() {
        delete [] elements;
    }

    bool empty() {
        return size == 0;
    }

    void push(int key) {
        int i = size++, p;
        while(i > 0) {
            p = (i-1) >> 1;
            if(key < elements[p]) {
                elements[i] = elements[p];
                i = p;
            } else break;
        }
        elements[i] = key;
    }

    int pop() {
        int top = elements[0];
        int key = elements[--size];
        int i = 0, L, R;

        while(true) {
            L = (i << 1) + 1;
            R = (i << 1) + 2;
            if(L < size && R < size) {
                if(elements[L] < elements[R] && elements[L] < key) {
                    elements[i] = elements[L];
                    i = L;
                } else if(elements[L] >= elements[R] && elements[R] < key) {
                    elements[i] = elements[R];
                    i = R;
                } else break;
            } else if(L < size) {
                if(elements[L] < key) {
                    elements[i] = elements[L];
                    i = L;
                } break;
            } else break;
        }

        elements[i] = key;
        return top;
    }
};

class Graph {
public:
    int *inDeg;
    List *neighbors;

    Graph(int V) {
        inDeg = new int[V];
        neighbors = new List[V];

        for(int i=0; i<V; ++i)
            inDeg[i] = 0;
    }

    ~Graph() {
        delete [] inDeg;
        delete [] neighbors;
    }

    void push(int u, int v) {
        neighbors[u].push_back(v);
        ++inDeg[v];
    }

    void pop(Heap *H, List *L) {
        int u = H->pop();
        for(ListNode *cur = neighbors[u].head; cur != NULL; cur = cur->next) {
            --inDeg[cur->key];
            if(inDeg[cur->key] == 0)
                H->push(cur->key);
        }
        L->push_back(u);
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int T, V, E;
    Graph *G;
    Heap *H;
    List *L;

    cin >> T;
    while(T--) {
        cin >> V;
        G = new Graph(V);
        H = new Heap(V);
        L = new List();

        cin >> E;
        for(int i=0, u, v; i<E; ++i) {
            cin >> u >> v;
            G->push(u, v);
        }

        for(int i=0; i<V; ++i) {
            if(G->inDeg[i] == 0)
                H->push(i);
        }

        while(!H->empty())
            G->pop(H, L);

        L->print();

        delete G;
        delete H;
        delete L;
    }

    return 0;
}
