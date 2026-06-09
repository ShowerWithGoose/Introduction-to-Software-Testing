#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct tree{
    int val;
    struct tree *left;
    struct tree *right;
}*root;
int n,height,temp,flag;

void createtree(struct tree *p);
void visittree(struct tree *p);
int main(void)
{
    root=(struct tree*)malloc(sizeof(struct tree));
    root->left=NULL;
    root->right=NULL;//创建根节点
    height=1;//基础深度

    scanf("%d",&n);

    while(n--){
        scanf("%d",&temp);
        createtree(root);//创建二叉查找树
    }
    
    visittree(root);//遍历
    
    return 0;
}

void createtree(struct tree *p){
    if(flag==0){
        root->val=temp;
        flag=1;//根节点赋值
    }else{
        if(temp<p->val){
            if(p->left==NULL){
                struct tree *r=(struct tree*)malloc(sizeof(struct tree));
                r->left=NULL;
                r->right=NULL;
                p->left=r;
                r->val=temp;//无左子树则插入
            }else{
                createtree(p->left);//递归
            }
        }else{
            if(p->right==NULL){
                struct tree *r=(struct tree*)malloc(sizeof(struct tree));
                r->left=NULL;
                r->right=NULL;
                p->right=r;
                r->val=temp;//无右子树插入
            }else{
                createtree(p->right);//递归
            }
        }
    }
}

void visittree(struct tree *p){
    if(p->left!=NULL){
        height++;
        visittree(p->left);//左递归调用一次深度加一
    }else if(p->right==NULL){
        printf("%d %d\n",p->val,height);
    }   

    if(p->right!=NULL){
        height++;
        visittree(p->right);//右递归调用一次深度加一
    }

    height--;//递归完毕回到父节点
}
