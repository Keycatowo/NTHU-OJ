#include <stdio.h>
#include <stdlib.h>
#include "Link_list.h"
#define Div(a,b) (a/b+((a%b>0)?1:0))        // ceil(a/b)

int M_Hp[25];
int M_Atk[25];
int spend[25],live[25];
int player_atk,player_hp;


void input(int n){
    int hp,atk,x,y;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&hp,&atk,&x,&y);
        M_Hp[(x-1)*5 + y-1]  = hp;
        M_Atk[(x-1)*5 + y-1] = atk;
    }
}

void reset_spend(){
    for(int i=0;i<25;i++)
    {
        if(M_Atk[i] > 0 && M_Hp[i]>0)
        {
            int player_times;
            player_times  = Div(Hp[i],player_atk);       // player attack monster
            spend[i] = (player_times-1) * M_Atk[i];
        }
    }
}

bool valid(int x){
    if(0<=x<25)
        return true;
    else
        return false;
}

bool solve(int hp){
    List* L = new_list();
    push(L,0);

    while(!is_list_empty(L))
    {
        int index = pop(L);
        if(valid(index+1))

    }
}
int main(){
    freopen("sample.txt","r",stdin);
    int m;
    scanf("%d %d %d",&player_hp,&player_atk,&m);
    input(m);
    if(solve(player_hp))
        printf("HEIR OF FIRE DESTROYED\n");
    else
        printf("YOU DIED\n");
    return 0;
}

