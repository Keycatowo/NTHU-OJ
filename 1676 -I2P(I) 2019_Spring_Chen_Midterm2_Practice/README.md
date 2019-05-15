# 12154 - You shall not pass!   
**Victory belongs to the Spitters!**

## Description
There are some meteors falling in a n*n area. The meteor's power of section (i,j) is denoted as "M(i,j)". There's no meteor if M(i,j) = 0.
You have a sequence of sputum denoted as "S(i)", sorted in ascending order.
If any sputum S(i) >= M(j,k), meteor M(j,k) can be destroyed by sputum S(i). At the same time, the sputum S(i) will be brken, too, which means that you can only use one sputum once.
If all of the meteors can be destroyed (which means all elements in M are 0), Knuckles wins. Otherwise, he loses.
>
M[i][j]儲存一個n*n的陣列(n<=100)
S[i]儲存一個k的陣列 (升序排列)


## Input
The first line contains two positive integer n and k.
The next n lines, each line contains exactly n numbers, indicating the power of the meteors which will fall onto this place. 0 means no meteor will fall on this place.
The last line contains k numbers, which indicate the power of every sputum. As the description says, the power will be in ascending order.
1 <= n <= 100, 1 <= k <= n*n, and the power of meteors and the power of sputums will be in range [1,10000].
```
5 13
0 0 1 3 4
8 7 4 2 3
0 0 0 0 0
0 0 0 99 0
9 9 9 9 0
2 2 3 4 4 5 8 13 17 21 23 25 108
```


## Output
You should output only one line. If Kunckles wins, output "Victory belongs to the Spitters!", otherwise output "Fly you fool."
```
Victory belongs to the Spitters!
```


## 解題方向
