#include <bits/stdc++.h>
#include "function.h"


namespace oj{

List::List():begin_(nullptr){}

List::~List(){
  if(begin_!=nullptr){
    Node* cur = begin_;
    do{
      Node* tmp= cur;
      cur = cur->next;
      delete tmp;
    }while (cur!=begin_);
  }
}

void List::remove(const_reference val){
  // for size 0 list
  if(begin_==nullptr)
    return;
  // for size 1 list delete
  if(begin_->next == begin_ && begin_->data == val){
    delete begin_;
    begin_ = nullptr;
    return;
  }

  // for size 2+ list
  if(begin_->data == val){
    // for head be delete
    // delete and recursion
    Node* tmp = begin_;
    begin_ = tmp->next;
    begin_->prev = tmp->prev;
    tmp->prev->next = begin_;
    delete tmp;
    remove(val);
  }
  else{
    // case not delete head
    Node* cur = begin_;
    do{
      if(cur->data == val){
        Node* tmp = cur;
        cur = cur->next;
        cur->prev = tmp->prev;
        tmp->prev->next = cur;
        delete tmp;
      }
      else
        cur = cur->next;
    }while(cur!=begin_);
  }
}


void List::push_back(const_reference val){
  // create a new node
  Node* new_node = new Node;
  new_node->data = val;

  // for size 0 list
  if(begin_==nullptr){
    begin_ = new_node;
    begin_->prev = new_node;
    begin_->next = new_node;
  }

  // for size 1+ list
  else{
    Node* old_tail = begin_->prev;
    old_tail->next = new_node;
    new_node->prev = old_tail;
    new_node->next = begin_;
    begin_->prev = new_node;
  }

}


std::ostream& operator<<(std::ostream &os, const List &lst){
  // for size 0 list
  if(lst.begin_==nullptr){
    return os;
  }
  // for size 1+ list
  List::Node* cur;
  for(cur=lst.begin_;cur->next!=lst.begin_;cur=cur->next){
    os<<cur->data<<" ";
  }
  os<<cur->data<<" ";
  return os;
}


} //namespace oj

