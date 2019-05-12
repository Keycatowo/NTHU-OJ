#include <bits/bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 65536;

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
            tail = tail->next;                  // update tail by new node
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
    int Key;
    vector< queue<int> > neighbors;
    vector<bool>       visited;

    Graph(int NodeNumbers)
    {
        this->Key = NodeNumbers;
        for(int i=0; i<=NodeNumbers; i++)
        {
            queue<int> tmp;
            neighbors.push_back(tmp);
            visited.push_back(false);
        }

    }

    ~Graph()
    {
        for(int i=0; i<=NodeNumbers; i++)
        {
            queue<int> tmp;
            neighbors[i].swap(tmp);
        }
        vector< queue<int> > tmp2;
        neighbors.swap(tmp2);
        vector<bool>         tmp3;
        visited.swap(tmp3);
    }

    int min_leaf_distance(int Source)
    {
        if(!visited[Source]) visited[Source] = true;    // visit it

        if(neighbors[Source].size()<= 1)                // size 0 is all graph one node,size 1 is leaf because only has father
            return 0;                                   // to leaf(itself) is distance 0

        int d,minD = MAX;
        for()

    }

};
