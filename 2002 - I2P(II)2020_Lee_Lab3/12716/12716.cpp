#include <bits/stdc++.h>
#include "function.h"
#define show(a) printf("%s:%d\n",#a,a)


void remove_zero(char *s){
  int len = strlen(s);
  for(int i=0;i<len;i++){
    if(s[i]!='0'){
      std::copy(s+i,s+len+1,s);
      break;
    }
  }
}

void add_one(char *s){
  int len = strlen(s);
  std::copy_backward(s,s+len+1,s+len+2);// 0xxxx
  s[0] = '0';
  bool carry = true;
  for(int i=0;i<=len;i++){
    if(carry){

      if(s[len-i] == '9'){
        // 9 -> 10
        carry = true;
        s[len-i] = '0';
      }

      else{
        // n -> n+1
        carry = false;
        s[len-i] += 1;
      }

    }
  }

  remove_zero(s);
  len = strlen(s);
  if( (s[len-1] - '0') % 2 ==0 ){
    s[len-1] += 1;
  }


}



namespace oj{
using namespace std;

BigOdd::BigOdd(char *s){
  _val = new char[strlen(s)+2];// '\0' and for move
  strcpy(_val,s);
  remove_zero(_val);
}

BigOdd::~BigOdd(){
    delete _val;
}

char* BigOdd::to_s(){
  return _val;
}

BigOdd& BigOdd::operator++(){
//  cout<<"++B\n";
  int len = strlen(_val);
  add_one(_val);
  if(_val[len] != '\0'){
    BigOdd new_odd(_val);
    swap(new_odd._val,(*this)._val);
  }
  return *this;
}

BigOdd BigOdd::operator++(int){
//  cout<<"B++\n";
  BigOdd tmp(_val);
  int len = strlen(_val);
  add_one(_val);
  if(_val[len] != '\0'){
    BigOdd new_odd(_val);
    swap(new_odd._val,(*this)._val);
  }
  return tmp;
}

BigOdd& BigOdd::operator--(){
  return *this;
}

BigOdd BigOdd::operator--(int){
  return *this;
}

}

