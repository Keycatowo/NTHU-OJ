#include <stdio.h>
#include <stdbool.h>

char A[100000];
char B[100000];

bool is_equal(int Al,int Ar,int Bl,int Br){
    /// length 1
    //if(Al==Ar) return (A[Al]==B[Bl]);

    /// can  devide
    if((Ar-Al))// 0~7, even length is 1
    {
        return
        (
            (is_equal(Al,(Al+Ar)/2,Bl,(Bl+Br)/2) && (is_equal((Al+Ar)/2+1,Ar,(Bl+Br)/2+1,Br)))
            // 0~
            ||
            (is_equal(Al,(Al+Ar)/2,(Bl+Br)/2+1,Br) && (is_equal((Al+Ar)/2+1,Ar,Bl,(Bl+Br)/2)))
        );
    }
    /// can't devide
    else
    {
        // all should same
        for(int i=0;i<=(Ar-Al);i++){
            if(A[Al+i]!=B[Bl+i]) return false;
        }
        return true;
    }


}
int getline(char* Seq){
    char tmp;
    int i=0;
    while( (tmp=getchar())!='\n' ){
        Seq[i]=tmp;
        i++;
    }
    return i;
}
void papa_judge(){
    int length;
    length=getline(A);
    getline(B);
    if(is_equal(0,length-1,0,length-1))
        printf("YES\n");
    else
        printf("NO\n");
}
int main(){
    papa_judge();
    return 0;
}

