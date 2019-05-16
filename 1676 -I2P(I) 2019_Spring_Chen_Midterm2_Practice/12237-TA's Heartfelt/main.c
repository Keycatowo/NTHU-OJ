#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool M[32];
int Output[32];
// 0    Sign
// 1~8  EXp
// 9~31 mantissa

void show(){
    printf("-e2345678m\n");
}

void Dec2Bin(float input){
    /// Sign
    if(input<0){
        M[0]= 1;
        input = -input;
    }
    /// EXP
    int E=floor( log(input) / log(2) );
    int Ma = (int) E;
    Ma = Ma>>E;
//    for(int i=0;i<E;i++)
//        E /=2;
    E +=127;
    for(int i=0;i<8;i++){
        if(E%2) M[8-i] = true;
        E/=2;
    }

    /// Mantissa
    Ma -= 1;
    Ma *=2;
    for(int i=0;i<23;i++){
        if(Ma>=1) M[9+i]=true;
        Ma *= 2;
    }

    /// Output
    for(int i=0;i<32;i++){
        printf("%d",M[i]?1:0);
        M[i] =false;
    }
    printf("\n");
}


void Direct_out(float input){
    /// Sign
    if(input<0){
        Output[0]= 1;
        input = -input;
    }

    int x = *(int*)&input;
    for(int i= 31; i>=1; i--){
        Output[i] = x%2;
        x /= 2;
    }

    for(int i=0;i<32;i++)
    {
        printf("%d",Output[i]);
        Output[i]=0;
    }
    printf("\n");
}

int main()
{
    float A;
    while(scanf("%f",&A) != EOF){
        Direct_out(A);
//        show();
//        Dec2Bin(A);
    }

    return 0;
}
