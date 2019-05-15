#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 1000;
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
int M[1000];

void init_M(){
    for(int i=0; i<1000;i++)
        M[i]=0;
}

class Node{
public:
    int index;
    Node* next;
    Node* prev;

    Node(int index)
    {
        this->index = index;
        prev = next = NULL;
    }

};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    ~List() {
        Node* temp;
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
            head = tail = new Node(index);
        } else {
            tail->next = new Node(index);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    int pop_front() {
        Node* temp = head;
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


class Graph{
public:
    int V;  // nodes
    List* pre_neighbors;
    List* next_neighbors;
    bool* visited;

    Graph(int V){
        this->V = V;
        pre_neighbors = new List[V];
        next_neighbors= new List[V];
        visited = new bool[V];
        reset_visited();
    }

    ~Graph(){
        delete [] pre_neighbors;
        delete [] next_neighbors;
        delete [] visited;
    }

    void reset_visited(){
        for(int i=0; i<V; i++)
            visited[i] = false;
    }

    void push(int from,int to){
        pre_neighbors[to].push_back(from);
        next_neighbors[from].push_back(to);
    }

    bool mix(Node* target){
        if(!pre_neighbors[target->index].empty())
        {
            int sum=0;
            for(Node* cur = pre_neighbors[target->index].head; cur!=NULL; cur = cur->next)
            {
                sum += M[cur->index];
                if(!visited[cur->index]) return false;
            }
            if(sum > 1000000) sum = 1000000;
            target->magic = sum;
            visited[target->index] = true;
            M[target->index] = sum;
            return true;
        }
        else
        {
            target->magic = 1;
            visited[target->index] = true;
            M[target->index] =1;
            return true;
        }
    }

    int spend(){
        int spend=0;
        for(int i=0; i<V; i++)
        {
            if(pre_neighbors[i].empty())
            {
                spend++;
            }
        }
        return spend;
    }

    void go(){
        reset_visited();
        queue<Node*> Q;
        Q.push(pre_neighbors[next_neighbors[0].head->index].head); //node 0

        while(!Q.empty())
        {
            Node* now = Q.front();
            Q.pop();

            if(!visited[now->index])
            {
                if(mix(now))
                {

//                    visited[now->index] = true;
                    for(Node* cur = next_neighbors[now->index].head; cur!=NULL; cur=cur->next)
                        if(!visited[cur->index]) Q.push(cur);
                }
                else
                {
                    for(Node* cur = pre_neighbors[now->index].head; cur!=NULL; cur=cur->next)
                        if(!visited[cur->index]) Q.push(cur);
                }
            }

        }

    }

    void show(){
        int sum =0;
        for(int i=0; i<V; i++){
            sum += M[i];
//            cout<<"["<<i<<"]:"<<M[i]<<"\n";
        }
//        cout<<spend()<<"\n";
        sum -= spend();
        cout<<sum<<"\n";
    }
};

void test_case(){
    int V,E;
    cin>>V>>E;
    Graph* G = new Graph(V);
    for(int u,v,i=0; i<E; i++)
    {
        cin>>u>>v;
        G->push(u,v);
    }
    init_M();
    G->go();
    G->show();

    delete G;
}

int main(){_

    int T;
    cin>>T;
    while(T--)
    {
        int V,E;
        cin>>V>>E;
        Graph* G = new Graph(V);
        for(int u,v,i=0; i<E; i++)
        {
            cin>>u>>v;
            G->push(u,v);
        }
        init_M();
        G->go();
        G->show();

        delete G;
    }

    return 0;
}
