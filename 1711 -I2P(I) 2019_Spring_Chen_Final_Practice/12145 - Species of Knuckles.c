#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) (a>b?a:b)

bool alphabets[26];
int n;

int char2int(char c){
    return c-'a';
}
bool solve(int n){
	if(n==1)
		return true;
    char c;
    for(int i=0;i<n;i++){
        scanf("%c",&c);
        if(alphabets[char2int(c)])
            return true;
        else
            alphabets[char2int(c)] = true;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    char tmp[10];
    gets(tmp);
    if(solve(n))
        printf("I'm the god of Knuckles!\n");
    else
        printf("Different makes perfect\n");
    return 0;
}
