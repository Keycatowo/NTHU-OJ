#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt","r",stdin);
  int N,S,a,b;
  cin>>N>>S;
  map<int, vector<int>> M;
  while(--N){
    cin>>a>>b;
    M[a].push_back(b);
    M[b].push_back(a);
  }
  /// BFS
  // reset
  queue<pair<int,int>> Q;
  Q.push(make_pair(S,0));
  int sum = 0;
  // loop
  while(!Q.empty()){
    // get a node
    auto cur = Q.front();
    Q.pop();
    if(!M[cur.first].empty())
      sum += cur.second;
    // go over all nodes it connect
    for(auto i: M[cur.first])
      Q.push(make_pair(i,cur.second+1));
    M[cur.first].clear();
  }

  cout<<sum<<"\n";
}
