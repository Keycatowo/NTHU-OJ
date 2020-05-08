# 1993 - I2P(II)2020_Lee_HW6


## 題目
| 完成狀態 | 題號  | 名稱            | 標籤                                 |
| -------- | ----- | --------------- | ------------------------------------ |
| AC       | 11422 | Shape           | `繼承`, `三角形面積`, `平面圖形條件` |
| AC       | 11443 | 3DShape         | `繼承`,`繼承建構子`                  |
| AC       | 11484 | Draw the Shapes | `protected`                          |


## 11422 Shape
```C++
#include <bits/stdc++.h>
#include "function.h"

bool is_nagative(double num){
  return num <0;
}

bool not_trigangle(double a,double b,double c){
  if(a+b < c ||
     b+c < a ||
     a+c < b)
      return true;
  else
    return false;

}


namespace oj{

Triangle::Triangle(double a,double b,double c)
{
  edge1 = a;
  edge2 = b;
  edge3 = c;

  if (is_nagative(a)|| is_nagative(b) || is_nagative(c)||
      not_trigangle(a,b,c)){
    setPerimeter(0);
    setArea(0);
  }

  else{
    setPerimeter(a+b+c);
    double s = (a+b+c)/2;
    setArea(std::sqrt(s*(s-a)*(s-b)*(s-c)));
  }

}

Rectangle::Rectangle(double w, double h)
{
  width = w;
  height = h;

  if (is_nagative(w)||is_nagative(h)){
    setArea(0);
    setPerimeter(0);
  }

  else{
    setArea(w*h);
    setPerimeter(2*(w+h));
  }
}

Circle::Circle(double r,double p)
{
  radius = r;
  pi = p;

  if (is_nagative(r)||is_nagative(p)){
    setArea(0);
    setPerimeter(0);
  }

  else{
    setPerimeter(p*r*2);
    setArea(p*r*r);
  }

}
} // namespace oj
```


## 11443 3DShape
```c++
#include <bits/stdc++.h>
#include "function.h"

/*
  題目只要求輸出體積
  所以先忽略 對於每個不同 class 內其他值的 set
*/

namespace oj{

Sphere::Sphere(double r,double p){

  if(r<0 || p<0){
    setVolume(0);
  }

  else{
    setVolume(r*r*r*p*4.0/3.0);
//    std::cout<<"Sphere "<<r*r*r*p*4.0/3.0;
  }

}

Cone::Cone(double r,double h,double p){
  if(r<0 || h<0 || p<0){
    setVolume(0);
  }

  else{
    setVolume(r*r*p*h/3.0);
  }
}

Cuboid::Cuboid(double l,double w,double h){
  if(l<0 || w<0 || h<0){
    setVolume(0);
  }

  else{
    setVolume(l*w*h);
  }

}

Cube::Cube(double a):Cuboid(a,a,a){

}




} // namespace oj

```

## 11484 Draw the Shapes
```c++
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
```
