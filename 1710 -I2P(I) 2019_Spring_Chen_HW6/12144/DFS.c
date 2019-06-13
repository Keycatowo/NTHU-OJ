#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Div(a,b) (a/b+(a/b)?1:0)

int player_hp,player_atk,pos_x,pos_y;
bool M[5][5];
int Hp[5][5];
int Atk[5][5];
bool visited[5][5];

void input(int n){
    int hp,atk,x,y;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&hp,&atk,&x,&y);
        M[x-1][y-1]   = true;
        Hp[x-1][y-1]  = hp;
        Atk[x-1][y-1] = atk;
    }
}

int battle(int x,int y,int now_hp){
    if(!M[x][y]) return now_hp;
    int player_times,monster_times;
    player_times  = Div(Hp[x][y],player_atk);
    monster_times = Div(now_hp,Atk[x][y]);
    if(player_times >= monster_times)
    {
        now_hp -= (player_times-1)*Atk[x][y];
//        M[x][y] = false;
        return now_hp;
    }
    else
        return -1;
}


bool edge_check(int x,int y){
    if(x<0 || y<0 || x>=5 || y>=5) return false;
        else return true;
}



bool DFS(int x,int y,int now_hp){
    /// died of arrive
    if(now_hp<=0) return false;
    if(x==4 && y==4) return true;

    bool check = false;

    // go left or right
    for(int i=-1;i<=1;i+=2)
    {
        if(edge_check(x+i,y))
        {
            if(!visited[x+i][y])  // haven't go there
            {
                visited[x+i][y] = true;
                int result = battle(x+i,y,now_hp);
                if(result==-1)
                    check = check || false;
                else
                    check = check || DFS(x+i,y,result);
                visited[x+i][y] = false;
            }
        }
    }
    // go up or down
    for(int i=-1;i<=1;i+=2)
    {
        if(edge_check(x,y+i))
        {
            if(!visited[x][y+i])  // haven't go there
            {
                visited[x][y+i] = true;
                int result = battle(x,y+i,now_hp);
                if(result==-1)
                    check = check || false;
                else
                    check = check || DFS(x,y+i,result);
                visited[x][y+i] = false;
            }
        }
    }
    return check;
}



int main()
{
    freopen("sample.txt","r",stdin);
    int m;
    scanf("%d %d %d",&player_hp,&player_atk,&m);
    input(m);
    if(M[0][0])
        player_hp -= Atk[0][0];
    visited[0][0] = true;
    if(DFS(0,0,player_hp))
        printf("HEIR OF FIRE DESTROYED\n");
    else
        printf("YOU DIED\n");
    return 0;
}
