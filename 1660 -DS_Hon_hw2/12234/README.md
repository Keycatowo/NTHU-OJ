# Binary Search Tree

## Description
建立一棵Binary Search Tree，實作insert、delete、preorder等函式。

Insert

1. 若 tree 是空的，則將 node 作為 root。

2. 若 subtree 存在，left subtree 的值皆小於 root，right subtree 的值皆大於 root。

3. 每個 subtree 皆為一個 BST。

Delete：

1. 若是欲刪除的 node 沒有 child，直接刪除。

2. 若是欲刪除的 node 有一個 child，請以他的 child 作為替代。

3. 若是欲刪除的 node 有兩個 child，請以它的 successor (right subtree中最小的值) 作為替代。

4. 若是 tree 中不存在這個值，則無需做任何處理。

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

## 解題方向
1. 插入
2. 刪除
   1. 不存在
   2. 存在
     1. 無子:直刪
     2. 單子:temp儲存目標後把其子接到其父
     3. 雙子:以successor替換後於右子刪除successor
3. Preorder
4. 長度(>0?)

然後這邊稍微談一下刪除(Delete)這件事，原本我一直很卡的地方在於我知道3種不同情況下理論上該怎麼做
但實際上要刪除的時候要考慮到指標的用法，實際做法分成2步
```
node* root=new node(123);
delete root;    //刪除這個指標所指的空間
root = NULL;    //然後再把這個指標指向NULL
```
但以這題為例，如果是2.2.1的情況，即我知道應該要直接刪除那個葉子節點，但我要做的應該是把其父親節點的左或右子樹指標刪除空間和指向NULL才對，但我只能知道往子節點的指標而不知道往父節點的指標，那要怎樣進行呢？
後來查完資料之後發現可以用遞迴呼叫的方式，如本題片段所寫的`root->right = Del(root->right,target);`這樣就可以在父親節點的時候設定其左右子樹指標，在往下子節點的時候清除空間，算是有點小小片段的DFS的感覺吧。

### 1916425(NA 3/4)
#### 測資分析
1. 輸入/刪除 長度不一樣 最後不會是空的
2. 輸入/刪除 長度一樣 最後會變成空的 長度%2==1
3. 輸入/刪除 長度一樣 最後不會是空的 長度%2==0
4. 輸入/刪除 長度一樣 最後不會是空的 長度%2==0
### 1916514(AC)
