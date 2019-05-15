#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
int M[1000];
bool Edges[1000][1000];
int V,E;
bool is_root[1000];

void init(){
    for(int i=0; i<V;i++){
        is_root[i] = true;
        M[i]=0;
        for(int j=0; j<V; j++)
            Edges[i][j]= false;
    }
}

void draw(int from, int to){
    Edges[from][to] =  true;
//    Edges[to][from] = -1;
}

bool mix(int target){
    int sum=0;
    for(int i=0; i<V; i++)
    {
      if(Edges[i][target])
      {
        if(M[i]==0) return false;
        else sum+= M[i];
      }
    }
    M[target] = sum;
    return true;
}

void go_out(int target){
    for(int i=0; i<V; i++)
    {
        if(Edges[target][i])
        {
            M[i] += M[target];
            if(M[i]>1000000) M[i]=1000000;
            Edges[target][i] = false;
        }
    }
}

bool no_in(int target){
    for(int i=0; i<V; i++){
        if(Edges[i][target]) return false;
    }
    return true;
}

void go(){
    queue<int> Q;
    int spend=0;
    for(int i=0; i<V; i++)
    {
        if(is_root[i])
        {
            M[i]=1;
            spend--;
            Q.push(i);
//            for(int j=0; j<V; j++)
//            {
//                if(Edges[i][j])
//                    Q.push(j);
//            }
        }
    }

    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();

        for(int i=0; i<V; i++)
        {
            if(Edges[now][i])
            {
                M[i] += M[now];
                if(M[i]>1000000) M[i]=1000000;
                Edges[now][i] = false;
                if(no_in(i)) Q.push(i);
            }
        }



    }

    for(int i=0; i<V; i++)
    {
        spend += M[i];
    }

    cout<<spend<<"\n";
}




void test_case(){
//    int V,E;
    cin>>V>>E;
    init();
    for(int u,v,i=0; i<E; i++)
    {
        cin>>u>>v;
        draw(u,v);
        is_root[v] =false;
    }
    go();
//    show();
}

int main(){_
    //freopen("sample.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
//        test_case();
        cin>>V>>E;
        init();
        for(int u,v,i=0; i<E; i++)
        {
            cin>>u>>v;
            draw(u,v);
            is_root[v] =false;
        }
        go();
    }

    return 0;
}
