#include <stdio.h>
#define FILE_MODE 1
#define DEBUG_MODE 0
#define show(st,vb) (DEBUG_MODE)?printf(st,vb):1
#define show2(st,vb1,vb2) (DEBUG_MODE)?printf(st,vb1,vb2):1
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b


short N[500000];
int n,k,L=1;

void input(){

    scanf("%d %d\n",&n,&k);
    int cur=0;
    char tmp,pre;
    scanf("%c",&pre);
    N[0]=1;

    for(int i=1;i<n;i++){
        scanf("%c",&tmp);
        if(tmp!=pre){
            show2("%c!=%c\n",pre,tmp);
            cur++;
            pre=tmp;
            N[cur]=1;
            L++;
        }
        else{
            show2("%c==%c\n",pre,tmp);
            N[cur]++;
        }
    }

}

void output(){
    int upper = L-k+1;
    show("%d\n",upper);
    int m=50000000,M=0;
    int tmp;
    for (int i=0; i<upper; i++){
        tmp=0;
        for (int j=0; j<k; j++){
            tmp += N[i+j];
        }

        m = min(tmp,m);
        M = max(tmp,M);
    }

    printf("%d %d\n",M,m);
}

int main(){
    (FILE_MODE)?freopen("12655_input.txt","r",stdin):1;

    input();
    output();


    return 0;
}
