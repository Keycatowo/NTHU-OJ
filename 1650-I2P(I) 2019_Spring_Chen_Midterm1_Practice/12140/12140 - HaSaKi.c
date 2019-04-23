#include <stdio.h>
#include <stdbool.h>

char S[1000];   //hasahasasaki
char s[1000];   //sa
int N,n;        //length of S and s
int times[1000];//store how many times s in S from 0 to i

int getline(char* Seq);
bool check(int index);
void build();
int diff(int l,int r);


int main(){
    /// input S s
    freopen("12140_sampleIn.txt","r",stdin);
    N=getline(S);
    n=getline(s);

    /// Build times array
    build();

//    /// test times
//    for(int i=0;i<=(N-n);i++)
//        printf("%d",times[i]);
//    printf("\n");

    /// t queries
    int t,l,r;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&l,&r);
//        printf("%d %d\n",times[r-n+1],times[l-1]);
        printf("%d\n",diff(l-1,r-1));
    }
    return 0;
}


int getline(char* Seq){
    char tmp;
    int i=0;
    while( (tmp=getchar())!='\n' ){
        Seq[i]=tmp;
        i++;
    }
    return i;/// the length of this string
}


bool check(int index){
    for (int i=0;i<n;i++){
        if(S[index+i]!=s[i]) return false;
    }
    return true;
}

void build(){
    times[0]=check(0) ? 1:0 ;
    for (int i=1;i<=(N-n);i++){
        times[i]=times[i-1]+(check(i)?1:0);
    }
}

int diff(int l,int r){
    return (times[r-n+1]-times[l-1]);
}
