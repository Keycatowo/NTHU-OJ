#include <bits/stdc++.h>
#include "function.h"

/*
  �D�إu�n�D��X��n
  �ҥH������ ���C�Ӥ��P class ����L�Ȫ� set
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
