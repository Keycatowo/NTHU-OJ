# 2063 - I2P(II)2020_Lee_practice_Final

## 題目
| 狀態 | 題號            | 題目                                        | tags                        |
| ---- | --------------- | ------------------------------------------- | --------------------------- |
| AC  | [11371](#11371) | Polynomial multiplication using linked list | `linked-List`,`PJ`          |
| AC   | [11856](#11856) | Postfix Expression                          | `stack`                     |
| AC   | [11933](#11933) | Vector Dot                                  | `operator overloading`,`PJ` |
| 1/4  | [12306](#12306) | beat the monster                            | `BFS`                       |
| AC   | [12652](#12652) | Yoshiko And Tentacles                       | `set`                       |
| AC   | [12654](#12654) | Easygoing Yuri                              | `sort`,`interval`           |
| AC   | [12692](#12692) | GY's Tree                                   |                             |
|      | [12817](#12817) | Social Distance                             |                             |
| 2/4  | [12839](#12839) | MinMax-Heap                                 | `priority_queue`,`heap`     |

## 11371
### 題目
用linked list實作多項式乘法
### 輸入
+ 兩行測資
    + 每行內有2n個數字
    + 前者為係數，後者為指數(必定包含0次)

```
5 4 -3 2 1 0
-2 3 1 1 0 0
```
### 輸出
+ 降序輸出結果
+ 格式同輸入
+ 最前面加空格
+ 常數0不用輸出

```
 -10 7 11 5 -5 3 1 1
 ```

### 解題
+ 分開處理輸入、計算、輸出
+ 輸入以0結尾做確定
+ 以mapreduce的方式做
```c++
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
```

[回到目錄](#題目)
## 11856
### 題目
後序表示求值運算
### 解法
用stack操作  
運算時由後序式的前方開始讀取，遇到運算元先存入堆疊，如果遇到運算子，則由堆疊中取出兩個運算元進行對應的運算，然後將結果存回堆疊，如果運算式讀取完 畢，那麼堆疊頂的值就是答案了，

[回到目錄](#題目)
## 11933
[回到目錄](#題目)
## 12306
### 題目
模擬對戰計算  
+ 每回合操作：
    + 升級
    + 攻擊
    + 回血
### 輸入
+ 第一行輸入四個數字
    + 最大等級L
    + 最大血量HP
    + 怪物血量MHP
    + 怪物傷害MDMG
+ 接下來L行
    + 傷害量DMG
    + 回血量HL
+ 模式
    + 玩家先動
    + 怪物打固定值
    + 滿血開始
    + 1等開始

[回到目錄](#題目)
## 12652
### 題目
碎形問題，考慮重疊
### 輸入
+ 第一行為分支次數N
+ 第二行有N個表示每次分支長的長度p
+ 數量限制：
    + N=1~30
    + p=1~5
### 輸出
有被填滿過的格子數量
### 思路
最滿長30*5*2=300格
每次走完之後下次要走的起點和方向insert進一個set裡面
### 解答
為對齊次數，最後一次沒有cin下一步，所以拿出來用補0的方式做
```c++
S_now.insert(make_tuple(155,155,2,p));

  for(int i=1;i<N;i++){
    cin>>p;
    for (auto point: S_now){
      fill_with(point,S_next, p);
    }
    S_now.clear();
    S_now = S_next;
    S_next.clear();
  }

  for (auto point: S_now){
      fill_with(point,S_next, 0);
  }
```

```c++
void fill_with(const tuple<int,int,int,int> &point,set<tuple<int,int,int,int> > &S,const int & next_len){
  int x = get<0>(point);
  int y = get<1>(point);
  int direction = get<2>(point);
  int len = get<3>(point);
  direction = (direction+8)%8;
  for(int i=0;i<len;i++){
    x += dx[direction];
    y += dy[direction];
    filled[x][y] = true;
  }

  int d1 = (direction+9)%8;
  int d2 = (direction+7)%8;
  S.insert(make_tuple(x,y,d1,next_len));
  S.insert(make_tuple(x,y,d2,next_len));
}
```

[回到目錄](#題目)
## 12654
### 題目
最大重疊區段問題
### 解法
將開始和結束點標記`1`或`-1`push進一個vector  
sort之後遍歷一次把每個位置的sum記錄下來求最大
```c++
sort(all_list.begin(),all_list.end());
  int tmp_step = all_list.at(0).first;
  int d_count = 0;
  int sum = 0;
  int max_count = 0;
  for(auto i:all_list){
    if(tmp_step != i.first){
      tmp_step = i.first;
      sum += d_count;
      max_count = max(max_count,sum);
      d_count = 0;
    }

    d_count += i.second;
  }
```
[回到目錄](#題目)
## 12692
### 題目
計算一顆樹的level和
### 輸入
+ 第一行為兩個數字N和S，N表數字數，S表示根節點
+ 接下來N-1行，每行兩個數字表示連接關係
### 輸出
計算階層和
### 解法
因為節點數多(2*10^5)，所以不能用adjacency matrix  
改用map來存點，key為node值，value為連接的vector
```c++
  int N,S,a,b;
  cin>>N>>S;
  map<int, vector<int>> M;
  while(--N){
    cin>>a>>b;
    M[a].push_back(b);
    M[b].push_back(a);
  }
  /// BFS
  // reset
  queue<pair<int,int>> Q;
  Q.push(make_pair(S,0));
  int sum = 0;
  // loop
  while(!Q.empty()){
    // get a node
    auto cur = Q.front();
    Q.pop();
    if(!M[cur.first].empty())
      sum += cur.second;
    // go over all nodes it connect
    for(auto i: M[cur.first])
      Q.push(make_pair(i,cur.second+1));
    M[cur.first].clear();
  }
  cout<<sum<<"\n";
```
[回到目錄](#題目)
## 12817
[回到目錄](#題目)
## 12839
### 題目
MinMax-Heap  
### 解法
用兩個優先佇列加虛擬長度計算
[回到目錄](#題目)
