# 2041 - I2P(II)2020_Lee_HW8

## 題目
| 狀態 | 題號 | 題目                | tags                    |
| ---- | ---- | ------------------- | ----------------------- |
| AC   | 9272 | Max-Heap            | `heap`,`priority queue` |
| AC   | 9328 | Queueing(I)         |                         |
| AC   | 9416 | Lexicographic Order |                         |


## 9227 Max-Heap
### 題目
滿足三個操作
+ push：新增資料
+ pop：刪除最大的資料
+ top：印出最大的資料

### 解法
可以用`algorithm`裡面的heap做  
也可以用`priority_queue`直接來完成  
前者速度比較快，後者比較直觀  
```c++
// 44ms
void solve_by_heap(){
  string command;
  int k;
  vector<int> vec;
  while(cin>>command){
    if(command=="PUSH"){
      cin>>k;
      vec.push_back(k);
      push_heap(vec.begin(),vec.end());
    }
    else if (command=="POP"){
      pop_heap(vec.begin(),vec.end());
      vec.pop_back();
    }
    else if (command=="TOP"){
      if(vec.empty())
        cout<<"Null\n";
      else
        cout<<vec[0]<<"\n";
    }
  }
}
```

```c++
// 60ms
void solve_by_priority_queue(){
  string command;
  int k;
  priority_queue<int> pq;
  while(cin>>command){
    if(command=="PUSH"){
      cin>>k;
      pq.push(k);
    }
    else if (command=="POP"){
      pq.pop();
    }
    else if (command=="TOP"){
      if(pq.empty())
        cout<<"Null\n";
      else
        cout<<pq.top()<<"\n";
    }
  }
}
```

## 9328 Queueing 1
### 題目
就...最基本的queue操作
+ push
+ pop
+ empty
+ front

### 解答
```c++
// 0ms
string command;
  string name;
  queue<string> q;
  while(cin>>command){
    if(command=="Push"){
      cin>>name;
      q.push(name);
    }
    else if (command=="Pop"){
      if(!q.empty())
        q.pop();
    }
    else if (command=="Front"){
      if(q.empty())
        cout<<"empty\n";
      else
        cout<<q.front()<<"\n";
    }
  }
```


## 9416	Lexicographic Order
### 題目
輸入N，輸入N個名字，按字典序排序後輸出
### 解答
keypoint:**string的排序是按照字典序**  
```c++
int N;
  string s;
  vector<string> vec;
  while(cin>>N){
    if(N==0)
      return 0;
    for(int i=0;i<N;++i){
      cin>>s;
      vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    for(auto i:vec){
      cout<<i<<"\n";
    }
    cout<<"\n";
    vec.clear();
  }
```
