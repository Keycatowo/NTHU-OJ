#include "function.h"
#include <stdlib.h>
int HP[MAX_N*MAX_N];



int compare(const void *A, const void *B){
    return *(int*)A - *(int*)B;
}

void two2one(int N, int S[MAX_N][MAX_N],int *H){
    for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			H[i*N+j]=S[i][j];
}



int solve(int *n, int *k, int *sputum, int (*spell)[MAX_N]){
    int N=*n, K=*k;
    two2one(N,spell,HP);
    qsort(HP,N*N,sizeof(HP[0]),compare);

    int Atk=0, Def=0;
    int matrix_size= N*N;
    while(Def < matrix_size)
    {
        if(HP[Def]==0)
            Def++;
        else
        {
            if(sputum[Atk] >= HP[Def])  // successful
            {
                Atk++;
                Def++;
            }
            else
            {
                Atk++;
                if(Atk >= K)
                    return 0;
            }
        }

    }
    return 1;
}
