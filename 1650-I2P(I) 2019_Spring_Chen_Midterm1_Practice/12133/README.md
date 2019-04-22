# 12133 - Yes papa   

## Description
Johnny is a three years old kids. He likes to eat sugar. Oneday, he sneak into the kitchen in order to grab some sugar to eat. Unfortunately, his papa catch him.

His papa call him: " Johnny, Johnny! "

Johnny reply: " Yes, papa. "

papa then ask: " Eating sugar? "

Johnny lied: " No, papa. "

At that moment, Johnny begain to think that what's defintion of string equivalent? In this three years old kids' recognition, string a and string b is equivalent if a and b are the same or string a and string b can be devide into two same size part: a1, a2, b1, b2 and the following rules fulfill.

(  ( a1 == b1 ) && ( a2 == b2 ) )  or  ( ( a1 == b2 ) && ( a2 == b1 ) )

For example: a = " papa ", b = " apap ", we need to check if " pa " equals " ap " in Johnny ' s rule, therefore we divide " pa " into "p" and "a".

Divide " ap" into "a" and "p".

Then because "p" == "p" && " a " == "a" we know that "pa" == "ap".

therefore we can conclude that " papa " equals " apap ".

Note that we can't  divide a string if the length of the string is an odd number.

Help Johnny find out if the two string are the same. If you help him, he will give you some sugar.

> 定義一個等於規則：
  Oo=Xx
    1. O=X,o=x 前前相等，後後相等
    2. O=x;o=X  前等於對方的後，後等於對方的前







## Input
input contains two lines.

First line is the string a.

Second line is the string b.

the length of the two string are the same and the length is from 1~10^5 ( 1 <= length <= 10^5 )
```
apapapap
papapapa
```
> 2行字串輸入
    長度相等且介於1~10^5之間


## Output
output contains one line.

print "YES" if two string is equal in Johnny's rule,

print "NO" otherwise.

remember to print \n at the end of output.
```
YES
```
## 解題方向

遞迴寫法
1. 先判斷長度
  2. 奇數：判斷是否相等
  3. 偶數：拆兩個部分丟遞迴
陣列丟進去寫法
  `(Al,Ar,Bl,Br)`分別記錄兩個陣列的頭尾

### 1902914 AC
```
#include <stdio.h>
#include <stdbool.h>

char A[100000];
char B[100000];

bool is_equal(int Al,int Ar,int Bl,int Br){
    /// length 1
    //if(Al==Ar) return (A[Al]==B[Bl]);

    /// can  devide
    if((Ar-Al))// 0~7, even length is 1
    {
        return
        (
            (is_equal(Al,(Al+Ar)/2,Bl,(Bl+Br)/2) && (is_equal((Al+Ar)/2+1,Ar,(Bl+Br)/2+1,Br)))
            // 0~
            ||
            (is_equal(Al,(Al+Ar)/2,(Bl+Br)/2+1,Br) && (is_equal((Al+Ar)/2+1,Ar,Bl,(Bl+Br)/2)))
        );
    }
    /// can't devide
    else
    {
        // all should same
        for(int i=0;i<=(Ar-Al);i++){
            if(A[Al+i]!=B[Bl+i]) return false;
        }
        return true;
    }


}
int getline(char* Seq){
    char tmp;
    int i=0;
    while( (tmp=getchar())!='\n' ){
        Seq[i]=tmp;
        i++;
    }
    return i;
}
void papa_judge(){
    int length;
    length=getline(A);
    getline(B);
    if(is_equal(0,length-1,0,length-1))
        printf("YES\n");
    else
        printf("NO\n");
}
int main(){
    papa_judge();
    return 0;
}
```
原本還另外判斷了長度為1，後來發現其實它和奇數長度一樣都屬於不可分割，所以不用另外做判斷。
