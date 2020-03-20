#include <stdio.h>
#include <stdbool.h>


int people[5005];
bool alive[5005] ;
int N,M;

void solve(){
    int n = N;
    int mov = M;
    int cur = -1;
    while(n>1){
        mov = M%n;// booster the count
        while(mov>0){
            cur++;
            if(cur==N)
                cur=0;// the end to the head
            if(alive[cur])
                mov--;// someone alive -> success move 1

        }

        alive[cur]=false;
        printf("%d ",people[cur]);
        n--;//kill one
    }
    // kill the last one
    mov = 1;
    while(mov>0){
        cur++;
        if(cur==N)
            cur=0;// the end to the head
        if(alive[cur])
            mov--;// someone alive -> success move 1
    }

    alive[cur]=false;
    printf("%d\n",people[cur]);
    n--;//kill one
}

int main(){
    freopen("input.txt", "r", stdin);


    while(scanf("%d %d",&N,&M)!=EOF){
        // input
        for(int i=0;i<N;i++){
            scanf("%d",&people[i]);
            alive[i] = true;
        }
        //solve
        solve();
    }


    return 0;
}


