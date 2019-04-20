#include <stdio.h>

int W[2*10^5+1];
int A[2*10^5];
int B[2*10^5];
int N;//1~2*10^5
int pos=0;

void input();
void solve();
void eat(int);

int main(){
    freopen("12132_sampleIn.txt","r",stdin);
    input();
    solve();
    return 0;
}




void input(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<=N;i++){
        W[i]=1;
    }
}

void solve(){
    for(int i=0;i<N;i++){
        switch(W[B[i]])//Bi為第幾顆西瓜，W為它是否還在
        {
        case 1:
            eat(B[i]);
            break;
        case 0:
            printf("0");
            break;
        default:
            exit(1);
        }

    }
}

void eat(target){
    for(int i=pos;i<N;i++){
        if(A[i]==target)
        {
            W[A[i]]=0;
            printf("%d",i-pos+1);// count eating how many
            pos=i+1;
            return;
        }
        else
        {
            W[A[i]]=0;
        }
    }

}
