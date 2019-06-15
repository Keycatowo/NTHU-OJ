#include<bits/stdc++.h>

typedef struct B{
    int val, hei;
    struct B *lf, *rt;
    B(int x){
        val = x;
        hei = 1;
        lf = rt = NULL;
    };
}node;

typedef struct A{
    node *root;
    char dir[3]; // for rotation
    void del_sub(node *cur){
        if(cur==NULL) return;
        del_sub(cur->lf);
        del_sub(cur->rt);
        delete(cur);
    }
    void del(){
        dir[0] = dir[1] = dir[2] = '\0';
        del_sub(root);
        root = NULL;
    }
    void up_hei(node *cur){
        int lfh = (cur->lf==NULL)? 0:cur->lf->hei; // left height
        int rth = (cur->rt==NULL)? 0:cur->rt->hei; // right height
        cur->hei = 1 + ((lfh>rth)?lfh:rth);
    }
    node* lf_rot(node *cur){
        node *rt_c = cur->rt;
        cur->rt = rt_c->lf;
        rt_c->lf = cur;
        up_hei(cur); up_hei(rt_c);
        return rt_c; // the new root;
    }
    node* rt_rot(node *cur){
        node *lf_c = cur->lf;
        cur->lf = lf_c->rt;
        lf_c->rt = cur;
        up_hei(cur); up_hei(lf_c);
        return lf_c; // the new root;
    }
    node* rot(node *cur){
        if(dir[0] == 'L'){
            if(dir[1] == 'L'){ // LL
                cur = rt_rot(cur);
            }else{ // LR
                cur->lf = lf_rot(cur->lf);
                cur = rt_rot(cur);
            }
        }else{
            if(dir[1] == 'L'){ // RL
                cur->rt = rt_rot(cur->rt);
                cur = lf_rot(cur);
            }else{ // RR
                cur = lf_rot(cur);
            }
        }
        return cur;
    }
    node* ins(int x, node *cur){
        if(cur == NULL){
            return new node(x);
        }
        if(x < cur->val){
            cur->lf = ins(x, cur->lf);
        }else{
            cur->rt = ins(x, cur->rt);
        }
        // update the height
        int lfh = (cur->lf==NULL)? 0:cur->lf->hei; // left height
        int rth = (cur->rt==NULL)? 0:cur->rt->hei; // right height
        cur->hei = 1 + ( (lfh>rth)? lfh:rth );
        // check the balance factor
        int bf = lfh - rth;
        // resolving the directions
        if(bf>1){ // L
            dir[0] = 'L';
            if(x < cur->lf->val) dir[1] = 'L';
            else dir[1] = 'R';
            return rot(cur); // return the new root of the subtree
        }else if(bf < -1){ // R
            dir[0] = 'R';
            if(x < cur->rt->val) dir[1] = 'L';
            else dir[1] = 'R';
            return rot(cur);
        }
        return cur; // no rotation
    }
    void insert(int x){
        root = ins(x, root);
    }
    void print(){
        std::vector<node*> v;
        v.clear();
        if(root != NULL) v.push_back(root);
        int i=0;
        node *cur;
        while(i<v.size()){
            cur = v[i];
            if(cur->lf != NULL) v.push_back(cur->lf);
            if(cur->rt != NULL) v.push_back(cur->rt);
            i++;
        }
        for(i=0;i<v.size();i++){
            if(i==0) printf("%d", v[i]->val);
            else printf(" %d", v[i]->val);
        }
        puts("");
    }
}AVL_TREE;

AVL_TREE avl;

int main(){
    int T, n, a;
    scanf("%d", &T);
    while(T--){
        avl.del();
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &a);
            avl.insert(a);
        }
        avl.print();
    }
    return 0;
}
