#include <stdio.h>
#include <stdlib.h>
int n,k;
int A[20];//0~19

void input();
int compare(const void *,const void *);
void show();
int dfs(int,int);

int main(){

    input();
//    show();
    qsort(A,n,sizeof(A[0]),compare);
//    show();
    printf("%d\n",dfs(0,0));
    return 0;


}

int dfs(int sum,int p){
    /// Termination condition
    if(sum==k) return 1;
    if(sum>k||p==n) return 0;
    /// Recursive
    return (dfs(sum+A[p],p+1)+dfs(sum,p+1));
}


void input(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
}
int compare(const void *a,const void*b){
    return -*(int *)a + *(int *)b;
}
void show(){
    for(int i=0;i<n;i++)
    printf("%d ",A[i]);
    printf("\n");
}
