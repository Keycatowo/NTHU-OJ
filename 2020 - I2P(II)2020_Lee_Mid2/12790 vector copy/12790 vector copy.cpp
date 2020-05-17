#include <bits/stdc++.h>
#include "function.h"
#ifndef ONLINE_JUDGE
#define DEBUG
#endif // ONLINE_JUDGE


namespace oj{

Vector::Vector()
  : begin_(nullptr), end_(nullptr), last_(nullptr) {}

Vector::Vector(const Vector &rhs)
  : begin_(nullptr), end_(nullptr), last_(nullptr){
  #ifdef DEBUG
  std::cout<<"copy";
  std::cout<<"\tFrom "<<rhs<<"\n";
  #endif // DEBUG
  reserve(rhs.size());
  for(size_type i=0; i<rhs.size(); i++){
    #ifdef DEBUG
    std::cout<<"Insert "<<rhs[i]<<" into pos_"<<i<<"\n";
    #endif // DEBUG
    insert(i,rhs[i]);
  }
}





//Vector& Vector::operator=(const Vector& rhs){
////  std::cout<<"copy assignment\n";
//  Vector temp(rhs);
//  std::swap(begin_, temp.begin_);
//  std::swap(end_, temp.end_);
//  std::swap(last_, temp.last_);
//  return *this;
//}



Vector& Vector::operator=(const Vector &rhs){
#ifdef DEBUG
  std::cout<<"copy assignment\n";
#endif // DEBUG

  /// deal with copy itself
  if(this == &rhs)
    return *this;
  // delete old value
  for(size_type i=0;i<size();i++){
    begin_[i].~value_type();
  }
  last_ = begin_;
  /// insert from reference vector
  reserve(rhs.size());
  for(size_type i=0;i<rhs.size();i++){
    insert(i,rhs[i]);
  }
  /// return
  return *this;
}


void Vector::erase(value_type val){
  // for size 0
  if(begin_ == nullptr)
    return;
  // for size other
  for(size_type i=0;i<size();i++){
    if(!(begin_[i] != val)){
      for(size_type j=i;j<size()-1;j++){
        begin_[j] = begin_[j+1];
      }
      begin_[size()-1].~value_type();
      last_--;
      return ;
    }
  }
}


void Vector::insert(size_type pos, const_reference val){
  if(pos<0 || pos>size())
    return;
  if(last_ == end_)
    reserve(std::max(capacity()+1,capacity()*3));

  if(pos == size()){
    new (begin_+size()) value_type(val);
    last_++;
  }
  else{
    new (begin_+size()) value_type(begin_[size()-1]);
    for(size_type i=size();i>pos;i--){
      begin_[i] = begin_[i-1];
    }
    begin_[pos] = val;
    last_ ++;
  }

}

void Vector::reserve(size_type new_capacity){
  size_type old_size = size();
  size_type old_capacity = capacity();
  if(old_capacity<new_capacity){
    pointer new_begin_ (static_cast<pointer> (operator new[](new_capacity * sizeof(value_type))));
    for(size_type i=0;i<old_size; i++){
      new (new_begin_+i) value_type(begin_[i]);
      begin_[i].~value_type();
    }
    operator delete (begin_);
    begin_ = new_begin_;
    last_  = &begin_[old_size];
    end_   = &begin_[new_capacity];
  }
}


Vector::~Vector(){
  if(begin_!=nullptr){
    for(size_type i=0; i<size(); i++){
      begin_[i].~value_type();
    }
    if(begin_!=nullptr)
      operator delete (begin_);
  }

}








}
