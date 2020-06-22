#include <bits/stdc++.h>
using namespace std;

class MinMaxHeap{
  private:
    priority_queue<int> min_heap;
    priority_queue<int> max_heap;
    int virtual_min_heap_size = 0;
    int virtual_max_heap_size = 0;

  public:
    void push(int k){
      min_heap.push(-k);
      max_heap.push(k);
    }

    bool is_min_empty(){
      if(min_heap.size() == virtual_min_heap_size){
        while(!min_heap.empty())
          min_heap.pop();
        virtual_min_heap_size = 0;
        return true;
      }
      else
        return false;
    }

    bool is_max_empty(){
      if(max_heap.size() == virtual_max_heap_size){
        while(!max_heap.empty())
          max_heap.pop();
        virtual_max_heap_size = 0;
        return true;
      }
      else
        return false;
    }


    void pop_min(){
      if(!is_min_empty()){
        min_heap.pop();
        virtual_max_heap_size++;
      }
    }

    void pop_max(){
      if(!is_max_empty()){
        max_heap.pop();
        virtual_min_heap_size++;
      }
    }

    int min(){
      if(is_min_empty())
        cout<<"Null\n";
      else
        cout<<-min_heap.top()<<"\n";
    }

    int max(){
      if(is_max_empty())
        cout<<"Null\n";
      else
        cout<<max_heap.top()<<"\n";
    }

    void clear(){
      while(!min_heap.empty())
          min_heap.pop();
      while(!max_heap.empty())
          max_heap.pop();
      virtual_max_heap_size = 0;
      virtual_min_heap_size = 0;
    }

};


int main(){
  freopen("input.txt","r",stdin);
  string op;
  int k;
  MinMaxHeap MMH;
  while(cin>>op){
    if(op == "PUSH"){
      cin>>k;
      MMH.push(k);
    }

    if(op == "MAX")
      MMH.max();

    if(op == "MIN")
      MMH.min();

    if(op == "POPMAX")
      MMH.pop_max();

    if(op == "POPMIN")
      MMH.pop_min();

    if(op == "CLEAR")
      MMH.clear();
  }


}
