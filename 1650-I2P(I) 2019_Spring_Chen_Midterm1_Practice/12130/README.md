# 12130 - Oh! I find de way!   

## Description

Ugandan Knuckles keeps finding his queen. However, he lost his way. He decides to meditate and read some books. In Knuckles' religion, there are two kinds of string: "good string" and "bad string".

A string of length n is good if and only if no letter appears strictly more than n/2 times. For example " aabb ", " ababab " are good and " aab ", " abaab " are bad. Knuckles especially likes to find the substring in a string S.

For example, for the string S = " abcdefgh ", the good substring includes " abc ", " cdef ", " bcdef ", and so on.

Now you need to help Knuckles find the minimum length of the good substring in the given string S. It's guarantee that there will be at most one answer in each testcase.


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
