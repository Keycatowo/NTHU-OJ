#include "function.h"

int BS_util(int *A,int target,int l,int r)
{
    if(l==r) return r;
    int m=(l+r)/2;
    if(target>A[m]) return BS_util(A,target,m+1,r);
    if(target<A[m]) return BS_util(A,target,l,m);
}
int BS(int *A, int target, int length)
{
    BS_util(A,target,0,length-1);
}
