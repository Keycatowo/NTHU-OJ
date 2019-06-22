#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int n,k;


typedef struct item{
    int today;
    int tomorrow;
}T;
T items[100000];

int cmp(const void *a,const void *b){
    T *A =(T*)a;
    T *B =(T*)b;
    if((A->today-A->tomorrow) == (B->today-B->tomorrow))
        return 0;
    if((A->today-A->tomorrow) > (B->today-B->tomorrow))
        return 1;
    else
        return -1;
}



int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&items[i].today);
    for(int i=0;i<n;i++)
        scanf("%d",&items[i].tomorrow);
    qsort(items,n,sizeof(T),cmp);
    int i;
    long long int sum=0;
    for(i=0;i<k;i++)
        sum += items[i].today;
    for(;i<n;i++)
        sum += min(items[i].tomorrow,items[i].today);
    printf("%lld\n",sum);
    return 0;
}
