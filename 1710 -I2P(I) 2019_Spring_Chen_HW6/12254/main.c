#include <stdio.h>
#include <stdlib.h>
#define ULL unsigned long long
typedef struct{
    ULL a11,a12,a13;
    ULL a21,a22,a23;
    ULL a31,a32,a33;
}Matrix;

ULL mod(ULL n){
    return (n%1000000007);
}
Matrix reset(){
    Matrix A;
    A.a11=1; A.a12=2; A.a13=1;
    A.a21=1; A.a22=0; A.a23=0;
    A.a31=0; A.a32=1; A.a33=0;
    return A;
}
Matrix mult(Matrix A,Matrix B){
    Matrix C;
    C.a11 =mod( A.a11*B.a11 + A.a12*B.a21 + A.a13*B.a31 );
    C.a12 =mod( A.a11*B.a12 + A.a12*B.a22 + A.a13*B.a32 );
    C.a13 =mod( A.a11*B.a13 + A.a12*B.a23 + A.a13*B.a33 );

    C.a21 =mod( A.a21*B.a11 + A.a22*B.a21 + A.a23*B.a31 );
    C.a22 =mod( A.a21*B.a12 + A.a22*B.a22 + A.a23*B.a32 );
    C.a23 =mod( A.a21*B.a13 + A.a22*B.a23 + A.a23*B.a33 );

    C.a31 =mod( A.a31*B.a11 + A.a32*B.a21 + A.a33*B.a31 );
    C.a32 =mod( A.a31*B.a12 + A.a32*B.a22 + A.a33*B.a32 );
    C.a33 =mod( A.a31*B.a13 + A.a32*B.a23 + A.a33*B.a33 );

    return C;
}


Matrix fpw(ULL n){
    if(n==1)
        return reset();
    Matrix tmp = fpw(n/2);
    if(n%2)
        return mult(reset(),mult(tmp,tmp));
    else
        return mult(tmp,tmp);
}
void solve(ULL k){
    if(k==1){
        printf("1\n");
        return;
    }
    if(k==2){
        printf("12\n");
        return;
    }
    if(k==3){
        printf("13\n");
        return;
    }

    Matrix A = fpw(k-3);
    ULL ans = mod(A.a11*13 + A.a12*12 + A.a13);
    printf("%llu\n",ans);
}


int main()
{
    int t;
    ULL k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&k);
        solve(k);
    }
//    printf("%llu %llu %llu\n",C.a11,C.a12,C.a13);
//    printf("%llu %llu %llu\n",C.a21,C.a22,C.a23);
//    printf("%llu %llu %llu\n",C.a31,C.a32,C.a33);
    return 0;
}
