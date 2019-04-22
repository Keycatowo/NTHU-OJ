# 12130 - Oh! I find de way!   

## Description

Ugandan Knuckles keeps finding his queen. However, he lost his way. He decides to meditate and read some books. In Knuckles' religion, there are two kinds of string: "good string" and "bad string".
> good string /bad string.


A string of length n is good if and only if no letter appears strictly more than n/2 times. For example " aabb ", " ababab " are good and " aab ", " abaab " are bad. Knuckles especially likes to find the substring in a string S.
> good string iff 沒字母出現超過n/2次

For example, for the string S = " abcdefgh ", the good substring includes " abc ", " cdef ", " bcdef ", and so on.

Now you need to help Knuckles find the minimum length of the good substring in the given string S. It's guarantee that there will be at most one answer in each testcase.
> 找最小長度的good substring
> 題目保證只會有一組解答
> 也就是說good string 只有可能有兩種字元且前後分段



## Input
The input contains an integer n and a string S(only contains a~z).

n is the length of S.( 1<= n <= 106 ).

There may be many test cases in each test, but it won't exceed 10 test cases in each test. The input ends with EOF.
```
6
aaabbb
5
aaaaa
4
aabb
```

## Output
The output contains two lines. First line prints "YES" if there's an answer; otherwise, prints "NO".

The second line prints the answer of the minimum length of the good substring if there's an answer; otherwise, prints nothing.

(remember to print '\n' at the end of each line. If the second line has no answer, prints nothing )
```
YES
ab
NO
YES
ab
```

## 解題方向及記錄
因為題目保證good string 題目保證只會有一組解答，所以good string 只有可能是aaaabbbb這樣的形式。
如果判斷是good的話，輸出頭尾即可。
如果是長度為奇數，必定bad。

### 初次Submmit-1900986 -NA（0/4)
```
#include <stdio.h>
char S[106];
int n;
int main(){
    //freopen("12130_sampleIn.txt","r",stdin);
    while(scanf("%d\n",&n)!=EOF){
        /// input string
        for(int i=0;i<n;i++){
            scanf("%c",&S[i]);
        }
        /// judge
        if(S[0]==S[n-1]||n%2) printf("NO\n");//aaaaa
        else if(S[0]==S[n/2-1]&&S[n-1]==S[n/2])
            printf("YES\n%c%c\n",S[0],S[n-1]);
    }

}
```
可能是只有想到good的處理方式
似乎還沒考慮到全部bad的可能，如：aabca應該是bad(a>2)，但在原本的判斷中沒考慮到這個可能。
改進方向：將good/bad分開處理結果，先專門判斷是否bad。

做法：增加max_count function
```
int max_count(char* Seq,int length){
    int alphabet[26];
    for(int i=0;i<26;i++){
        alphabet[i]=0;
    }
    int tmp;
    for(int i=0;i<length;i++){
        tmp=Seq[i];
        //printf("tmp= %c %c \n",tmp,Seq[i]);
        alphabet[tmp-97]++;
    }
    int max=0;
    for(int i=0;i<26;i++){
        if(alphabet[i]>max) max=alphabet[i];
    }
    return max;
}
```
### 重新釐清題意 1901178 -NA（2/4）
測試過各種組合後都無法通過，後來在iLms上看到助教對於同學的回覆
> 測資的string是不是good string不重要
你要找的是這個string有沒有good string存在，如果有的話輸出最短的那個，和上面同學說的一樣

所以原來不用判斷整個string是否good，只要找到最小的即可————即第一次相異的那個
所以aaabb的話可以找到ab(在原本方式會被判斷成bad)
```
void Find2(){
        int check;
    while(scanf("%d\n",&n)!=EOF){

        check=0;
        /// input string
        for(int i=0;i<n;i++){
            scanf("%c",&S[i]);
        }

        /// judge
        if(n>1) {
            for(int i=1;i<n;i++){
                if(S[i]!=S[i-1]){
                    check=1;
                    printf("YES\n%c%c\n",S[i-1],S[i]);
                //break;
                }
            }
        }
        if(check==0)printf("NO\n");
    }
}

```
第1 3筆過了，但第2 4筆測資有RTE

### 修正宣告方式 1901583 AC
```
char S[10^6]      //12
char S[1000000]   //1000000
```
>在C裡面^為XOR的意思
