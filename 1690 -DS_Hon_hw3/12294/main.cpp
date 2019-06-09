#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define Div 429497296
using namespace std;

int T,m,n;

long long int H(long long int m, long long int n,long long int x)
{
    return ((m*x)%Div)%n;
}

class Graph{
public:
    int ListNumbers;
    vector<int> * List;

    Graph(int ListNumbers)
    {
        this->ListNumbers = ListNumbers;
        List = new vector<int> [ListNumbers];
    }

    ~Graph()
    {
        for(int i=0;i<ListNumbers;i++)
            List[i].clear();
        delete [] List;
    }

    void push(int x)
    {
        long long int h = H(m,n,x);
        List[h].push_back(x);
    }

    void show()
    {
        for(int i=0; i<ListNumbers; i++)
        {
            if(List[i].empty())
                cout<<"\n";
            else
            {
                cout<<List[i][0];   // for head
                for(int j=1;j<List[i].size();j++)
                {
                    cout<<" "<<List[i][j];
                }
                cout<<"\n";         // for tail
            }
        }
    }

};

int main(){_

    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        Graph* G = new Graph(n);
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            G->push(k);
        }
        G->show();
        delete G;
    }
    return 0;

}


