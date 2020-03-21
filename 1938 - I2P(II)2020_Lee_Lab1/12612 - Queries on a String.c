#include<stdio.h>

char S[10000];
char tmp[10000];

int main(){
    //freopen("input.txt","r",stdin);

    int N;
    int L,R,K;
    int tar;
    gets(S);

    scanf("%d",&N);
    while(N--){
        scanf("%d %d %d",&L,&R,&K);

        int length = R-L+1;

        // save
        for(int i=0;i<length;i++){
            tmp[i]=S[L+i-1];
        }

        // load
        for(int i=0;i<length;i++){
            tar = i-K;
            while(tar<0)
                tar += length;
            tar = tar%length;
            S[L+i-1] = tmp[tar];
        }

//        printf("%d %d %d\n",L,R,K);
    }

    puts(S);
    return 0;
}
