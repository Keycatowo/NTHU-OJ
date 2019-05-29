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
    freopen("sample.txt","r",stdin);
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
