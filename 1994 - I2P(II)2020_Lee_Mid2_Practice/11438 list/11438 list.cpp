#include <bits/stdc++.h>
#include "function.h"


namespace oj{
extern std::size_t current_memory_size;

List::List():begin_(nullptr){}

List::~List(){
  Node* cur = begin_;
  do{
    Node* tmp= cur;
    cur = cur->next;
    delete tmp;
  }while (cur!=begin_);
}

void List::pop_back(){
  // for size 0 list
  if(begin_==nullptr)
    return;
  // for size 1 list
  if(begin_->next == begin_){
    delete begin_;
    begin_ = nullptr;
    return;
  }

  // for size 2+ list
  Node* old_tail = begin_->prev;
  Node* new_tail = old_tail->prev;
  new_tail->next = begin_;
  begin_->prev = new_tail;
  delete old_tail;
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
  if(lst.begin_==nullptr)
    return os;
  // for size 1+ list
  List::Node* cur;
  for(cur=lst.begin_;cur->next!=lst.begin_;cur=cur->next){
    os<<cur->data<<" ";
  }
  os<<cur->data<<" ";
  return os;
}


} //namespace oj

