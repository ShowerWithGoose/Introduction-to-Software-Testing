#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>//BST,后序遍历，标记深度
//将左右指针以数组的方式存储可以优化代码量
typedef struct btnode{
    int value;
    int depth;
    struct btnode *left,*right;
} btnode;

btnode *root;
btnode *talloc(int);

void bvisit(btnode*);

int main(){
    root = talloc(0);
    int i,j,lock = 0,n,tem;
    btnode *p = root;
    scanf("%d",&n);
    for(i = 0;i < n;++i){
        scanf("%d",&tem);
        if(i == 0) root->value = tem;
        else{
            p = root;
            while(1){
                if(tem >= p->value){
                    if(p->right == NULL){
                        lock = 1;
                        break;
                    }
                    else p = p->right;
                }
                else{
                    if(p->left == NULL){
                        lock = -1;
                        break;
                    }
                    else p = p->left;
                }
            }
            if(lock == -1){
                p->left = talloc(tem);
                p->left->depth = p->depth+1;
            }
            else if(lock == 1){
                p->right = talloc(tem);
                p->right->depth = p->depth+1;
            }
        }
    }
    bvisit(root);
    return 0;
}

btnode *talloc(int num){
    btnode *tem = (btnode*)malloc(sizeof(btnode));
    tem->left = tem->right = NULL;
    tem->value = num;
    tem->depth = 1;
    return tem;
}

void bvisit(btnode *p){
    if(p != NULL){
        bvisit(p->left);
        bvisit(p->right);
        if(p->left == NULL && p->right == NULL){
            printf("%d %d\n",p->value,p->depth);
        }
    }
}
