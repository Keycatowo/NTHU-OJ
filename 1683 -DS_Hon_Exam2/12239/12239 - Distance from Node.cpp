#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 65536
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

bool is_root[MAX];

class Node{
public:
    int NodeData;
    Node* left;
    Node* right;

    Node(int NodeData)
    {
        this->NodeData = NodeData;
        left  = NULL;
        right = NULL;
    }

//    ~Node()
//    {
//        left = right = NULL;
//    }

};

class List{
public:
    Node* head;
    Node* tail;

    List()
    {
        head=tail=NULL;
    }

    ~List()
    {
        Node* temp;
        while(head!=NULL){
            temp = head;
            head = head->right;
            delete temp;
        }
        head = tail = NULL;
    }

    bool empty()
    {
        if(head==NULL) return true;
            else return false;
    }

    int size()
    {
        int s=0;
        if(empty()) return 0;
        else
            for(Node* cur = head; cur != NULL; cur = cur->right)
                s++;
        return s;
    }

    void push_back(int NodeData)
    {
        if(empty())
        {
            head = new Node(NodeData);
            tail = head;
        }
        else
        {
            tail->right = new Node(NodeData);   // let now tail point right to new node
            tail->right->left = tail;           // let new node point left to now last
            tail = tail->right;                  // update tail by new node
        }
    }

    int pop_front()
    {
        Node* temp = head;                      // we care about the head of List
        int data = head->NodeData;

        if(head==tail)                          // when List length is 1
        {
            head = tail = NULL;
            delete temp;
        }
        else
        {
            head = head->right;
            delete temp;
        }

        return data;
    }
};

class Graph{
public:
    int NodeNumbers;
    List* neighbors;
    bool* visited;
    int*  steps;
    int*  d_sum;
//    int max_step;
//    int max_step_min_index;
    int root_index;
    int max_distance;
    int max_distance_index;

    Graph(int NodeNumbers)
    {
        this->NodeNumbers = NodeNumbers;
        neighbors = new List[NodeNumbers];
        visited   = new bool[NodeNumbers];
        d_sum     = new int [NodeNumbers];
        steps     = new int [NodeNumbers];
//        max_step  = 0;
//        max_step_min_index = MAX ;
        max_distance =0;
        max_distance_index = MAX;
    }

    ~Graph()
    {
        delete [] neighbors;
        delete [] visited;
        delete [] d_sum;
        delete [] steps;
    }

    void reset_visited()
    {
        for(int i=0; i<NodeNumbers; i++)
            visited[i] = false;
    }

    void push(int Node_u,int Node_v)
    {
        neighbors[Node_u].push_back(Node_v);
        neighbors[Node_v].push_back(Node_u);
    }



    int min_leaf_distance(int Source)
    {
        if(!visited[Source]) visited[Source] = true;    // visit it

        if(neighbors[Source].size()<=1)                         // size 0 is all graph one node,size 1 is leaf because only has father
            return 0;                                   // to leaf(itself) is distance 0

        int d,minD = MAX;
        for(Node* cur = neighbors[Source].head; cur != NULL; cur = cur->right)
        {
            if(visited[cur->NodeData])
            {
                // has visited , do nothing
            }
            else
            {
                d = min_leaf_distance(cur->NodeData);
                minD = min(d,minD);
            }
        }
        return (1+minD);
    }

    int max_leaf_distance(int Source, int index)
    {
        if(!visited[index]) visited[index] = true;

        if(neighbors[index].empty() || (neighbors[index].size()==1 && Source!=index) ) return 0;

        int d,maxD = 0;
        for(Node* cur = neighbors[index].head; cur != NULL; cur = cur->right)
        {
            if(!visited[cur->NodeData])
            {
                d = max_leaf_distance(Source,cur->NodeData);
                maxD = max(d,maxD);
            }
        }
        return (1+maxD);
    }

    void getDs(int Source)
    {
        queue<int> Q;
        Q.push(Source);
        visited[Source] = true;
        steps[Source] = 0;
        d_sum[Source] = 0;
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
//    cout<<"cur at"<<cur<<endl;
            for(Node* nei = neighbors[cur].head; nei!=NULL; nei=nei->right)
            {
                if(!visited[nei->NodeData])
                {
//    cout<<"visit "<<nei->NodeData<<endl;
                    visited[nei->NodeData] = true;
                    Q.push(nei->NodeData);
                    steps[nei->NodeData] = steps[cur] + 1;
                    d_sum[nei->NodeData] = d_sum[cur] + max(cur,nei->NodeData);
                    /// update
                    if(neighbors[nei->NodeData].head == neighbors[nei->NodeData].tail && nei->NodeData!=root_index)
                    {
                        if(d_sum[nei->NodeData] > max_distance)
                        {
//                            max_step = steps[nei->NodeData];
//                            max_step_min_index = nei->NodeData;
                            max_distance = d_sum[nei->NodeData];
                            max_distance_index = nei->NodeData;
                        }
                        else if(d_sum[nei->NodeData]  == max_distance && nei->NodeData < max_distance_index)
                        {
//                            max_step_min_index = nei->NodeData;
                            max_distance_index = nei->NodeData;
                        }
                    }
                }
            }

        }
        if(max_distance_index != MAX )
        {
//            cout<<max_step<<" "<<max_step_min_index<<" ";
            cout<<d_sum[max_distance_index]<<"\n";
        }
        else
        {
            cout<<0<<"\n";
        }

//        for(int i=0; i<NodeNumbers; i++)
//        {
////            cout<<i<<" "<<steps[i]<<" "<<d_sum[i]<<"\n";
//            if(steps[i] == Distance)
//                return d_sum[i];
//        }
    }

};



int main(){_

    /// input

    //freopen("sample input.txt","r",stdin);
        // line 1
    int N; cin >> N;

    Graph* KT = new Graph(N);
        // N lines

    for(int i=0; i<N; i++)
        is_root[i] = true;

    for(int u,v,i=0; i < N-1; i++)
    {
        cin>> u >> v;
        is_root[v] =false;
        KT->push(u,v);
    }

    int root;
    for(int i=0; i<N; i++)
        if(is_root[i]) root =i;
    KT->root_index = root;
        // last line
    int B;cin >> B;
//    cout<<"end input\n";
    /// process
//    KT->reset_visited();
//    int dBC = KT->min_leaf_distance(B);
//    KT->reset_visited();
//    int dBF = KT->max_leaf_distance(B,B);
//    cout<<dBF;
    KT->reset_visited();
    KT->getDs(B);

    delete KT;

    return 0;


}
