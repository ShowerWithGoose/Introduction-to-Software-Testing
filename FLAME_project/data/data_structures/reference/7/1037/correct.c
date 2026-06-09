#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TREE_NODE_STRUCT{
    int val,depth;
    struct TREE_NODE_STRUCT *ls, *rs;
}NODE;
NODE *root, *tree[100000];
int cnt;

void insert(int x){
    if (root == NULL){
        tree[cnt] = (NODE *)calloc(1, sizeof(NODE));
        root = tree[cnt];
        tree[cnt]->depth = 1;
        tree[cnt++]->val = x;
    }
    else {
        NODE *u = root;
        while (1){
            if (x >= u->val){
                if (u->rs == NULL){
                    tree[cnt] = (NODE *)calloc(1, sizeof(NODE));
                    u->rs = tree[cnt];
                    tree[cnt]->depth = u->depth+1;
                    tree[cnt++]->val = x;
                    break;
                }
                else {
                    u = u->rs;
                    continue;
                }
            }
            else {
                if (u->ls == NULL){
                    tree[cnt] = (NODE *)calloc(1, sizeof(NODE));
                    u->ls = tree[cnt];
                    tree[cnt]->depth = u->depth+1;
                    tree[cnt++]->val = x;
                    break;
                }
                else {
                    u = u->ls;
                    continue;
                }
            }
        }
    }
}

void output(NODE *u){
    int isLeaf = 1;
    if (u->ls != NULL){
        output(u->ls);
        isLeaf = 0;
    }
    if (u->rs != NULL){
        output(u->rs);
        isLeaf = 0;
    }
    if (isLeaf){
        printf("%d %d\n",u->val, u->depth);
    }
}

int main(){
#ifdef VSCODE
    freopen("input.in","r",stdin);
#endif
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++){
        int tmp;
        scanf("%d",&tmp);
        insert(tmp);
    }
    output(root);
    return 0;
}
