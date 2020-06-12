# 2028 - I2P(II)2020_Lee_HW7

## 題目
| 狀態 | 題號  | 題目                 | tags |
| ---- | ----- | -------------------- | ---- |
| AC   | [11423](#11423-Simulating_Iterators)| Simulating Iterators |      |
|      | 12727 | Container List       |      |
|      | 12728 | Container Tree       |      |

## 11423-Simulating_Iterators
### 目的
implement iterator

### Input
第一行輸入數字N(0<N<100)  
第二行輸入N組表示**下個節點的位置**和**下個節點的值**  
第三行輸入一個數字H表示head在哪裡  
接下來有數行的指令，分別為
+ `0 p`：
+ `1 k`：
+ `2`：
+ `3`：

```
6
4 24713 2 21367 5 -3338 1 1893 3 -4723 0 -16458
1
1 25184
2
1 -24016
2
0 5
2
2
1 14994
2
1 26919
```

### Output
對於每個0Operation要輸出距離  
結束的時候輸出兩行
+ 按random access輸出值
+ 輸出index之類的東西

```
3
-16458 25184 -24016 26919 14994 -3338
0 1 2 3 4 5
```

### 解答
建構子
```c++
Node::Node()
  : prev(nullptr),next(nullptr){};

Iter::Iter(data_t *begin)
  : p_(begin){};

Bidirect_iter::Bidirect_iter(data_t *begin)
  : Iter(begin){};
  //繼承呼叫父類別建構子
Random_iter::Random_iter(data_t *begin)
  : Iter(begin){};
  //繼承呼叫父類別建構子
```
`Random_iter`的function
```c++
std::ptrdiff_t Random_iter::distance_(const Iter &begin,
                                      const Iter &end) const
{
  // 計算距離，用指標差值取絕對值
  return std::abs(begin.get() - end.get());
}

void Random_iter::next_(Iter &des) const
{
  //因為要修改，所以用call by reference
  //des是一個Iter的reference
  //修改des成random acess 的下一個位置
  //先取得目前位置再+1 (因為類型是Node指標所以可以直接運算
  des.assign(Random_iter(get()+1));
//  des.assign(des.get()+1); //這種寫法不行
  //因為對於Iter來說沒有copy constructor
  //所以要用呼叫method的方式來取得這個des裡面的東西
}

void Random_iter::prev_(Iter &des) const
{
  des.assign(Random_iter(get()-1));
}
```  
`Bidirect_iter`的function
```C++
std::ptrdiff_t Bidirect_iter::distance_(const Iter &begin,
                                        const Iter &end) const
{
  //Iter沒有copy constructor 所以不能抓下來用for loop
  //改用recursion呼叫
  if(begin.get() == end.get())
    return 0;
  else
    return distance_(Bidirect_iter(begin.get()->next),end) + 1;
}

void Bidirect_iter::next_(Iter &des) const
{
  //  des.assign(des.get().next);
  // 不能用這種寫法 理由同上
  des.assign(Bidirect_iter(get()->next));
  // get()完得到的是一個Node*
  // 要存取其member variable要用->的方式
}

void Bidirect_iter::prev_(Iter &des) const
{
  des.assign(Bidirect_iter(get()->prev));
}
```
[回到頂部](#題目)
