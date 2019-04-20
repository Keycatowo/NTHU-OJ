# 12140 - HaSaKi~   

## Description
"Death is like the wind, always by my side.", said by a famous streamer, Mr. Yasuoo.

Mr. Yasuoo is known for his skill "Slides up".

When Mr. Yasuoo slides across a string S, he will be asked t questions.

In each question, he should respond the number of occurrences of substring s, given a interval of [ l, r ].

Specifically, if the string S is "hasahasasaki" and the substring s is "sa", Mr. Yasuoo should answer 2 given the interval of [3, 9].

Since the interval [3~9]  indicates "sahasas",  the number of occurrences of substring "sa" is then 2.

Note that the index of string starts from 1 and contains only 'a' ~ 'z'.

Help Mr. Yasuoo to answer these questions before he starts feeding, ASAP!

⠄⠄⠄⠄⠄⠄⠄
 ⠄⠄⠄⠄⠄⠄⠄⠈⠉⠁⠈⠉⠉⠙⠿⣿⣿⣿⣿⣿
 ⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⣀⠄⠄⠄⠄⠄⠹⣿⣿⣿
 ⠄⠄⠄⠄⠄⢐⣲⣿⣿⣯⠭⠉⠙⠲⣄⡀⠄⠈⢿⣿
 ⠐⠄⠄⠰⠒⠚⢩⣉⠼⡟⠙⠛⠿⡟⣤⡳⡀⠄⠄⢻
 ⠄⠄⢀⣀⣀⣢⣶⣿⣦⣭⣤⣭⣵⣶⣿⣿⣏⠄⠄⣿
 ⠄⣼⣿⣿⣿⡉⣿⣀⣽⣸⣿⣿⣿⣿⣿⣿⣿⡆⣀⣿
 ⢠⣿⣿⣿⠿⠟⠛⠻⢿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣼
 ⠄⣿⣿⣿⡆⠄⠄⠄⠄⠳⡈⣿⣿⣿⣿⣿⣿⣿⣿⣿
 ⠄⢹⣿⣿⡇⠄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
 ⠄⠄⢿⣿⣷⣨⣽⣭⢁⣡⣿⣿⠟⣩⣿⣿⣿⠿⠿⠟
 ⠄⠄⠈⡍⠻⣿⣿⣿⣿⠟⠋⢁⣼⠿⠋⠉⠄⠄⠄⠄
 ⠄⠄⠄⠈⠴⢬⣙⣛⡥⠴⠂⠄⠄⠄⠄⠄⠄⠄⠄⠄...
(the photo of the famous streamer)
> 給一串長的字串和短的目標以及固定範圍
  每次求範圍內出現短的字串的次數

## Input
Input should contain multiple lines.

First line indicates the string S ( 1<= length of S <= 103 )

Second line gives the substring s ( 1<= length of s <= 103 )

the string contains only lower case a~z.

Third line contains one integer t ( 1<= t <= 2*106 )

each of the following t lines gives two integer [l , r], where ( 1<= l <= r <= length of S)
```
hasahasasaki
sa
3
3 9
1 4
2 3
```
> 第一行為字串S
  第二行為子字串s
  第三行為問題數t
    接下來t行為序列區間 [l,r] 1~length of S

## Output
For each question, you are asked to print the the number of occurrences of substring s.

Your program should present a single '\n' at the end of output.
```
2
1
0
```
> t行
