# 10966 - Infix to syntax tree

## Description
Given an infix Boolean expression with parentheses, which has at most 4 variables ‘A’, ’B’, ‘C’, and ‘D’, and two operators ‘&’ and ‘|’. Build a corresponding syntax tree for it.

To parse the infix expression with parentheses, use the grammar below.

EXPR = FACTOR | EXPR OP FACTOR

FACTOR = ID | (EXPR)

EXPR is the expression, ID is one of ‘A’, ‘B’, ’C’, or ‘D’, and OP is one of ‘&’ or ‘|’.



You will be provided with main.c and function.h. main.c contains the implementation of functions printPrefix and freeTree. function.h contains the definition of tree node and variables. You only need to implement the following three functions in function.c.

BTNode* makeNode(char c)   // create a node without any child

BTNode* EXPR()   // parse an infix expression and generate a syntax tree

BTNode* FACTOR()   // use the parse grammar FACTOR = ID | (EXPR) to deal with parentheses



For OJ submission:

        Step 1. Submit only your function.c into the submission block.(Please choose C compiler)

        Step 2. Check the results and debug your program if necessary.

## Input
The input contains N infix expressions, which has at most 4 variables ‘A’, ’B’, ‘C’, and ‘D’, two operators ‘&’ and ‘|’, and parentheses. All parentheses are matched.
```
7
9 3 1 5 7 10 34
6
AverLevel 2
AverLevel 3
SumLevel 3
P
GetMax
SumLevel 10
```

## Output
The output contains N prefix expressions without parentheses, which are preorders of syntax trees.
```
6.500
13.333
40
1 3 5 7 9 10 34
4
0
```

## 題目說明
+ 建一個BST，要求4種功能
        + `P`:用in-order的方式印出tree，如果空的話印出`NULL`
        + `GetMax`:印出tree的層數
        + `SumLevel(input)`:印出某層的節點和
        + `AverLevel(input)`:印出某層的節點平均(取小數3位)

## 解題思路
+ 節點
        + int data
        + Node* left
        + Node* right
        + int level：因為本次題目要求的並非平衡樹，所以層數只和建立的時候有關
+ 建樹
        + 如果NULL，新增一個節點並設定成root
        + 如果目前非NULL(有data)，比較大小後遞迴呼叫建樹
