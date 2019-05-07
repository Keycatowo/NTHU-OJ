# 12219 - Uncle Huang Points Tutor  

## Description
*Disclaimer: If something described below happened or happens in real world, which is just a coincidence. We will not take any responsibility of any coincidence.*

Uncle: I'm an employee of the library and dating master, nickname "Uncle Huang", who are you?

Shiao: Two years tutor experience, straying book boy of second-hand section, "Shiao Tsing".

Uncle: Well, well. Let me test you!

Uncle: In the painting, dragons won't roar, tigers won't howl, little book boy, funny funny!

Shiao: In the article, man is allowed, woman is forbidden, seeking tutor, urgent urgent!

Uncle: Warbler, swallow, emerald, red, prosperous, harmonious, everywhere.

Shiao: Tutor, Shu-shu, urgent, critial, anxious, serious, swimming pool.

Wang Ye: Another distich!

Uncle: See a jerk standing over there.

Shiao: Seek a tutor swimming over the pool.

Uncle: I am hero in the battle field.

Shiao: You are topic master booming the post.

Uncle: Ahhhhh........!

(Inspired by the post  [靠北清大7754](https://www.facebook.com/KowbeiNTHU/posts/1215056468645226))

Although uncle Huang loses the distich competition, he is still seeking for a male tutor. He would choose one of those who left comments below his post as his tutor ( and one cannot refuse! ). Because too many people left comments below ( just like Shiao said, he's truly a topic master ), he would pick two numbers "x" and "y", and choose the (xy)-th person that left a comment as his tutor.

Because xy might be too big, so the answer would mod(取模) a number "m", which is the total number of comments of his post.

Uncle Huang is too busy seeking for his true love tutor, he asks you for help, could you help him find out his true love tutor?

You are given three numbers "x", "y", and "m", you have to calculate the answer of ((xy)%m) .
**Hint: Use "Fast Power" method to solve this problem!**

## Input
The input contains only one line.

The first line contains exactly three numbers "x", "y", and "m", which are described above.

1 <= x <= 1018,, 0 <= y <= 1018, 1 <= m <= 109.
```
775477547754 775477547754 10235876
```


## Output
Output one number: (xy)%m .

Remember th print a '\n' at the end of the output.

```
9284380
```
## 解題方向
考慮整數求mod特性
>
(a*b)%p = ( (a%p) * (b%p) )%p

let a*b=x^y
1. if y is even, x^y %m = ( (x^(y/2) %m) * (x^(y/2) %m) )%m
2. if y is odd, x^y %m = ( (x^(y/2) %m) * (x^(y/2) %m) * (x^1%m) )%m
3. if y is zero, x^y %m = 1%m (consider include m=1)

### 1918404 WA(6/8)
第7 8筆測資WA，推測可能是數值太大，故做呼叫時修正`fast_mod(x%m,y,m)`
### 1914810 AC
