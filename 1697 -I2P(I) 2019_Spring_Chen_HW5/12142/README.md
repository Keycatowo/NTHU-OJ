# 12142 - Ugandan Knuckles's adventure
## Description
After Knuckles escaped from the dungeon he faced on another difficulty. He meet an elder who claimed that he knew where to find the queen. As long as Knuckles solve the question.

The elder likes "big" . He will give Knuckles n integers, and Knuckles can make a big integer by appending those integers after one another.

For example:

If n = 3, Knuckles have three integers: "71", "87", "22". Following integers can be made:

"718722", "227187", "877122", "228771".......

In this example, 6 such integers can be made. Knuckles  need to find the biggest integer.  In this example, the answer will be "877122".

Help Knuckles find the biggest integer he can make.
>給定n表示有n個數  
排列使得輸出為最大值



## Input


The input will end by EOF.

Each input contains several lines.

First line contains an integer n(1 <= n <= 100).

The following n lines, each line contains an interger ai(1 <= ai <=10^999)

Each testcase contains at most 10 input.

 ```
 4
3115
13521
30747
4856
3
71
87
22
5
21078
18680
4115
13485
10319
```
> 檔案以EOF結尾  
  最多100個數字
  每個數字最長999位


## Output


For each input, print the biggest integer you can make

remember to print \n after each output
```
485631153074713521
877122
411521078186801348510319
```
> 每次輸出記得換行



## 解題方向
初始有兩個想法
1. 暴力列出所有子集並比對
2. 每次從裡面找出最大的輸出

因為考慮到位數問題用數判斷應該都會溢位，先用方法2著手吧

### 方法2 流程
+ 開100個長1000的char陣列作為儲存用
+ 用`while(scanf(%c,)!=EOF)`來處理輸入   
+ 從大到小印出              
  1. 從9印到1(不用考慮0因為沒有0開頭)
  2. 用一個`bool Finished[100]`去檢查陣列是否列印過了
  3. 用一個`bool to_print[100]`去代替list檢查目前要待判斷的數量
  4. 當目前要印的數量=1的時候
    + 印出並標記Finished
  5. 當目前要印的數量>1的時候
    + 從9印到1，到下一位

### 方法1 流程
突然想起來可以設定排序方式就好。
1. 用cmp設定比較大小
2. 用qsort排序
3. 輸出

#### 1941852 WA(3/6)
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define MAX 1000

char strs[SIZE][MAX];
char *ptrs[SIZE];

int compare_str_ptr(const void *a, const void *b)
{
    char **pa;
    char **pb;
    pa = (char **) a;
    pb = (char **) b;
    return -strcmp(*pa, *pb);
}


int main(void)
{
    int i;
    int n;
    //freopen("sample.txt","r",stdin);
    ///input
    while(scanf("%d",&n)!= EOF){
        gets(strs[0]);
        for (i=0; i<n; i++){
            gets(strs[i]);
            ptrs[i] = strs[i];
        }
        qsort(ptrs, n, sizeof(char*), compare_str_ptr);
        for(i=0;i<n;i++)
            printf("%s",ptrs[i]);
        printf("\n");
    }

    return 0;
}
```
2 5 6沒有過。
思考原因，因為要從大排到小，所以我直接在compare那邊加了個負號而已，但是這樣會造成的字串長的排在字串短的前面。
例如`53` `532`排法會變成`53253`，並非最大的。
因此著手在compare那邊改正。

#### 1941869 AC
```
int compare_str_ptr(const void *a, const void *b)
{
    /*
        a is something pointer
        let it be the pointer to pointer to char
        clam pa is a pointer to pointer to char
        *pa is the pointer to char,that means the head of string
    */
    char **pa = (char **) a;
    char **pb = (char **) b;
    int len_a=strlen(*pa),len_b=strlen(*pb);
    int m = min(len_a,len_b);//get the min length of two string
    int cmp = strncmp(*pa,*pb,m);
    int pre_a=0,pre_b=0;
    while(!cmp){
        // same length and same compare
        if( (len_a-pre_a) == (len_b-pre_b) )
            return 0;
        // not same length, keep Euclidean compare
        else if( (len_a-pre_a) >  (len_b-pre_b) ){
            pre_a += m;
            m=min(len_a-pre_a,len_b-pre_b);
            cmp = strncmp(*pa + pre_a, *pb + pre_b,m);
        }
        else{
            pre_b += m;
            m=min(len_a-pre_a,len_b-pre_b);
            cmp = strncmp(*pa + pre_a, *pb + pre_b,m);
        }
    }
    // not same will direct return result
    return cmp;
}
```
> 思考，有絕對的大小嗎還是要看比較的對象呢？

是有絕對的大小的，只要前半部分有出現差異的話即可直接判斷，所以重點和難點會是在後面一邊有一邊沒有的地方。

> 那如果前半一樣，後半就取長度比較短的嗎？

並不行，例如53X和53去比較，如果X>5則會比較大，X<5則會比較小。
所以我想到了用類似輾轉相除的方式去進行輾轉比較，持續把指標起始位置往後退。
不過因為是用持續迴圈的方式，所以記得終止條件要包含兩個字串完全一樣的情況就可以直接return 0了。
