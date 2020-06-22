#include "function.h"
#include <bits/stdc++.h>

void printNode(Node* head){
  if(head == nullptr)
    return;
  if(head->data!=0 || head->power !=0){
    std::cout<<" "<<head->data<<" "<<head->power;
    std::cout<<"\n";
    printNode(head->next);
  }
}

Node* create_Node_zero(){
  Node* node = new Node;
  node->data = 0;
  node->power=0;
  node->prev = nullptr;
  node->next = nullptr;
  return node;
}

Node* create(){
  Node* head = create_Node_zero();
  Node* cur = head;
  long a;
  int n;
  while(std::cin>>a>>n){
    cur->data = a;
    cur->power= n;
    cur->next = create_Node_zero();
    cur = cur->next;
    if(n==0)
      break;
  }
  return head;
}
void destroy(Node *node){
  if(node == nullptr)
    return;

  Node* tmp = node->next;
  delete node;
  destroy(tmp);
}
//Node* multiple(Node* p1, Node* p2){
//  using namespace std;
//  priority_queue<pair<int,long>> Q;
//  for(Node* cur1=p1; cur1!=nullptr; cur1=cur1->next){
//    for(Node* cur2=p2; cur2!=nullptr; cur2=cur2->next){
//      auto tmp = make_pair(cur1->power + cur2->power,
//                           cur1->data * cur2->data);
//      if(tmp.first!=0 && tmp.second!=0)
//        Q.push(tmp);
//    }
//  }
//  long tmp_data=0;
//  int tmp_power=Q.top().first;
//
//  while(!Q.empty()){
//    auto i = Q.top();
//    if(tmp_power == i.first){
//      tmp_data += i.second;
//    }
//    else{
//      cout<<" "
//          <<tmp_data
//          <<" "
//          <<tmp_power;
//      tmp_power = i.first;
//      tmp_data = i.second;
//    }
//
//    Q.pop();
//  }
//  cout<<" "
//          <<tmp_data
//          <<" "
//          <<tmp_power;
//  return nullptr;
//}

Node* multiple(Node* p1, Node* p2){
  using namespace std;
  vector<pair<int,int> > L1;
  vector<pair<int,int> > L2;
  for(Node* cur = p1; cur!= nullptr;cur = cur->next)
    L1.push_back(make_pair(cur->power, cur->data));
  for(Node* cur = p2; cur!= nullptr;cur = cur->next)
    L2.push_back(make_pair(cur->power, cur->data));


  map<int,int,greater<int> > M;
  int power,data;
  for(auto i:L1){
    for(auto j:L2){
      power = i.first + j.first;
      data = i.second * j.second;
//      cout<<data << " " << power<<"\n";
      if(M.find(power)!=M.end())
        M[power] += data;
      else
        M[power] = data;
    }
  }

  for(auto i:M){
    if(i.second != 0)
      cout<<" "<<i.second<<" "<<i.first;
  }

  return nullptr;
}
