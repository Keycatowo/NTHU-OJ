#include <stdio.h>

int count_parentheses(){
    char str[2010];// store the char of test data
    int i=0;
    int number_of_pair=0,number_of_sum=-1;
    str[0]='\0';
    do{
        str[++i]=getchar();//i will start from 1
        number_of_sum++;//number off all +1

        if(str[i]==']'){
            if(str[i-1]=='['){
                i=i-2;
                number_of_pair++;
            }
            //else break;
        }

        if(str[i]==')'&&i>0){
            if(str[i-1]=='('){
                i=i-2;
                number_of_pair++;
            }
            //else break;
        }
        if(str[i]=='>'&&i>0){
            if(str[i-1]=='<'){
                i=i-2;
                number_of_pair++;
            }
            //else break;
        }
        if(str[i]=='}'&&i>0){
            if(str[i-1]=='{'){
                i=i-2;
                number_of_pair++;
            }
            //else break;
        }
    }while((str[i]!='\r')&&(str[i]!='\n'));

    if(number_of_pair*2==number_of_sum) return 1;
        else return 0;
}



int main(){
    int T;//numbers of the data lists
    int sum=0;
    scanf("%d",&T);
    getchar();//refresh the flash of enter
    for (int i=0;i<T;i++){
        sum+=count_parentheses();
        //printf("%dth:%d\n",i,sum);
    }
    printf("%d\n",sum);
    //scanf("%d",sum);
    return 0;

}
