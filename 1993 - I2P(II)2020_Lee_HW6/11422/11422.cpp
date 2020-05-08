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




}
