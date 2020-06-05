#include<bits/stdc++.h>
using namespace std;


int main(){
  freopen("input_9238.txt","r",stdin);
  string command;
  string name;
  queue<string> q;
  while(cin>>command){
    if(command=="Push"){
      cin>>name;
      q.push(name);
    }
    else if (command=="Pop"){
      if(!q.empty())
        q.pop();
    }
    else if (command=="Front"){
      if(q.empty())
        cout<<"empty\n";
      else
        cout<<q.front()<<"\n";
    }
  }

}
