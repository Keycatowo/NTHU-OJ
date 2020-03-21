#include<stdio.h>


int main(){
    int N;
    int min=2e9,max=-1;
    int tmp;
    int n0;
    scanf("%d",&N);
    scanf("%d",&n0);
    while(N--){
        scanf("%d",&tmp);
        min = min<tmp?min:tmp;
        max = max>tmp?max:tmp;
    }
    if(n0>max)
        printf("%d\n",2*(n0-min));
    else if(n0<min)
        printf("%d\n",2*(max-n0));
    else
        printf("%d\n",((n0-min)+(max-n0))*2);
    return 0;
}
