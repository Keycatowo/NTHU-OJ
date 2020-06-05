#include<bits/stdc++.h>
using namespace std;

bool solve_one_line(){
  string str;
  int a=0,b=0,c=0,d=0;
  getline(cin,str);
  if(str.size()==0)
    return true;
  cout<<"size is "<<str.size()<<"\n";
  for(int i=0; i<str.size();++i){
    switch(str[i]){
      case '{':
        a++;
        break;
      case '[':
        b++;
        break;
      case '(':
        c++;
        break;
      case '<':
        d++;
        break;
      case '}':
        a--;
        break;
      case ']':
        b--;
        break;
      case ')':
        c--;
        break;
      case '>':
        d--;
        break;
      default:
        break;
    }
    cout<<a<<"/"<<b<<"/"<<c<<"/"<<d<<"\n";
    if(a<0 || b<0 || c<0 || d<0){
//      cout<<"not balancce\n";
      return false;
    }

  }//for

  if(a==0 && b==0 && c==0 && d==0)
    return true;
  else{
//    cout<<"not enough\n";
    return false;
  }
}




int main(){
  freopen("input_9467.txt","r",stdin);
  int N;
  cin>>N;
  getchar();

  for(int i=1;i<N;i++){
    cout<<"Case :"<<i<<" ";
    if (solve_one_line())
      cout<<"Yes\n";
    else
      cout<<"No\n";
  }


  cout<<"Case :"<<N<<" ";
    if (solve_one_line())
      cout<<"Yes";
    else
      cout<<"No";
}
