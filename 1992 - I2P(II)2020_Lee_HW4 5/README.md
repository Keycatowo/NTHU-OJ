# 1992 - I2P(II)2020_Lee_HW5


## 目錄

| 完成狀態 | 題號  | 名稱                                  | 標籤                |
| -------- | ----- | ------------------------------------- | ------------------- |
| AC       | 11410 | Implement a vector 2                  |                     |
|          | 11430 | Implement a list 1 (erase and insert) |                     |
|          | 12721 | Implement a BST                       |                     |
|          | 11445 | Copy a vector (Implement a vector 6)  |                     |
|          | 12715 | BigInt++                              |                     |
| AC       | 12722 | Fibonacci Machine                     | `加速` `運算子重載` |


## 11410 Implement a vector 2
+ Implement Vector
    + constructor
    + `pop_back()`:
    + `push_back()`:
    + `capacity()`:
    + `size()`:
    + `insert()`:
    + `reserve()`:
    + `resize()`:
    + destructor

### code:

```C++
#include <bits/stdc++.h>
#include "function.h"

namespace oj{
  Vector::Vector()
    :begin_(nullptr), end_(nullptr), last_(nullptr)
  {

  }

  Vector::size_type Vector::capacity() const
  {
    // for memory size
    return end_ - begin_;
  }

  Vector::size_type Vector::size() const
  {
    // for used data size
    return last_ - begin_;
  }

  void Vector::pop_back()
  {
    // no need to actually delete
    if(size()>0)  last_--;
  }

  void Vector::push_back(value_type val)
  {
    if(capacity()==size()){
		reserve(std::max(capacity()+1,capacity()*3));
	}

	(* last_) = val;
	last_++;
  }

  void Vector::insert(size_type pos, size_type count, value_type val)
  {
    auto old_capacity = capacity();
    auto old_size = size();
    if(old_capacity < old_size+ count)
    {
      auto cap = std::max(old_capacity+old_capacity/2,old_capacity+count);
      reserve(cap);
    }
    resize(old_size+count);

    std::copy_backward(begin_+(pos+count-1),last_,last_+count);
    std::fill(begin_ + pos , begin_+ pos + count,val);
    last_ += count;
  }


  void Vector::reserve(size_type new_capacity)
  {
    auto old_capacity = capacity();
    auto old_size = size();
    if (new_capacity > old_capacity)
    {
      pointer new_begin_ = new value_type[new_capacity];
      std::copy(begin_, last_, new_begin_);
//      for (auto i=0;i<old_size;i++)
//        new_begin_[i] = begin_[i];
      delete [] begin_;
      begin_ = new_begin_;
      end_ = &begin_[new_capacity];
      last_ = &begin_[old_size];
    }



  }
void Vector::resize(size_type new_size) {
		auto old_size = size();
		if (new_size < old_size) {
			for (auto i = old_size;i > new_size;i--) {
				pop_back();
			}
		}
		else if (new_size > old_size) {
			if (new_size > capacity()) {
				reserve(new_size);
			}
			for (auto i = old_size;i < new_size;i++) {
				// Pad empty space with zeroes.
				push_back(0);
			}
		}
		// == : No need to do anything.
	}

	Vector::~Vector() { // Destructor
		delete [] begin_;
	}

}
```


## 11430 Implement a list 1 (erase and insert)
+ Implement List
    + constructor
    + destructor
    + erase
    + insert
    + operator<<(std::ostream &,const List &lst).


## 12721 Implement a BST




## 11445 Copy a vector (Implement a vector 6)

###  目的
**完成一個Vector的實作**  
+ `default constructor`
+ `copy constructor`
+ `copy assignment operator`
+ `erase`
+ `insert`
+ `reserve`
+ `destructor`

### Input
```
copy_ctor 0
i 1 0 43842
s 1
i 0 0 875
copy_ctor 0
e 1 0
i 1 0 27629
s 0
i 1 0 31641
copy 0
i 0 0 14191
copy 1
e 1 0
copy_ctor 1
```
### Output
```
43842
1

43842
875
43842
875
875
875

875
27629
1
875
27629
875
31641 27629
875
875
14191 875
875
875
875
875



```

## 12715 BigInt++
### 目的
+ 建立一個`Bigint`類別
+ 要求有7個基本的function
    + **Constructor**：以`string`初始化為非零整數(非0開始)
    + **Destructor**
    + operator overloading
        + ++x
        + x++
        + --x
        + x--
    + `char* to_s()`:returns a duplicate of the number in char*, e.g., "123".
