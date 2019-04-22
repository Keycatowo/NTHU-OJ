# Binary Search Tree

## Description
建立一棵Binary Search Tree，實作insert、delete、preorder等函式。



## Input
第一行為一個數字Ｉ，表示有Ｉ個數字被insert。

第二行為Ｉ個被insert的數字。

第三行為一個數字Ｄ，表示有Ｄ個數字被delete。

第四行為D個被delete的數字。

insert的數字不會有重複，delete的數字不一定在BST裡。

1<=Ｉ<=100

1<=Ｄ<=100
```
7
6 8 3 4 5 7 9
5
1 2 3 4 5
```
## Output
印出BST的preorder。

每個node後面接一個空白（即最後一個node後仍有一個空白），印完整棵樹後換行。

若Tree為空，則需印出一行空行。
```
6 8 7 9
```
