#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct SSSSSS{
    int val, h;
    struct SSSSSS *ls, *rs;
}NODE;

NODE *root;

NODE *new_r(int val){
    NODE *x = (NODE *)calloc(1, sizeof(NODE));
    x->val = val;
    return x;
}

void dfs(NODE *u){
    if (u->ls)dfs(u->ls);
    if (u->rs)dfs(u->rs);
    if (!u->ls && !u->rs)printf("%d %d\n", u->val, u->h);
}

int main(){
#ifdef VSCODE
    freopen("input.in","r",stdin);
#endif
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int val;
        scanf("%d", &val);
        NODE *u = root;
        NODE *pre;
        int x = 0;
        while (u){
            pre = u;
            if (val >= u->val)u = u->rs, x = 1;
            else u = u->ls, x = 2;
        }
        u = new_r(val);
        if (!root){
            root = u;
            root->h = 1;
        }
        if (x){
            u->h = pre->h+1;
            if (x == 1)pre->rs = u;
            if (x == 2)pre->ls = u;
        }
    }
    dfs(root);
    return 0;
}
