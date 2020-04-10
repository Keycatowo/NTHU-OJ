#include <stdio.h>
#include <stdbool.h>
#define DEBUG_MODE 0
#define FILE_MODE 1
#define SHOW(a) (DEBUG_MODE)?(printf("%s:%d\n",#a,a)):1
#define SHOW_C(c) (DEBUG_MODE)?printf("%c",c):1
#define LOGGING(s) (DEBUG_MODE)?printf(s):1
#define MAX 500
#define MAX_PUZZLE 50


typedef struct _puzzle{
    bool puzzle_matrix [MAX_PUZZLE][MAX_PUZZLE];
    int row,col;
}puzzle;

bool matrix [MAX][MAX];
int m_col,m_row;
int number_of_puzzle;
bool check = false;


puzzle* puzzle_list;

puzzle create_puzzle(int x,int y){
    char tmp;
    puzzle new_puzzle;

    new_puzzle.row = y;
    new_puzzle.col = x;


    for (int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            tmp = getchar();
            new_puzzle.puzzle_matrix[i][j] = (tmp=='O')?1:0;

        }
        getchar(); // to get "\n"
    }
    return new_puzzle;
}


void reset(){
    for (int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            matrix[i][j] = false;
        }
    }
    check = false;
}

void input_map(){
    char tmp;
    for (int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            tmp = getchar();
            matrix[i][j] = (tmp=='O')?1:0;

        }
        getchar(); // to get "\n"
    }

}

bool valid(puzzle P,int x,int y){
    if(x + P.row > m_row || y + P.col > m_col)
        return false;

    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.col;j++){
            if( P.puzzle_matrix[i][j]&& matrix[x+i][y+j])
                return false;
        }
    }
    return true;
}


void fill_puzzle(puzzle P,int x,int y){
    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.col;j++){
            if(P.puzzle_matrix[i][j])
                matrix[x+i][y+j] = true;
        }
    }
}

void remove_puzzle(puzzle P,int x,int y){
    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.col;j++){
            if(P.puzzle_matrix[i][j])
                matrix[x+i][y+j] = false;
        }
    }
}
void show_matrix(){
    if(DEBUG_MODE==0)
        return;

    printf("\n");
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            if(matrix[i][j])
                printf("O");
            else
                printf("-");
        }
        printf("\n");
    }

    printf("\n");
}

void DFS(int index){
    if(check || index == number_of_puzzle){
        check = true;
        return;
    }


//    show_matrix();




    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            SHOW(index);SHOW(i);SHOW(j);
            if( valid(puzzle_list[index],i,j)){
                LOGGING("Valid:\n");
//                LOGGING("Before:");
//                show_matrix();
                fill_puzzle(puzzle_list[index],i,j);
//                LOGGING("FILLED");
//                show_matrix();
                DFS(index+1);
                remove_puzzle(puzzle_list[index],i,j);
//                LOGGING("REMOVED:");
//                show_matrix();
            }
        }
    }
}





int main(){
    (FILE_MODE)?freopen("input.txt","r",stdin):1;

    int x,y;

    scanf("%d",&number_of_puzzle);
    SHOW(number_of_puzzle);
    puzzle_list = (puzzle*)malloc(number_of_puzzle * sizeof(puzzle));// create a dynamic array to save puzzles
    // input with puzzles
    for(int i=0; i<number_of_puzzle;i++){
        scanf("%d %d\n",&x,&y);
        puzzle_list[i] = create_puzzle(x,y);

    }
    int T;
    // input with maps
    scanf("%d",&T);
    while(T--){
        scanf("%d %d\n",&m_col,&m_row);
        reset();
        input_map();
        DFS(0);
        (check)?printf("Yes\n"):printf("No\n");
    }




}

