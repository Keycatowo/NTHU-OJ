# Binary Tree Recovery

## Description
給定 Binary Tree (BT) preorder (or postorder) traversal 跟 inorder traversal 的結果，就有辦法重建 BT。

preorder + inorder -> postorder：
給定 preorder traversal 跟 inorder traversal 的結果後，重建 BT，並印出 postorder traversal 的結果。

postorder + inorder -> preorder：
給定 postorder traversal 跟 inorder traversal 的結果後，重建 BT，並印出 preorder traversal 的結果。

Hint：以 BT 的角度而言，preorder 跟 postorder 是一體兩面。

## Input
總共有 6 行：
(1) 整數 N_0，代表 BT_0 中 node 的數量
(2) BT_0 preorder traversal 的結果
(3) BT_0 inorder traversal 的結果
(4) 整數 N_1，代表 BT_1 中 node 的數量
(5) BT_1 postorder traversal 的結果
(6) BT_2 inorder traversal 的結果

每個 node 都有自己的 unique integer index，0 < index < 2^31
0 < N_0 <= 10^5
0 < N_1 <= 10^5
```
10
1 2 4 8 9 5 10 3 6 7
8 4 9 2 10 5 1 6 3 7
8
1 5 4 7 3 2 6 8
1 5 7 4 8 3 6 2
```

## Output
總共有 2 行：
(1) BT_0 postorder traversal 的結果
(2) BT_1 preorder traversal 的結果

postorder 或 preorder traversal 的結果輸出格式：
每個 index of node 後面加一個空格，最後加一個換行字元結尾。
```
8 9 4 10 5 2 6 7 3 1
8 7 3 1 4 6 3 2
```
