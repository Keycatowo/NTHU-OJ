#include <bits/stdc++.h>
#include "function.h"

namespace oj{

Vector::Vector():begin_(nullptr),end_(nullptr),last_(nullptr){}

Vector::Vector(const Vector &rhs){
  // copy constructor
  begin_ = nullptr;
  last_  = nullptr;
  end_   = nullptr;
  reserve(rhs.size());
  for(size_type i=0; i<rhs.size();i++)
    insert(i,rhs[i]);
}

Vector& Vector::operator=(const Vector &rhs){
  /** important!**/
  /* deal with the case copy to itself */
  if(this==&rhs) return *this;

  // delete old vector
  for(size_type i=0;i<size();i++)
    begin_[i].~value_type();
  last_=begin_;
  reserve(rhs.size());
  // insert new vector
  for(size_type i=0;i<rhs.size();i++)
    insert(i,rhs[i]);

  return *this;
}


void Vector::erase(size_type pos){
  if(pos>=0 && pos<size()){
    for (size_type i=pos;i<size()-1;i++){
      begin_[i] = begin_[i+1];
    }
    begin_[size()-1].~value_type();
    last_--;
  }
}


void Vector::insert(size_type pos, const_reference val){
  size_type old_size = size();
  size_type old_capacity = capacity();

  // for invalid pos case
  if(pos>old_size || pos<0)
    return;
  // for reserve memory
  if(last_==end_)
    reserve(std::max(old_capacity+1,old_capacity*3));

  /// for insert
  if(pos==old_size)
    new (begin_+old_size) value_type(val);
  else{
    new (begin_+old_size) value_type(begin_[old_size-1]);
    for (size_type i=old_size-1;i>pos;i--){
    // copy_backward
      begin_[i] = begin_[i-1];
    }
    begin_[pos] = val;
  }
  last_++;
}


void Vector::reserve(size_type new_capacity){
  size_type old_size = size();
  size_type old_capacity = capacity();
  if(new_capacity>old_capacity){
    /** �����m�߭��I�G�ϥ�static_cast **/
    pointer new_begin_(static_cast<pointer>(operator new[](new_capacity * sizeof(value_type))));

    for(size_type i=0;i<old_size;i++){
      new (new_begin_+i) value_type(begin_[i]);
      begin_[i].~value_type();
    }
    if(begin_!=nullptr)
      operator delete(begin_);
    // reassign the pointers
    begin_ = new_begin_;
    last_ = begin_+old_size;  // ���]�Ŷ� ���פ���
    end_ = begin_+new_capacity; // ���]�Ŷ� �Ŷ�����
  }
}


Vector::~Vector(){
  for(size_type i=0;i<size();i++)
    begin_[i].~value_type();
  if(begin_!=nullptr)
    operator delete(begin_);
}




} //namespace oj
