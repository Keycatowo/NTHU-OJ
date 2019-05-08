#include <iostream>
#define MAX 65536
using namespace std;

class ListNode {
public:
    int index;
    ListNode *prev;
    ListNode *next;

    ListNode(int index) {
        this->index = index;
        prev = next = NULL;
    }
};

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

    bool empty() {
        return head == NULL;
    }

    void push_back(int index) {
        if(empty()) {
            head = tail = new ListNode(index);
        } else {
            tail->next = new ListNode(index);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    int pop_front() {
        ListNode *temp = head;
        int index = head->index;
        if(head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        return index;
    }
};

class Graph {
public:
    int V;
    List *neighbors;
    bool *visited;

    Graph(int V) {
        this->V = V;
        neighbors = new List[V+1];
        visited = new bool[V+1];
        clearVisited();
    }

    ~Graph() {
        delete [] neighbors;
        delete [] visited;
    }

    void clearVisited() {
       for(int i=1; i<=V; ++i)
           visited[i] = false;
    }

    void push(int u, int v) {
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    int getdBC(int index) {
        if(!visited[index])
            visited[index] = true;

        if(neighbors[index].empty() || neighbors[index].head == neighbors[index].tail)
            return 0;

        int d, minD = MAX;
        for(ListNode *cur = neighbors[index].head; cur != NULL; cur = cur->next) {
            if(!visited[cur->index]) {
                d = getdBC(cur->index);
                minD = (d < minD)? d : minD;
            }
        }
        return 1 + minD;
    }

    int getdBF(int B, int index) {
        if(!visited[index])
            visited[index] = true;

        if(neighbors[index].empty() || (neighbors[index].head == neighbors[index].tail && B != index))
            return 0;

        int d, maxD = 0;
        for(ListNode *cur = neighbors[index].head; cur != NULL; cur = cur->next) {
            if(!visited[cur->index]) {
                d = getdBF(B, cur->index);
                maxD = (d > maxD)? d : maxD;
            }
        }
        return 1 + maxD;
    }

    int getMs(int B, int D) {
        List *indexQueue = new List();
        List *dQueue = new List();
        indexQueue->push_back(B);
        dQueue->push_back(0);
        visited[B] = true;

        int sum = 0, prevD = 0, index, d, m = B;
        while(!indexQueue->empty()) {
            index = indexQueue->pop_front();
            d = dQueue->pop_front();

            if(d != prevD) {
                sum += m;
                prevD = d;
                m = index;
            } else {
                m = (index < m)? index : m;
            }

            if(d < D) {
                for(ListNode *cur = neighbors[index].head; cur != NULL; cur = cur->next) {
                    if(!visited[cur->index]) {
                        visited[cur->index] = true;
                        indexQueue->push_back(cur->index);
                        dQueue->push_back(d+1);
                    }
                }
            }
        }
        sum += m;
        delete indexQueue;
        delete dQueue;
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int V;
    cin >> V;

    Graph *KT = new Graph(V);

    for(int i=0, u, v; i<V-1; ++i) {
        cin >> u >> v;
        KT->push(u, v);
    }

    int B;
    cin >> B;

    KT->clearVisited();
    int dBC = KT->getdBC(B);

    KT->clearVisited();
    int dBF = KT->getdBF(B, B);

    KT->clearVisited();
    cout << KT->getMs(B, dBF-dBC) << '\n';

    delete KT;

    return 0;
}
