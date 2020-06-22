#include<bits/stdc++.h>
using namespace std;

int main(){
  freopen("input.txt","r",stdin);
  stack<int> S;
  // input
  string s;
  while(cin>>s){
    if(s == "0")
      break;

    if(isdigit(s[0]))
      S.push(stoi(s));

    else{
      char op = s[0];
      int a = S.top();      S.pop();
      int b = S.top();      S.pop();
      switch(s[0]){
        case '+':
          S.push(b+a);
          break;
        case '-':
          S.push(b-a);
          break;
        case '*':
          S.push(b*a);
          break;
        case '/':
          S.push(b/a);
          break;
      }
    }
  }

  cout<<S.top()<<"\n";





}
