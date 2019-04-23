# 1650 第一次期中題目

## 12130 - Oh! I find de way!
1. 不定次數輸入 `while(scanf("%d\n",&n)!=EOF)`
2. 題目保證唯一good string解 -> 第一次不同`if(S[i]!S[i-1])`
3. C語言無內建指數`char S[1000000]`

## 12132 - too many watermelons
1. 使用好不同陣列做記錄
  1. 西瓜存活狀態 W[i]
  2. 西瓜擺放狀態 A[i]
  3. 西瓜欲吃順序 B[i]
  4. 答案儲存陣列 R[i]
2. 從B走迴圈
  1. 先判斷存活 W[B[i]]
  2. 死了 -> R[i]=0
  3. 活著 ->
    1. 從 A[i++=pos] 開始吃
    2. 吃到 容器內指的A[i]==目標B[i]為止 (記得i<N才繼續吃)
    3. R[i]=i-pos+1 (線段頭尾包含，長度為差值+1)
    4. pos=i+1，下次從下一顆開始吃
3. 在R輸出結果

## 12133 - Yes papa  
1. 以 `(Al,Ar,Bl,Br)`分別記錄兩個陣列的頭尾丟入遞迴
  1. 奇數：判斷相等
  2. 偶數：拆兩部分丟遞迴
    1. 前半: l,(l+r)/2
    2. 後半: (l+r)/2+1,r
2. 使用`stdbool.h`

## 12137 - Johnny Johnny
1. DFS遞迴 每次要選/不選
2. 遞迴(sum,position)
  1. 最終回傳1/0 表成立/不成立
  2. 每次遞迴(要加，下一步)+(不要加，下一步)
3. 優化使用`qsort(A,n,sizeof(A[n]),cpmpare)`
```
int cpmpare(const void *A ,const void *B){
    return *(int *)A - *(int *)B; //升,降的話改正負
}
```

### 12140 - HaSaKi~
1. 問題簡單大量 -> 使用答案陣列儲存
2. 以頭儲存累積次數，0 to N-n
3. (l,r)計算差值
  1. 左邊不含
  2. 右邊含，但位移n
  3. times[r-n+1]-times[l-1]
4. 畫離散方格圖幫助思考
![Fig 1](\12140\Fig1.png)
![Fig 2](\12140\Fig2.png)
