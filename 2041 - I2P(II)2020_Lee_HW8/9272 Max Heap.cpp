#include<bits/stdc++.h>
using namespace std;

void solve_by_heap(){
  string command;
  int k;
  vector<int> vec;
  while(cin>>command){
    if(command=="PUSH"){
      cin>>k;
      vec.push_back(k);
      push_heap(vec.begin(),vec.end());
    }
    else if (command=="POP"){
      pop_heap(vec.begin(),vec.end());
      vec.pop_back();
    }
    else if (command=="TOP"){
      if(vec.empty())
        cout<<"Null\n";
      else
        cout<<vec[0]<<"\n";
    }
  }
}

void solve_by_priority_queue(){
  string command;
  int k;
  priority_queue<int> pq;
  while(cin>>command){
    if(command=="PUSH"){
      cin>>k;
      pq.push(k);
    }
    else if (command=="POP"){
      pq.pop();
    }
    else if (command=="TOP"){
      if(pq.empty())
        cout<<"Null\n";
      else
        cout<<pq.top()<<"\n";
    }
  }
}

int main(){
  freopen("input_9272.txt","r",stdin);
  /// solution 1 44ms
  solve_by_heap();
  /// solution 2 60ms
//  solve_by_priority_queue();



}
