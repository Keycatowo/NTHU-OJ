# 12143 - AAAAAAAAAAAA~

## Description
A famous streamer once said: "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA~". This streamer is famous for his "stroke style". If he plays video game with some poor skilled players, he will "stroke". Today he strokes again. He is furious because other players keep "giving head" to his opponents.

He give each player an number bi denoted as the level of his "stroke". He sorts those numbers in increasing order to make a "stroke list".

Now he gives you t queries. Each query will give you a number ai, and you should answer the positions of the numbers in the "stroke list".

There will be n numbers in the "stroke list" and all numbers are distinct.

Note that the position starts from 0, and we guarantee that ai is always in the list.

### Hint:

you can use binary search(https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%88%86%E6%90%9C%E7%B4%A2%E7%AE%97%E6%B3%95) to solve this question.

This question is "partial judge". You only need to complete one function. You should download the two files below and compile those two files and your answer together.

Your submission should only contains your answer.

If you use "codeblocks" or "Xcode" just put all three files(containing your answer) into the same project.

your answer will be like this:

```
#include "function.h"

int BS(int *陣列名, int 欲尋找的數字, int 陣列長度)
{

}
```
## Input
Input contains several lines.

First line contains two integers n, t (1 <= n, t <= 2*106)

Second line contains n integers bi ( 1 <= bi <= 109 )

The following t lines, each line contains one integer ai ( 1 <= ai <= 109 )
```
10 10
0 1 2 3 4 5 6 7 8 9
5
8
9
0
2
2
1
7
7
0
```


## Output
For each query, you should print the index of the number in this form: "ai is at index: ansi ".

Remember to print \n at the end of each query.
```
5 is at index: 5
8 is at index: 8
9 is at index: 9
0 is at index: 0
2 is at index: 2
2 is at index: 2
1 is at index: 1
7 is at index: 7
7 is at index: 7
0 is at index: 0
```
