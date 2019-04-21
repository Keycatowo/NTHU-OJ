#include <stdio.h>
char S[1000000];


/*
int max_count(char* Seq,int length){
    int alphabet[26];
    for(int i=0;i<26;i++){
        alphabet[i]=0;
    }
    int tmp;
    for(int i=0;i<length;i++){
        tmp=Seq[i];
        //printf("tmp= %c %c \n",tmp,Seq[i]);
        alphabet[tmp-97]++;
    }
    int max=0;
    for(int i=0;i<26;i++){
        if(alphabet[i]>max) max=alphabet[i];
    }
    return max;
}
void Find(){
    while(scanf("%d\n",&n)!=EOF){
        /// input string
        for(int i=0;i<n;i++){
            scanf("%c",&S[i]);
        }
        /// judge

        if(S[0]==S[n-1]||n%2||max_count(S,n)>(n/2)) printf("NO\n");//aaaaa
        else if(S[0]==S[n/2-1]&&S[n-1]==S[n/2])
            printf("YES\n%c%c\n",S[0],S[n-1]);
    }
}
*/
void Find2(){
    int check;
    int n;
    while(scanf("%d\n",&n)!=EOF){
//        printf("n=%d\n",n);
        check=0;
        /// input string
        for(int i=0;i<n;i++){
            scanf("%c",&S[i]);//先把數列全部吃進來
        }
        ///test
//        for(int i=0;i<n;i++){
//            printf("%c",S[i]);
//        }
//        printf("\n");



        /// judge
        if(n>1) {
            for(int i=1;i<n;i++){
//            printf("[%d %d]:%c %c\n",i-1,i,S[i-1],S[i]);
                if(S[i]!=S[i-1]){
                    check=1;
                    printf("YES\n%c%c\n",S[i-1],S[i]);
                //break;
                }
            }
        }
        if(check==0)printf("NO\n");

    }



}
int main(){
    freopen("12130_sampleIn.txt","r",stdin);
    Find2();
    return 0;
}
