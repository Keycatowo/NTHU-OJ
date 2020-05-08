#include <bits/stdc++.h>
#include "function.h"


namespace oj{

void Circle::draw(){
  // 要考慮半徑小於0
  using namespace std;
  int x,y,r;
  cin>>x>>y>>r;
  points.push_back(Point(x,y));
  radius = r;

  if(r<0)
    area = 0;
  else
    area = r*r*PI;
}

void Rectangle::draw(){
  // 要考慮不按順序的點
  using namespace std;
  int x,y;
  int x_max=INT_MIN, y_max=INT_MIN;
  int x_min=INT_MAX, y_min=INT_MAX;
  for(int i=0;i<4;i++){
    cin>>x>>y;
    points.push_back(Point(x,y));
    x_min = min(x_min,x);
    y_min = min(y_min,y);
    x_max = max(x_max,x);
    y_max = max(y_max,y);
  }
//  cout<<"size is "<<points.size()<<endl;
  area = (y_max-y_min) * (x_max-x_min);

}



} //  namesapce oj
