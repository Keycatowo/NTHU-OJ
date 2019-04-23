#include <stdio.h>
#include <stdbool.h>
char S[1000000];

void Find2();


int main(){
    freopen("12130_sampleIn.txt","r",stdin);
    Find2();
    return 0;
}

void Find2(){
    bool check;
    int n;
    while(scanf("%d\n",&n)!=EOF){
        check=false;
        /// input
        for(int i=0;i<n;i++){
            scanf("%c",&S[i]);
        }

        /// judge
        if(n>1) {
            for(int i=1;i<n;i++){
                if(S[i]!=S[i-1]){
                    check=true;
                    printf("YES\n%c%c\n",S[i-1],S[i]);
                }
            }
        }

        if(!check)printf("NO\n");

    }

}
