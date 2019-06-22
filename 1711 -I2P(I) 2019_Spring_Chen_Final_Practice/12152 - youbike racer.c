#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MAX_SIZE 100000


int n,k;
int Station[MAX_SIZE];

void input(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&Station[i]);
}

void min_step(){
    int sum=0,pos=0,flag=0,finish=Station[n-1];
    while(pos<finish){
        if((Station[flag] - pos) <=k)
            flag++;
        else
        {
            pos = Station[flag-1];
            sum++;
            if((Station[flag] - pos) > k)
            {
                printf("The Legend Falls.\n");
                return;
            }
        }
        if((finish - pos) <= k)
            break;
    }
    printf("%d\n",sum);

}

int main(){
    input();
    min_step();
    return 0;
}

