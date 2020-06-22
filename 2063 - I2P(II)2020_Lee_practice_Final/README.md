# 2063 - I2P(II)2020_Lee_practice_Final

## 題目
| 狀態 | 題號            | 題目                                        | tags                        |
| ---- | --------------- | ------------------------------------------- | --------------------------- |
| 1/4  | [11371](#11371) | Polynomial multiplication using linked list | `linked-List`,`PJ`          |
| AC   | [11856](#11856) | Postfix Expression                          | `stack`                     |
| AC   | [11933](#11933) | Vector Dot                                  | `operator overloading`,`PJ` |
| 1/4  | [12306](#12306) | beat the monster                            | `BFS`                       |
|      | [12652](#12652) | Yoshiko And Tentacles                       |                             |
| AC   | [12654](#12654) | Easygoing Yuri                              |                             |
|      | [12692](#12692) | GY's Tree                                   |                             |
|      | [12817](#12817) | Social Distance                             |                             |
| 2/4  | [12839](#12839) | MinMax-Heap                                 | `priority_queue`,`heap`     |

## 11371
### 題目
用linked list實作多項式乘法
### 輸入
+ 兩行測資
    + 每行內有2n個數字
    + 前者為係數，後者為指數(必定包含0次)

```
5 4 -3 2 1 0
-2 3 1 1 0 0
```
### 輸出
+ 降序輸出結果
+ 格式同輸入
+ 最前面加空格
+ 常數0不用輸出

```
 -10 7 11 5 -5 3 1 1
 ```

### 解題
+ 分開處理輸入、計算、輸出
+ 輸入以0結尾做確定
+ 計算把n*m項結果全留下來
    + 排除0x^0資料
    + 其餘全部push 到一個優先佇列，以指數排序
+ 輸出的時候
    + 相同指數累加tmp_data
    + 不同指數輸出之前累加好的tmp_data，並更新tmp_data和tmp_power
    + 最後再輸出一次

[回到目錄](#題目)
## 11856
### 題目
後序表示求值運算
### 解法
用stack操作  
運算時由後序式的前方開始讀取，遇到運算元先存入堆疊，如果遇到運算子，則由堆疊中取出兩個運算元進行對應的運算，然後將結果存回堆疊，如果運算式讀取完 畢，那麼堆疊頂的值就是答案了，

[回到目錄](#題目)
## 11933
[回到目錄](#題目)
## 12306
### 題目
模擬對戰計算  
+ 每回合操作：
    + 升級
    + 攻擊
    + 回血
### 輸入
+ 第一行輸入四個數字
    + 最大等級L
    + 最大血量HP
    + 怪物血量MHP
    + 怪物傷害MDMG
+ 接下來L行
    + 傷害量DMG
    + 回血量HL
+ 模式
    + 玩家先動
    + 怪物打固定值
    + 滿血開始
    + 1等開始

[回到目錄](#題目)
## 12652
[回到目錄](#題目)
## 12654
### 題目
最大重疊區段問題
### 解法
將開始和結束點標記`1`或`-1`push進一個vector  
sort之後遍歷一次把每個位置的sum記錄下來求最大
```c++
sort(all_list.begin(),all_list.end());
  int tmp_step = all_list.at(0).first;
  int d_count = 0;
  int sum = 0;
  int max_count = 0;
  for(auto i:all_list){
    if(tmp_step != i.first){
      tmp_step = i.first;
      sum += d_count;
      max_count = max(max_count,sum);
      d_count = 0;
    }

    d_count += i.second;
  }
```
[回到目錄](#題目)
## 12692
[回到目錄](#題目)
## 12817
[回到目錄](#題目)
## 12839
### 題目
MinMax-Heap  
### 解法
用兩個優先佇列加虛擬長度計算
[回到目錄](#題目)
