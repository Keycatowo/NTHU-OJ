# 12178 - Queens and Castles   

## Description

There are N queens and M castles in the palace.
The palace is just like a chessboard with size (N+M) * (N+M).
Queen can see all people in 8 directions(←, ↑, →, ↓, ↖, ↗, ↘, and ↙. Just like what queen in the chess does). If any queen see castles or other queens, the mission will fail.
Castle can see all people in 4 directions(←, ↑, →, and ↓. Just like what castle in the chess does). If any castle see queens or other castles, the mission will fail.
Find out the total amount of states that all queens and castles are placed in the palace and mission isn't fail.

## Input
The input contains exactly two numbers N and M, each seperated by a space.

1 <= N+M <= 9.

## Output
Output only one number ── the total amount of states that queens and castles are placed in the palace and mission isn't fail.

Remember to print a '\n' at the end of the output.


## 解題方向

遞迴解solve(Qs,Cs)
  1. 當Qs和Cs都為0的時候，表示放完了，sum++
  2. 對於下一行從0~(N+M)-1個位置
     1. 先確認是否還有剩下要放的 Qs or Cs >0
     2. 檢查是否可以放皇后和城堡
     3. 可以放的話放了之後，solve(Qs-1,Cs)或solve(Qs,Cs-1)
     4. 先拿掉再結束迴圈！
