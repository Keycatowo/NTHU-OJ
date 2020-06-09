## 2048 HW9

## 題目
| 狀態 | 題號  | 題目                 | tags    |
| ---- | ----- | -------------------- | ------- |
| AC   | 9420  | Count the Leaves     | `graph` |
| AC   | 9467  | Parentheses Matching | `stack` |
| AC   | 11490 | The Cat Society      | `sort`  |


## 9420  Count the Leaves
### 題目
輸入數字N，輸入N行a,b表示a是b的父親  
輸入數字a表示根的位置  
求總葉子數量  
> N<1000

## 解法
是葉必是子，是父不是葉

```c++
int N;
  int a,b;
  bool parent[MAX],child[MAX];

  while(cin>>N){
    if(N==0)
      return 0;
    // reset whole array
    for(int i=1;i<=MAX;++i)
      parent[i] = child[i] = false;
    // input N lines
    for(int i=1;i<=N;++i){
      cin>>a>>b;
      parent[a] = true;
      child[b] = true;
    }
    cin>>a;
    parent[a] = true;
    // count leafs
    int sum=0;
    for(int i=1;i<=MAX;++i)
      if(parent[i]==false && child[i]==true)
        sum++;
    cout<<sum<<"\n";
  }
```
