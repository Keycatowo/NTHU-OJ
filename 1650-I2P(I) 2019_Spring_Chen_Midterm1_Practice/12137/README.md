# 12137 - Johnny Johnny   

##Description
PaPa suspected that Johnny ate the sugar, yet Johnny said he hadn't eaten it.

Therefore, PaPa asked: " Telling lies? "

Johnny replied: " No PaPa. "

PaPa then demanded: " Open your mouth! "

Johnny laughed embarrassedly: " Ha Ha Ha!!! "

PaPa is so furious with Johnny telling lies, abd he punished Johnny to do some math.

PaPa gave Johnny n numbers a1 ~ an and a number k.

PaPa asked Johnny to calculate how many ways he could pick some numbers from a1 to an in order to make their sum equal to k?

For example: given n = 5 and numbers: { 1,2,3,3,3 }, and k = 3, the answer is 4.

(Note that although there are three identical "3", we still consider them as different indentities.) { (1, 2), (3), (3), (3) }

Johnny is a bad boy, so he commands you to do this for him!

> 給一串數字和目標和
  求可以將元素組合求和得出目標和的方法數



##Input
Input contains two lines.

First line contains two integer **n ( 1 <= n <= 20 ), k ( 1<=  k <=109)**

Second line contains n integer a1 ~ an (**1 <= ai <= 107** )
```
5 3
1 2 3 3 3
```
> n k
  a1 a2 ... an

##Output
Output only contains one integer that is sum of available ways to pick numbers, which summation is equal to k.

Remember to print \n at the end of output.
```
4
```
