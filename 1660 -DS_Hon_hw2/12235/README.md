# Minimums around Node

## Description
給定一 K-ary Tree (KT)：
(1) K-ary 代表 KT 中每個 node 有最多 K 個 children，K 是一個正整數。
(2) KT 中有 N 個 nodes，每個 node 都有 unique postive integer index (from 1 to N)。

假設有兩個 nodes，X 和 Y：
(1) path(X,Y):
代表從 X 出發，走到 Y 結束中所有 nodes (不能重複，i.e. simple path) 的序列 (包含 X 和 Y)。
|path(X,Y)| 代表序列的長度，( e.g. 如果 path(X,Y) = X, Z, W, Y，那 |path(X,Y)| = 4 )。

(2) d(X,Y):
代表 X 和 Y 之間的距離，
亦即為 |path(X,Y)| -1 (或是 |path(Y,X)| - 1)。

給定起始點 B (Beginning node)：
(1) 令 C 為距離 B 最近的 leaf (Closest leaf from B) ，若有多個 leaves 則定義為 index 最小的那個 leaf。
(2) 令 F 為距離 B 最遠的 leaf (Farthest leaf from B)，若有多個 leaves 則定義為 index 最小的那個 leaf。

令 m_i (i 為正整數) 為符合 d(B, V) = i 的所有 nodes (V) 中，index 最小那個 node 的 index；如果沒有 node 符合，m_i = 0。  

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
