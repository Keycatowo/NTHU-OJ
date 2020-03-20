#include <stdio.h>
#include <stdbool.h>


int people[5005];
bool alive[5005] ;
int N,M;

void reset(){
    for(int i=0;i<5000;i++){
        alive[i] = true;
    }
}


void solve(){
    int n = N;
    int step = M;
    int cur = -1;

    while(n>1){
        step = M%n;// booster the count
        if(step==0)
            step =n;
        while(step>0){
            cur++;
            if(cur==N)
                cur=0;// the end to the head
            if(alive[cur])
                step--;// someone alive -> success move 1
        }
        alive[cur]=false;
        printf("%d ",people[cur]);
        n--;//kill one
    }

//    // kill the last one
    step = 1;
    while(step>0){
        cur++;
        if(cur==N)
            cur=0;// the end to the head
        if(alive[cur])
            step--;// someone alive -> success move 1
    }
    printf("%d\n",people[cur]);

}

int main(){
    freopen("input.txt", "r", stdin);

    while(scanf("%d %d",&N,&M)!=EOF){
        for(int i=0;i<N;i++)
            scanf("%d",&people[i]);// input
        reset();
        solve();
    }


    return 0;
}


