#include <stdio.h>
char A[100000];
char B[100000];

bool is_equal(char *a,char *b,int start,int end){
    /// 直接相等
    // a1==b1 a2==b2
    bool all_same=true;
    for(int i=start;i<=end;i++){
        if(a[i]!=b[i]) all_same=false;
    }
    if(all_same) return true;
    /// 特殊規則
    // a1==b2 a2==b1
    if((start-end)%2)//長度為偶數，才可分割
    {
        return(is_equal(a,b,))
    }
    else return false;



}

