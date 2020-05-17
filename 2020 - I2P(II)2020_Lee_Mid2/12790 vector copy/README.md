# 12790 - Copy a vector again

## Description
You must follow the rules as below:

1. do not use any static variables

2. do not use any variables which is not inside a function

3. only new, operator new, delete and operator delete are allowed to allocate or deallocate memory

4. memory usage limit: 16384 byte

You are required to implement a vector.

You have to enable C++11 in this problem. (e.g. "g++ -std=c++11 ...")

capacity is max(capacity(), rhs.size()).
erase: erases the first element that is equal to val (if it exists).
insert: inserts a val at pos. When capacity is not enough, the new capacity is max(old capacity + 1, old capacity * 3).
reserve: reserves storage (Increase the capacity of the container to a value that's equal to new capacity. If the new capacity is greater than the current capacity, new storage is allocated, otherwise the function does nothing.).
destructor

For all testcases, you have to deal with reserve() and whatever is not explicitly mentioned below;
For the first testcase, you only need to deal with insert();
For the second and third, you only need insert() and erase();
For the fourth, you may only omit copy assignment;
For all, you need to do all.

## Input
There are seven functions in Vector that you have to implement, the functionality is as below:

default constructor: initializes pointers. Do not allocate memory.
copy constructor: copies the elements of rhs. The new capacity is rhs.size().
copy assignment operator: copies the elements of rhs. The new
```
i 0 0 1
i 0 0 2
i 0 1 3
copy_ctor 0
copy 1 1
e 1 3
e 0 2
c 0
s 0
```

## Ouput
Complete a Vector (default constructor, copy constructor, copy assignment operator, erase, insert, reserve and destructor).
```
1

2 1

2 3 1

2 3 1
2 3 1
2 3 1
2 3 1
2 3 1
2 1
3 1
2 1
3
3 1
2 1
2
3 1
2 1
```

## 解題思路
### copy operator
+ 將lhs的空間令成rhs的大小
+ 將rhs中的元素依序插入lhs對應位置  
  + 迴圈控制條件是用`rhs.size()`不是`size()`，因為此時lhs的size還沒插入是0(考試的時候就是因為這裡寫錯所以一直沒對QQ)
```c++
Vector::Vector(const Vector &rhs)
  : begin_(nullptr), end_(nullptr), last_(nullptr){
  reserve(rhs.size());
  for(size_type i=0; i<rhs.size(); i++){
    insert(i,rhs[i]);
  }
}
```
### assignment operator
+ 特殊case：先處理assignment給自己的情況
+ 依序operator delete舊的資料
+ 設定新的空間大小
+ 依序插入新的值
```c++
Vector& Vector::operator=(const Vector &rhs){
  /// deal with copy itself
  if(this == &rhs)
    return *this;
  // delete old value
  for(size_type i=0;i<size();i++){
    begin_[i].~value_type();
  }
  last_ = begin_;
  /// insert from reference vector
  reserve(rhs.size());
  for(size_type i=0;i<rhs.size();i++){
    insert(i,rhs[i]);
  }
  /// return
  return *this;
}
```

## 重點整理
### DEBUG 模式
學期初的時候是用類似warning message level的方式去define一個值  
然後再用三元運算子夾`printf()`來控制除錯時輸出  
但是現在的`cout`回傳的並不是整數值，所以不能簡單的使用這種方式  
再加上最近的OJ題目都是使用partial judge的方式，題目都會有define一個**ONLINE_JUDGE**來檢查記憶體  
那我就順便利用OJ端和本地端的這個差異來設定可以不用在上傳的時候還要再特地修改值或是註解掉特定行來加快速度，具體操作方法如下  

開始的時候加上檢查是否有define值
```c++
#ifndef ONLINE_JUDGE
#define DEBUG
#endif // ONLINE_JUDGE
```


使用的時候用define值檢查
```c++
#ifdef DEBUG
  std::cout<<"copy\n";
  std::cout<<"From "<<rhs<<"\n";
#endif // DEBUG
```

雖然其實也可以用ONLINE_JUDGE直接去檢查，但想說這樣寫起來比較直觀一點和可讀性比較高，而且如果要設定不同的DEBUG level的時候也比較好調試

### **copy constructor** and **copy assignment constructor**
![](https://miro.medium.com/max/1400/1*osUChreU2Y4DO1EjBzt9Kg.png)