> Note that you don't need to implement negative numbers. When the number is 0 and you have to decrement it, you can ignore the operation.

### Input
```
2
0
2
B--
++B
9
3
B++
B--
--B
```

### Output
```
0
1
9
10
8
```
### Code

```C++
#ifndef FUNCTION_H
#define FUNCTION_H
#include <bits/stdc++.h>

namespace oj {
    class BigInt {
    private:
        char* _val;

        // Remove leading zeroes.
        void truncate() {
            if (strlen(_val) > 1 && _val[0] != '0') return;
            else if (strlen(_val) == 1) return;
            char* new_val = new char[strlen(_val) + 1];
            strcpy(new_val, _val + 1);
            delete _val;
            _val = new_val;
        }

        // Given the current digit position and the carry, add the carry to the digit and return the carry.
        int half_adder(const int pos, const int& c) {
            if (_val[pos] + c > '9') {
                _val[pos] = '0';
                return 1;
            }
            else {
                _val[pos]++;
                return 0;
            }
        }

        // Add 1 to _val.
        void add_one() {
            int carry = 1;
            for (int i = strlen(_val) - 1;i >= 0 && carry;i--)
                carry = half_adder(i, carry);
            if (carry) {
                char* new_val = new char[strlen(_val) + 2];
                new_val[0] = '1';
                strcpy(&new_val[1], _val);
                delete _val;
                _val = new_val;
            }
        }

        // Given the current digit position and the borrow, subtract the borrow from the digit and return the borrow.
        int half_subtractor(const int pos, const int& b) {
            if (_val[pos] - b < '0') {
                _val[pos] = '9';
                return 1;
            }
            else {
                _val[pos]--;
                return 0;
            }
        }

        // Subtract 1 from _val.
        void subtract_one() {
            if (_val[0] == '0') return;
            int borrow = 1;
            for (int i = strlen(_val) - 1;i >= 0 && borrow;i--)
                borrow = half_subtractor(i, borrow);
            truncate();
        }

    public:
        BigInt(char* s);
        ~BigInt();
        BigInt& operator++();
        BigInt operator++(int);
        BigInt& operator--();
        BigInt operator--(int);
        char* to_s();
    };

    BigInt::BigInt(char* s) {
        _val = new char[strlen(s) + 1];
        strcpy(_val, s);
    }

    BigInt::~BigInt() {
        delete _val;
    }

    BigInt& BigInt::operator++() {
        add_one();
        return (*this);
    }

    BigInt BigInt::operator++(int) {
        BigInt* tmp = new BigInt(_val);
        add_one();
        return (*tmp);
    }

    BigInt& BigInt::operator--() {
        subtract_one();
        return (*this);
    }

    BigInt BigInt::operator--(int) {
        BigInt* tmp = new BigInt(_val);
        subtract_one();
        return (*tmp);
    }

    char* BigInt::to_s() {
        return _val;
    }

}  // namespace oj

#endif
```



## 12722 Fibonacci Machine  
+ 完成`Fib` class內的function：
    + `void setBase(int, int);`
    + `int64_t operator[](int);`
+ 結果保證在`int64_t`裡面

### Input
```
4       // 表示輸入行數
0 0 1   // 0 A B 調用 fib.setBase(A, B)
1 5     // 1 K 調用 fib[K]
0 1 1   // 下一筆Query
1 3
```

### Output
```
5
3
```
## Sol-1 內建表法
```C++
#include "function.h"
#define MAX_INDEX 92    // 1,1開始的費式數列最多到93項還在int64內
#include <cstdint>

using namespace std;
bool preprocessed = false;
int64_t series[MAX_INDEX];

void init(){
    if(preprocessed == false){
        preprocessed = true;
        series[0]=1;
        series[1]=1;
        for(int i=2;i<MAX_INDEX;i++){
            series[i] = series[i-1] + series[i-2];
        }

    }
}

void oj::Fib::setBase(const int x, const int y){
    a0 = x;
    a1 = y;
    init();
}


int64_t oj::Fib::operator[](int k){
    if (k==0){
        return a0;
    }
    else if (k==1){
        return a1;
    }
    else{
        if(k>(MAX_INDEX+1))
        // 因為題目保證在int64裡面的範圍
        // 如果超過93位還有要求的話
        // 一定是0,0開始的數列
            return 0;
        return (series[k-2]*a0 + series[k-1]*a1);
    }
}
```
