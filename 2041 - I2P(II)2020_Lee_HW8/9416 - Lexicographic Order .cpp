#include<bits/stdc++.h>
using namespace std;


int main(){
  freopen("input_9416.txt","r",stdin);
  int N;
  string s;
  vector<string> vec;
  while(cin>>N){
    if(N==0)
      return 0;
    for(int i=0;i<N;++i){
      cin>>s;
      vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    for(auto i:vec){
      cout<<i<<"\n";
    }
    cout<<"\n";
    vec.clear();
  }

}
