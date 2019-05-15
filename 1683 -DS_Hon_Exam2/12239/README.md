# 12239 - Distance from Node  

## Description
給定一 K-ary Tree (KT)：
(1) K-ary 代表 KT 中每個 node 有最多 K (有限正整數) 個 children。
(2) KT 中有 V 個 nodes。
(3) 每個 node 都有 unique non-negative integer index (0 ~ V-1)。
(4) node v 意指 index 為 v 的 node。

假設有：
(i) 兩個相鄰 (中間只隔一條 edge ) 的 nodes，node u 和 node v。
(ii) 兩個不一定相鄰的 nodes，node x 和 node y。

以下定義：
(1) path(x, y)：
代表從 node x 出發到 node y 結束的 (unique) simple path (nodes 的序列、nodes 不能重複)。
e.g. path(x, y) = (x, z, w, y)。

(2) d(x, x)：
代表 node x 到自己的距離，定義成 0。

(3) d(u, v)：
代表相鄰的 node u 和 node v 之間的距離，定義成 max{u, v}。

(4) d(x, y)：
代表 node x 和 node y 之間的距離。
e.g.
(i) 如果 path(x, y) = (x)，d(x, y) = d(x, x) = 0。
(ii) 如果 path(x, y) = (x, y)，d(x, y) = max{x, y}。
(iii) 如果 path(x, y) = (x, w, z, y)，d(x, y) = d(x, w) + d(w, z) + d(z, y)。

給定起始點 node S (start)：
(1) 令 node F (farthest) 為距離 node S 最遠的 leaf，若有多個 leaves 則定義為 index 最小的那個 leaf。




上面這張是 sample testcase 的圖示，題目敘述的變數、符號、定義用這張圖來舉例即是：

(1) K：3
(2) V：7

以下假設 S 為 5：

(1) path(S, leaf)：
path(5, 3)：(5, 2, 0, 3)
path(5, 4)：(5, 2, 0, 1, 4)
path(5, 5)：(5)
path(5, 6)：(5, 2, 6)

(2) d(S, leaf)：
d(5, 3)：d(5, 2) + d(2, 0) + d(0, 3) = max{5, 2} + max{2, 0} + max{0, 3} = 5 + 2 + 3 = 10
d(5, 4)：d(5, 2) + d(2, 0) + d(0, 1) + d(1, 4) = max{5, 2} + max{2, 0} + max{0, 1} + max{1, 4} = 5 + 2 + 1 + 4 = 12
d(5, 5)：0
d(5, 6)：d(5, 2) + d(2, 6) = max{5, 2} + max{2, 6} = 5 + 6 = 11

(3) F：4
(4) d(S, F)：d(5, 4) = 12

## Input
第一行為 V：
代表 KT 中 nodes 的總數，1 ≦ V ≦ 216。

接下來若干行皆是 (u, v) ：
代表 node u 跟 node v 之間有 edge。

最後一行為 S：
代表起始點的 index。

## Output
請輸出 d(S, F)。
