#include <stdio.h>

int GCD(int a,int b){
    if(a==b) return a;
    while(1){
        if(b==0) return a;
        if(a==0) return b;
        if(a>b) a=a%b;
            else b=b%a;
    }
}
int max_gcd(int *Seq,int length){
    int max=0;
    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            if(GCD(Seq[i],Seq[j])>max) max=GCD(Seq[i],Seq[j]);
        }
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("%d\n",max_gcd(A,n));
    return 0;
}
