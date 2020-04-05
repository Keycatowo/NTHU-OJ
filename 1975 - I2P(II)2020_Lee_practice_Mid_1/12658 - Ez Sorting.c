#include <stdio.h>
#include <stdlib.h>

int X [10000];


int cmp (const void *A, const void *B){
    return *(int*)A - *(int*)B;
}

int main(){
    freopen("12658_input.txt","r",stdin);

    int N;
    while(scanf("%d",&N)!=EOF){
        // input
        for (int i=0; i<N; i++){
            scanf("%d",&X[i]);
        }

        qsort(X,N,sizeof(X[0]),cmp);

        for (int i=0; i<(N-1); i++){
            printf("%d ",X[i]);
        }

        printf("%d\n",X[N-1]);
    }
    return 0;
}
