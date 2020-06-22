#include<bits/stdc++.h>

int main(){
  using namespace std;
  freopen("input.txt","r",stdin);
  vector<pair<int,int> > all_list;
  int N,a,b;
  cin>>N;
  while(N--){
    cin>>a>>b;
    all_list.push_back(make_pair(a,1));
    all_list.push_back(make_pair(b,-1));
  }

  sort(all_list.begin(),all_list.end());
  int tmp_step = all_list.at(0).first;
  int d_count = 0;
  int sum = 0;
  int max_count = 0;
  for(auto i:all_list){
//    cout<<"for "<<i.first<<" "<<i.second<<"\n";
    if(tmp_step != i.first){
      tmp_step = i.first;
      sum += d_count;
//      cout<<"sum = "<<sum<<"\n";
      max_count = max(max_count,sum);
      d_count = 0;
    }

    d_count += i.second;
  }
  cout<<max_count<<"\n";

}
