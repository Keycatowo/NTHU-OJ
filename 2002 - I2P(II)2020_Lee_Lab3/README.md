# 2002 - I2P(II)2020_Lee_Lab3

| 完成狀態 | 題號  | 名稱     | 標籤                                     |
| -------- | ----- | -------- | ---------------------------------------- |
| 補AC     | 12716 | BigOdd++ | `class`,`operator overloading`,`big int` |
| AC       | 12723 | BSTWD    | `class`,`string`                         |


## 12723 BSTWD
### Description
You need to implement the following functions for a binary search tree data structure:

  BST(); // constructor, does what needs to be done when created
  ~BST();  // destructor, doest what needs to be done when destroyed
  void insert(int v); // insert value v
  string inorder(); // returns a string representing the values in the inorder traversal, separated by a space

There is only one private member "`Node *root`" in BST. The definition of Node is as follows:
```
struct Node {
  int val;
  int cnt; // occurence of value
  Node *lc; // left child
  Node *rc; // right child
  Node(int v) : val(v), lc(nullptr), rc(nullptr) {} // init to null when created
};
```
Note that duplicate values may exist at the same time in the data structure

### Input
Q
OP_1
OP_2
...
OP_Q

Where Q is an integer representing the number of operations. Q lines follow.
OP_i is the i'th operation, and it may be one of the two following forms:

0 V
1

Where "0 V" will need you to insert V into the BST, and "1" needs you to print the inorder traversal. The operations has to be accomplished in the order they are given.

1 <= Q <= 2000
0 <= V <= 10^9
```
5
0 1
0 1
0 2
0 3
1
```

### Output
For each operation "1", print the inorder traversal in a line.
```
1 1 2 3
```

### 解題方向
因為題目要求重複的資料要重複出現，且輸出排序後的結果
那這樣其實就不用真的用BST的方式去做，用vector排序就好


### 解法-非正式
```C++
#include <bits/stdc++.h>
#include "function.h"
using namespace std;

vector <int> tree;

namespace oj{

BST::BST(){
}

BST::~BST(){
}

void BST::insert(int val){
  tree.push_back(val);
}

string BST::inorder(){
  sort(tree.begin(),tree.end());
  string S="";
  for(auto i=0;i<tree.size();i++){
    S += to_string(tree[i]);
    if (i!=tree.size()-1)
      S += " ";
  }
  return S;
}

}
```



##  12716 BigOdd++

### 解題方向
+ `new` 字元陣列長度的時候+2(一個留給`\0`，一個留給位移用的)
+ `remove_zero`
  + 找到前面非數字0的位置，`copy`移到開頭
+ `add_one`
  + 全部往後移首位補0，例如`123`變成`0123`
  + 一開始carry設成true
  + 從結尾開始，到如果carry是true的話
    + 如果那位是9，令其為0，進位carry為true
    + 如果非9，令其+1，進位carry為false
  + 檢查結尾是否為偶數
    + 是則+1
  + 檢查最終是否有多1位
    + 是則copy and swap一個新的BigOdd

### Sol
```C++
#include <bits/stdc++.h>
#include "function.h"
#define show(a) printf("%s:%d\n",#a,a)


void remove_zero(char *s){
  int len = strlen(s);
  for(int i=0;i<len;i++){
    if(s[i]!='0'){
      std::copy(s+i,s+len+1,s);
      break;
    }
  }
}

void add_one(char *s){
  int len = strlen(s);
  std::copy_backward(s,s+len+1,s+len+2);// 0xxxx
  s[0] = '0';
  bool carry = true;
  for(int i=0;i<=len;i++){
    if(carry){

      if(s[len-i] == '9'){
        // 9 -> 10
        carry = true;
        s[len-i] = '0';
      }

      else{
        // n -> n+1
        carry = false;
        s[len-i] += 1;
      }

    }
  }

  remove_zero(s);
  len = strlen(s);
  if( (s[len-1] - '0') % 2 ==0 ){
    s[len-1] += 1;
  }


}



namespace oj{
using namespace std;

BigOdd::BigOdd(char *s){
  _val = new char[strlen(s)+2];// '\0' and for move
  strcpy(_val,s);
  remove_zero(_val);
}

BigOdd::~BigOdd(){
    delete _val;
}

char* BigOdd::to_s(){
  return _val;
}

BigOdd& BigOdd::operator++(){
//  cout<<"++B\n";
  int len = strlen(_val);
  add_one(_val);
  if(_val[len] != '\0'){
    BigOdd new_odd(_val);
    swap(new_odd._val,(*this)._val);
  }
  return *this;
}

BigOdd BigOdd::operator++(int){
//  cout<<"B++\n";
  BigOdd tmp(_val);
  int len = strlen(_val);
  add_one(_val);
  if(_val[len] != '\0'){
    BigOdd new_odd(_val);
    swap(new_odd._val,(*this)._val);
  }
  return tmp;
}

BigOdd& BigOdd::operator--(){
  return *this;
}

BigOdd BigOdd::operator--(int){
  return *this;
}

}
```
