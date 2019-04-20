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

the length of the two string are the same and the length is from 1~105 ( 1 <= length <= 105 )
```
apapapap
papapapa
```
> 2行字串輸入
    長度相等且介於1~105之間


## Output
output contains one line.

print "YES" if two string is equal in Johnny's rule,

print "NO" otherwise.

remember to print \n at the end of output.
```
YES
```
