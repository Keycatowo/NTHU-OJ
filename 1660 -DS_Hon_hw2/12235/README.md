# 12235-Minimums around Node

## Description
給定一 K-ary Tree (KT)：
(1) K-ary 代表 KT 中每個 node 有最多 K (有限正整數) 個 children。
(2) KT 中有 N 個 nodes。
(3) 每個 node 都有 unique postive integer index (1 ~ N)。
(4) node v 意指 index 為 v 的 node。

假設有兩個 nodes，node x 和 node y：
(1) path(x, y)：
代表從 node x 出發到 node y 結束的 (unique) simple path (nodes 的序列、nodes 不能重複)。
e.g. path(x, y) = (x, z, w, y)。

(2) |path(x, y)|：
代表 path(x, y)的長度。
 e.g. 如果 path(x, y) = (x, z, w, y)，|path(x,y)| = 4 。

(3) d(x, y):
代表 node x 和 node y 之間的距離，亦即為 |path(x, y)| -1 (= |path(y, x)| - 1)。

給定起始點 node B (begin)：
(1) 令 node C (closest) 為距離 node B 最近的 leaf (包含 node B 自己) ，若有多個 leaves 則定義為 index 最小的那個 leaf。
(2) 令 node F (farthest) 為距離 node B 最遠的 leaf (包含 node B 自己)，若有多個 leaves 則定義為 index 最小的那個 leaf。

令 mi (i 為非負整數) 為符合 d(B, v) = i 的所有 node v 中，最小的 v；如果沒有 node 符合，mi = 0。

![Fig 1](Fig1.jpg)

上面這張是 sample testcase 的圖示，題目敘述的變數、符號、定義用這張圖來舉例即是：
(1) K：3
(2) N：10
(3) path(7, 6)：(7, 2, 1, 3, 6)
(4) |path(7, 6)|：5
(5) d(7, 6)：|path(7, 6)| - 1 = 5 - 1 = 4
以下假設 B 為 7：
(6) C：8
(7) F：5

Hint：DFS 跟 BFS

## Input
第一行為 N，代表 KT 中 nodes 的總數，0 < N ≦ 2^16。
第二行為 B，代表起始點的 index。
接下來若干行皆是 (u,v) ，代表 node u 跟 node v 之間有相連，u, v 即為 index。
```
10
7
1 2
1 3
1 4
2 7
3 5
3 6
7 8
7 9
7 10
```

## Output
請輸出  Σm_i ，1 ≦ i ≦ d(B,F) - d(B,C)。
```
6
```

## 解題方向
1. 最近葉子距離:BFS
   1. 距離k++
   2. 是否為葉子，有葉子的時候停止
2. 最遠葉子距離:DFS
   1. 距離k++
   2. 往下
   3. 是葉子，回傳/不是葉子，捨棄
3. 距離為mi時，最小的節點V:BFS

### 資料結構-以二元樹表K元樹
左子樹表子節點，右子樹表兄弟節點
以Example為例
>
1
|
2 - 3 - 4
|   |
7   5-6
|
8-9-10

如果一個節點是葉子，則其無左子樹。(8 9 10 5 6 4)
但發現好像這樣的話不知道該如何建立(或是說每次建立都要搜尋一次似乎很消耗時間)
### 資料結構-無向圖
有n個頂點，用n個Linked list存放圖形，每個list代表一個頂點以及與其相鄰的點
以Example為例
>
1-2-3-4
2-1-7
3-1-5-6
4-1
7-2-8-9-10
5-3
6-3
8-7
9-7
10-7
