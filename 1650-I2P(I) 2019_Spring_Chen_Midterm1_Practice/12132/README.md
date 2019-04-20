# 12132 - too many watermelons  

##Description
Ovuvuevuevue Enyetuenwuevue Ugbemugbem Osas wants to eat watermelon.

He has n watermelons and each one has a specific index denote as ai. The watermelons are store in a cylindrical(圓柱狀) box. Osas wants to eat a watermelon indexed ai. But if the watermelon indexed ai is not on the top, he needs to eat all watermelon above the watermelon indexed ai.

For example if the index of watermelon from top to bottom is: 5, 3, 2, 1, 4. And Osas wants to eat watermelon which index is 2, then he need to eat watermelons which index are 5, 3, 2 at the same time.

Osas has a list which is the order of index of watermelons he wants to eat which denoted as bi. The length of the list is also n and all bi are distinct. Please help him calculate that each time he wants to eat a watermelon, how many watermelons he needs to eat at same time?

For example if the index of watermelon from top to bottom is: 5, 3, 2, 1, 4. And the list Osas has is: 2, 3, 4, 5, 1.

First time Osas will eat 3 watermelons(5,3,2). Second time because the watermelons that indexed 3 is already been eaten, Osas eat 0 watermelon . So on and so forth.

In this example, you need to output: 3 0 2 0 0.





## Input
input contains three lines.

First line contains n the number of watermelons.( 1 <= n <= 2*105 )

Second line contains n integer a1 ~ an which denote as the index of watermelons from top to bottom .( 1 <= ai <= n )



Third line contains n integer b1 ~ bn which denote as the order of the index that Osas' wants to eat.( 1 <= bi <= n )
```
5
5 3 2 1 4
2 3 4 5 1
```


##Output
output contains one line.

output n integer means the number of watermelons that each time Osas eat. Separate each number by a blank but don't print the blank after the last number.

remember to print \n at the end of output.
```
3 0 2 0 0
```
