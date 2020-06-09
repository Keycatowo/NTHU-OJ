#include<bits/stdc++.h>
using namespace std;
#define MAX 1005

int main(){
  freopen("input_9420.txt","r",stdin);
  int N;
  int a,b;
  bool parent[MAX],child[MAX];

  while(cin>>N){
    if(N==0)
      return 0;
    // reset whole array
    for(int i=1;i<=MAX;++i)
      parent[i] = child[i] = false;
    // input N lines
    for(int i=1;i<=N;++i){
      cin>>a>>b;
      parent[a] = true;
      child[b] = true;
    }
    cin>>a;
    parent[a] = true;
    // count leafs
    int sum=0;
    for(int i=1;i<=MAX;++i)
      if(parent[i]==false && child[i]==true)
        sum++;
    cout<<sum<<"\n";
  }

}
