#include<bits/stdc++.h>
using namespace std;


bool solve_one_line(){
  string str;
  getline(cin,str);
  if(str.size()==0)
    return true;

  stack<int> stk;
//  cout<<"size is "<<str.size()<<"\n";
  for(int i=0; i<str.size();++i){
    switch(str[i]){
      case '{':
        stk.push(1);
        break;
      case '[':
        stk.push(2);
        break;
      case '(':
        stk.push(3);
        break;
      case '<':
        stk.push(4);
        break;
      case '}':
        if(stk.empty()|| stk.top()!=1)
          return false;
        stk.pop();
        break;
      case ']':
        if(stk.empty()|| stk.top()!=2)
          return false;
        stk.pop();
        break;
      case ')':
        if(stk.empty()|| stk.top()!=3)
          return false;
        stk.pop();
        break;
      case '>':
        if(stk.empty()|| stk.top()!=4)
          return false;
        stk.pop();
        break;
      case ' ':
        return false;
      default:
        break;
    }//switch


  }//for
  if(stk.empty())
    return true;
  else
    return false;

}




int main(){
  freopen("input_9467.txt","r",stdin);
  int N;
  cin>>N;
  getchar();

  for(int i=0;i<N;i++){
    cout<<"Case :"<<i+1<<" ";
    if (solve_one_line())
      cout<<"Yes\n";
    else
      cout<<"No\n";
  }
}
