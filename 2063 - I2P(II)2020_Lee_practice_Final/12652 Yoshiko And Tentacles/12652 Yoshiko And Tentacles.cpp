#include <bits/stdc++.h>
#define MAX 350
using namespace std;

bool filled[MAX][MAX] = {false};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1,  1,  0, -1,-1,-1};


void count_filled(){
  int sum = 0;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      if(filled[i][j])
        sum++;
  cout<<sum<<"\n";
}

void show(){
  for(int i=170;i>140;i--){
    for(int j=140;j<170;j++)
        if(filled[j][i])
          cout<<"*";
        else
          cout<<"-";
    cout<<"\n";
  }
}

void fill_with(const tuple<int,int,int,int> &point,set<tuple<int,int,int,int> > &S,const int & next_len){
  int x = get<0>(point);
  int y = get<1>(point);
  int direction = get<2>(point);
  int len = get<3>(point);
  direction = (direction+8)%8;
  for(int i=0;i<len;i++){
    x += dx[direction];
    y += dy[direction];
    filled[x][y] = true;
  }
////  show();cout<<"\n";
  int d1 = (direction+9)%8;
  int d2 = (direction+7)%8;
  S.insert(make_tuple(x,y,d1,next_len));
  S.insert(make_tuple(x,y,d2,next_len));
}





int main(){

  freopen("input.txt","r",stdin);
  int N,p;
  cin>>N>>p;
  set<tuple<int,int,int,int> > S_now;
  set<tuple<int,int,int,int> > S_next;
  S_now.insert(make_tuple(155,155,2,p));

  for(int i=1;i<N;i++){
    cin>>p;
    for (auto point: S_now){
      fill_with(point,S_next, p);
    }
    S_now.clear();
    S_now = S_next;
    S_next.clear();
  }

  for (auto point: S_now){
      fill_with(point,S_next, 0);
  }

  count_filled();
//  show();



}
