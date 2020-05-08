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
