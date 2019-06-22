#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) (a>b?a:b)

int joseph_problem_formula(int m,int n){
    ///bottom-up
    ///m people, each n kill one ,started from 0
    int live=0;
    for (int i=2;i<=m;i++){
    //    last time is 1->2,so start from 2
    //    first time is m-1->m, so end at m(included)
        live=(live+n+1)%i;
        //    each time mod of n+1
    }
    return live;
}

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF){
        printf("%d\n",joseph_problem_formula(n,k+1)+1);
    }

}
