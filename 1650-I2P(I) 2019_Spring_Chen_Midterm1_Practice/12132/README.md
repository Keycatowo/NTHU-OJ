# 12132 - too many watermelons  

## Description
Ovuvuevuevue Enyetuenwuevue Ugbemugbem Osas wants to eat watermelon.

He has n watermelons and each one has a specific index denote as ai. The watermelons are store in a cylindrical(圓柱狀) box. Osas wants to eat a watermelon indexed ai. But if the watermelon indexed ai is not on the top, he needs to eat all watermelon above the watermelon indexed ai.

For example if the index of watermelon from top to bottom is: 5, 3, 2, 1, 4. And Osas wants to eat watermelon which index is 2, then he need to eat watermelons which index are 5, 3, 2 at the same time.

Osas has a list which is the order of index of watermelons he wants to eat which denoted as bi. The length of the list is also n and all bi are distinct. Please help him calculate that each time he wants to eat a watermelon, how many watermelons he needs to eat at same time?

For example if the index of watermelon from top to bottom is: 5, 3, 2, 1, 4. And the list Osas has is: 2, 3, 4, 5, 1.

First time Osas will eat 3 watermelons(5,3,2). Second time because the watermelons that indexed 3 is already been eaten, Osas eat 0 watermelon . So on and so forth.

In this example, you need to output: 3 0 2 0 0.
> A序列為西瓜編號順序
  B序列為要吃的順序
  每次在B中的序號要吃的西瓜從A處找，需要按順序吃
  如果已經吃過了就輸出0


## Input
input contains three lines.

First line contains n the number of watermelons.( 1 <= n <= 2*10^5 )

Second line contains n integer a1 ~ an which denote as the index of watermelons from top to bottom .( 1 <= ai <= n )



Third line contains n integer b1 ~ bn which denote as the order of the index that Osas' wants to eat.( 1 <= bi <= n )
> 3行輸入
  西瓜數 N
  A序列
  B序列

```
5
5 3 2 1 4
2 3 4 5 1
```


## Output
output contains one line.

output n integer means the number of watermelons that each time Osas eat. Separate each number by a blank but don't print the blank after the last number.

remember to print \n at the end of output.
> 1行輸出
  每次要吃掉的數量
```
3 0 2 0 0
```

## 解題想法
1.  開一個陣列W儲存所有西瓜狀態(吃掉0/還在1)
2.  從B序列開始迴圈
      每次先看W中是否被吃掉(被吃掉了就直接輸出0)
      如果沒被吃掉再去A中找要吃幾次
3.  應該要加一個記錄目前吃到哪裡的位置記錄P，這樣就不用每次要吃的時候都從頭開始
4.  題目輸出為空格方式輸出，把直接輸出儲存起來一次輸出


### 1901410 NA(1/6)
```
#include <stdio.h>

int W[2*10^5+1];    // 1/0: Is watermelon alive?
int A[2*10^5];      // watermelon storage sequence
int B[2*10^5];      // watermelon eat sequence
int N;              // 1~2*10^5
int pos=0;          // now place to eat(index to A_seq)
int R[2*10^5];      // store the answer waiting to print

void input();
void solve();
void eat(int,int);
void output();

int main(){
    freopen("12132_sampleIn.txt","r",stdin);
    input();
    solve();
    output();
    return 0;
}




void input(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<=N;i++){
        W[i]=1;
    }
}

void solve(){
    for(int i=0;i<N;i++){
        switch(W[B[i]])//Bi為第幾顆西瓜，W為它是否還在
        {
        case 1:
            eat(B[i],i);
            break;
        case 0:
            //printf("0");
            R[i]=0;
            break;
        default:
            exit(1);
        }

    }
}

void eat(target,store){
    for(int i=pos;i<N;i++){
        if(A[i]==target)
        {
            W[A[i]]=0;
            //printf("%d",i-pos+1);// count eating how many
            R[store]=i-pos+1;
            pos=i+1;
            return;
        }
        else
        {
            W[A[i]]=0;
        }
    }

}

void output(){
    for(int i=1;i<N;i++){
        printf("%d ",R[i-1]);
    }
    printf("%d\n",R[N-1]);
}
```
1. AC
2. RTE
3. WA
4. RTE
5. RTE
6. RTE
