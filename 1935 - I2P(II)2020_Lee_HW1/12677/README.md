# Hunter Likes Cypher :)   

## Description
"wo jiau ni funky na ge niu hai i i i ~~~"

Hunter likes to dance, and joined the nthu pop dance club.

One day he asked Jeff , Joshua , Bena , Ricky ... to form a circle to cypher, they used to spin a bottle to determine who is the next one.

But today they want to do it in another way, they count from 0th member M times, so the (M-1)th member solos, when he/she finishes, he/she will be removed from the circle, and count from mth person m times again...

Until every members have soloed.

Now Hunter wanna know the solo's order, can you help him?

## Input
There will be multiple testcases in each input file, but no more than 10

Two integer N, M, in first line, N means the numbers of members in the circle.

And N integers Ai in the second line which means the index of ith member , 0 <= i < N , 0 <= Ai < N

1 <= N <= 5000
1 <= M <= 1000
```
4 5
2 0 3 1
3 7
1 2 0
```

## Output
Output the solo's order.
```
2 3 1 0
1 2 0
```


## 解題方向
+ 約瑟夫問題
+ 印出過程
