#include <stdio.h>

int W[200001];    // 1/0: Is watermelon alive?
int A[200000];      // watermelon storage sequence
int B[200000];      // watermelon eat sequence
int N;              // 1~2*10^5
int pos=0;          // now place to eat(index to A_seq)
int R[200000];      // store the answer waiting to print

void input();
void solve();
void eat(int,int);
void output();

int main(){
    freopen("12132_sampleIn.txt","r",stdin);
    input();
    solve();
    output();
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
            eat(B[i],i);
            break;
        case 0:
            //printf("0");
            R[i]=0;
            break;
        default:
            exit(1);
        }

    }
}

void eat(target,store){
    for(int i=pos;i<N;i++){
        if(A[i]==target)
        {
            W[A[i]]=0;
            //printf("%d",i-pos+1);// count eating how many
            R[store]=i-pos+1;
            pos=i+1;
            return;
        }
        else
        {
            W[A[i]]=0;
        }
    }

}

void output(){
    for(int i=1;i<N;i++){
        printf("%d ",R[i-1]);
    }
    printf("%d\n",R[N-1]);
}
