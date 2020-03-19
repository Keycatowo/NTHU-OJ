# reverse linked list


## Description
Given a link list structure named Node.


```
typedef struct _Node {

    int data;

    struct _Node *next;

} Node;
```

Use this structure to implement a reversing linked list.



You will be provided with main.c and function.h, and asked to implement function.c.

For OJ submission:

       Step 1. Submit only your function.c into the submission block. (Please choose c compiler)

       Step 2. Check the results and debug your program if necessary.

## Input
The input contains a sequence of positive integers as the linklist and the order, except the last one, which is -1, indicating the end of the sequence.
```
4 7 8 9 10 7 -1
```


## Output
The output contains the sequence of resulting linklist.
```
7 10 9 8 7 4
```


## 解題方向
### CreateList
+ 創建新節點`Node* head = (Node*)malloc(sizeof(Node));`
+ 讀取資料的時間點
    + 每次循環的一開始
+ 結束時間點
    + 下一筆資料是`-1`的時候結束
    + `cur->next=NULL`
+ 移動的時間點
    + 下一筆資料不是`-1`的時候移動
    + `cur = cur->next`
+ 創建節點的時間點
    + 下一筆資料不是`-1`的時候創建

+ **每次的操作都是對`cur->next`操作**
    + head要先處理
    + n=-1：設成NULL
    + n!=-1：存到data/創建節點/移動到next

### reverse
+ 設定一個滑動的窗口
    + left
    + cur
    + righr

+ 每次循環
    + 動作1：變更cur節點的next指標`cur->next=left`
    + 動作2：移動窗口
        + `left = cur`
        + `cur = right`
        + `right = right->next`
    + 動作3：檢查結尾`if(right==NULL)`
        + 執行一次動作1 (**容易漏掉要小心**)
        + 設定`head = cur`及回傳
