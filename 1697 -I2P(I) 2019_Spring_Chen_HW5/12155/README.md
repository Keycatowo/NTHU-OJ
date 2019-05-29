# 12155 - Cat-Toast crisis

## Description
Recently, scientists finally find a way to produce unlimited energy. The scientists call it "Cat-Toast".

In case that someone might not know:
While buttered toast falls onto the ground, it will always land with its buttered side - Falling Toast Theorem(FTT)
While cats fall onto the ground, they will always land with their four feets. - Falling Cat Theorem(FCT)
By FTT, we can assume that if we put butter on both sides of the toast, we might create a perpetual motion machine, because by FTT, we know that the buttered side will land onto the ground. However, there are two buttered sides. If any side of the toast lands, there will be a contradiction, so the toast will never fall and continue spinning around. We can apply the same way on FCT.
However, there is a big problem. if we just put two buttered toasts or two cats together, there will be no momentum, and obviously it won't spin except for any external force, which cannot be a perpetual motion machine. This problem had confused scientists for centuries.
Recently, scientists finally got a breakthrough progress. They combined a cat and a buttered toast and it just spins by itself! Due to the difference mass of a cat and a buttered toast, the machine itself will provide the momentum to spin, and it will never fall onto the ground (due to the contradiction we proved before), the first perpetual motion machine was born!

The original video is here.



Scientists found that if two cat-toasts' distance are equal to or closer than r, there will be a collision which cause a small black hole and soon disappear, which is very dangerous. The cat-toast must be secured separately. Also, if there are multiple cat-toasts that will collide, those cat-toasts will all collide together and spawn exactly one black hole. If there's any problem, you may refer to Sample I/O.
One day in NTHU, a servitor just carries a lot of cat-toasts, each with a secured box. He accidently falls down and all the cat-toasts just drop out of their own boxes.
Now given r and all the coordinates of all cat-toasts, the servitor wants to know how many cat-toasts remains there after some destructive collisions and how many black holes spawned.

Note that the distance of two cat-toasts is sqrt( (x1-x2)^2 + (y1-y2)^2 ), where (x1,y1) and (x2,y2) are the coordinates of this two.
> 有n個點  
  任意兩個點距離小於r的時候會算作同一個黑洞

## Input
The first line contains two integers n, r, indicate the number of cat-toast, the distance r decribed above.
The next n lines, each line contains two integers xi, yi, indicates the location of the i-th cat-toast.
1 <= n <= 1000, 1 <= r <= 10^4
1 <= xi, yi <= 10^4
```
6 4
1 7
1 3
5 3
5 15
1 15
500 500
```
> 最多1000個點，位置都是int
  距離最多到10000

## Output
The first line of the output is the total number of cat-toasts that still remains and the total number of black holes after collisions, separated by a space.
Remember to output a '\n' at the end of the output.
(In fact, expect for the problem DO ask you not to output a '\n' at the end of the output, mostly you shoul output a '\n' at the end.)

Take Sample I/O as an example, obviously cat-toast located at (5,15) and (1,15) will collide. (1,7), (1,3), and (5,3) will collide together because (1,7), (1,3) collides, and (1,3), (5,3) collides, just like a chain, or a tree.

There's only one remaining cat-toast located at (500,500) and spawned 2 black holes, so the answer is "1 2" without quotes.
```
1 2
```
> 輸出黑洞數量 和未成為黑洞的點的數量


## 解題過程
這題應該可以用DFS解，但因為測資數量很小所以就很想先暴力做看看XD
### 暴力解
1. 對於每個點都對全部點(實際上是三角往後即可)都求距離
2. 如果距離有小於的話根據雙方是否已經有group的條件去設
   1. 兩方都沒，都設成兩方小的那個
   2. 一方沒有
     1. 沒有的比較小→把有的全部更新
     2. 沒有的比較大→把沒有的設成有的那個
   3. 兩方都有，把大的那方全更新成小的那方
#### 1941954 AC (最慢8ms)
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define min(a,b) (a<b?a:b)
#define MAX 1005

typedef struct point{
    int x;
    int y;
    int group;
}Point;
Point List[1001];
int ans[1000];
int n,r,lonely;

void input(){
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++){
        scanf("%d %d", &List[i].x, &List[i].y);
        List[i].group = MAX;
    }
}

double distance(Point A, Point B){
    return sqrt( (A.x-B.x)*(A.x-B.x) +
                 (A.y-B.y)*(A.y-B.y) );
}

void set_to(int from, int to){
    for(int i=0;i<n;i++){
        if(List[i].group == from)
            List[i].group = to;
    }
}
bool is_close_enough(int A,int B){
    return (distance(List[A],List[B]) <= r);
}
int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
int count(){
    int sum=0;
    lonely =0;
    for(int i=0;i<n;i++){
        ans[i] = List[i].group;
    }
    qsort(ans,n,sizeof(int),cmp);
    if(ans[0]==MAX) lonely++;
        else sum++;
    for(int i=1;i<n;i++){
        if(ans[i]!=ans[i-1] && ans[i]!=MAX)
            sum++;
        if(ans[i]==MAX)
            lonely++;
    }
    return sum;
}
int main()
{
    //freopen("sample.txt","r",stdin);
    input();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(is_close_enough(i,j))
            {
                if(List[i].group==MAX)
                {
                    if(List[j].group == MAX)
                        List[i].group=List[j].group = min(i,j);
                    else if(List[j].group <= i)
                        List[i].group = List[j].group;
                    else
                    {
                        List[i].group = i;
                        int from=List[j].group,to=i;
                        set_to(from,to);
                    }
                }
                else
                {
                    if(List[j].group == MAX)
                        List[j].group = List[i].group;
                    else if(List[i].group < List[j].group)
                    {
                        int from=List[j].group,to=List[i].group;
                        set_to(from,to);
                    }
                    else
                    {
                        int from=List[i].group,to=List[j].group;
                        set_to(from,to);
                    }
                }


            }
        }
    }
    printf("%d %d\n",lonely,count());

    return 0;
}
```
