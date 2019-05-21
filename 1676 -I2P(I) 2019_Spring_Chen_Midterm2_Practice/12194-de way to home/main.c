#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N,Q,q;
int A[1000000];

void show(bool YES){
    if(YES)
        printf("I know de way to your home.\n");
    else
        printf("Wake up, you homeless poor.\n");

}

void solve(){
    scanf("%d",&q);
    int l=0, r=N-1;
    while(l<=r)
    {
        if(l==r){
            show(A[l]==q);
            return;
        }

        int m = l + (l+r)/2;
        if(A[m]==q){
            show(true);
            return;
        }
        else if(q > A[m])
            l = m+1;
        else
            r = m;

    }
    show(false);
}

int main()
{
    scanf("%d %d",&N,&Q);
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<Q;i++)
        solve();
    return 0;
}
