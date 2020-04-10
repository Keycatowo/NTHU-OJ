#include <stdio.h>
#include <stdbool.h>
#define DEBUG_MODE 1
#define FILE_MODE 1
#define SHOW(a) (DEBUG_MODE)?(printf("%s:%d\n",#a,a)):1
#define SHOW_C(c) (DEBUG_MODE)?printf("%c",c):1
#define LOGGING(s) (DEBUG_MODE)?printf("%s",s):1
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

puzzle rotate_puzzle(puzzle origin){
    puzzle new_puzzle;

    new_puzzle.col = origin.row;
    new_puzzle.row = origin.col;

    LOGGING("ORIGIN\n");
    for(int i=0;i<origin.row;i++){
        for(int j=0;j<origin.col;j++){
            (origin.puzzle_matrix[i][j])?printf("O"):printf("-");
        }
        printf("\n");
    }


    for(int i=0;i<origin.row;i++){
        for(int j=0;j<origin.col;j++){
            new_puzzle.puzzle_matrix[j][new_puzzle.col-1-i] = origin.puzzle_matrix[i][j];
        }
    }

    LOGGING("NEW\n");
    for(int i=0;i<new_puzzle.row;i++){
        for(int j=0;j<new_puzzle.col;j++){
            (new_puzzle.puzzle_matrix[i][j])?printf("O"):printf("-");
        }
        printf("\n");
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
        LOGGING("YES\n");
        check = true;
        return;
    }
    puzzle cur_puzzle = puzzle_list[index];

    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            SHOW(i);SHOW(j);
            for(int k=0;k<4;k++){
                if( valid(cur_puzzle,i,j)){
                    fill_puzzle(cur_puzzle,i,j);
                    DFS(index+1);
                    remove_puzzle(cur_puzzle,i,j);
                }
                cur_puzzle = rotate_puzzle(cur_puzzle);
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
    SHOW(T);
    while(T--){
        scanf("%d %d\n",&m_col,&m_row);
        reset();
        input_map();
        DFS(0);
        (check)?printf("Yes\n"):printf("No\n");
    }




}

