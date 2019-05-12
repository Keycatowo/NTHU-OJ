#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 65536;
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

class Node{
public:
    int NodeData;
    Node* left;
    Node* right;

    Node(int NodeData)
    {
        this->NodeData = NodeData;
        left = right = NULL;
    }

    ~Node()
    {
        left = right = NULL;
    }

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
        while(!head){
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

    Graph(int NodeNumbers)
    {
        this->NodeNumbers = NodeNumbers;
        neighbors = new List[NodeNumbers+1];
        visited   = new bool[NodeNumbers+1];


    }

    ~Graph()
    {
        delete [] neighbors;
        delete [] visited;
    }

    void reset_visited()
    {
        for(int i=1; i<=NodeNumbers+1; i++)
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

        if(neighbors->size()<=1)                         // size 0 is all graph one node,size 1 is leaf because only has father
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

    int max_leaf_distance(int Source)
    {
        if(!visited[Source]) visited[Source] = true;

        if(neighbors->size() <= 1) return 0;

        int d,maxD = 0;
        for(Node* cur = neighbors[Source].head; cur != NULL; cur = cur->right)
        {
            if(!visited[cur->NodeData])
            {
                d = max_leaf_distance(cur->NodeData);
                maxD = max(d,maxD);
            }
        }
        return (1+maxD);
    }

    int sum_of_Mi(int Source, int Distance)
    {
        queue< pair<int,int> > to_do_list;              //with distance
        to_do_list.push(make_pair(Source,0));
        visited[Source]= true;

        int sum=0, now_D=0;                     //sum for return, now_D  is 0,1,...,Distance
        int index, d_each, part_min;
        while(!to_do_list.empty())
        {
            index  = to_do_list.front().first;
            d_each = to_do_list.front().second;
            to_do_list.pop();

            if(d_each != now_D)                 // every time when distance go to next step
            {
                sum += part_min;                // add previrous part_min
                now_D = d_each;
                part_min = index;
            }
            else
            {
                part_min = min(part_min,index);
            }

            if(d_each < Distance)
            {
                for(Node* cur = neighbors[index].head; cur != NULL; cur = cur->right)
                {
                    if(!visited[cur->NodeData])
                    {
                        visited[cur->NodeData] = true;
                        to_do_list.push(make_pair(cur->NodeData,d_each+1));
                    }
                }
            }
        }
        sum += part_min;
        //queue< pair <int,int> > tmp;
        //swap(tmp,to_do_list);
        return sum;
    }

};



int main(){

    /// input

    freopen("sample input.txt","r",stdin);
        // line 1
    int N; cin >> N;

    Graph* KT = new Graph(N);
        // N lines
    for(int u,v,i=0; i < N-1; i++)
    {
        cin>> u >> v;
        KT->push(u,v);
    }

        // last line
    int B;cin >> B;
//    cout<<"end input\n";
    /// process
    KT->reset_visited();
    int dBC = KT->min_leaf_distance(B);
    KT->reset_visited();
    int dBF = KT->max_leaf_distance(B);
    KT->reset_visited();
    int sum_M = KT->sum_of_Mi(B,dBF-dBC);           // dBF >= dBC


    /// output
    cout << sum_M << '\n';
    delete KT;

    return 0;


}
