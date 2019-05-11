## 12234
### Q
12: `left=NULL`與`this->left` 有差別嗎，何者較優？
24: `~BST()`是用來做什麼的？~通常用來表示什麼意思？
### Note
先處理例外，再把包含例外的情況丟遞迴。`if(node==NULL){...}else ...`
for迴圈內可以用來跑指標推進`for(succ = node->right; succ->left != NULL; succ = succ->left);`


## 12235
### Q
