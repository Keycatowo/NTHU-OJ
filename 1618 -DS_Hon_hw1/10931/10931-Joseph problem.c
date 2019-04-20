#include <stdio.h>

int joseph_problem_recursive(int m,int n){
    ///top-down
    ///m people, each n kill one ,started from 0
    if (m==1) return 0;// if only one people, he will be alive
        else return (joseph_problem_recursive(m-1,n)+n+1)%m;
        //    after each one turn
        //    convert the problem to
        //    less one people,and start from the next of killed
        //    so mod the number of all people(now),
        //    and always plus n+1 because of the killed one
}
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
    freopen("10931ShareSample.txt", "r", stdin);
    int a,b,T,sum=0;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d %d",&a,&b);
        sum+=joseph_problem_formula(a,b+1)+1;
        // because of the define of problem is different
        // the frequency of OJ10931 should +1 to be usually Joseph problem
    }
    printf("%d\n",sum);
    return 0;

}
////
////cost time
////OJ 12176
////recursive 0 4 4 8
////formula 0 0 4 4
