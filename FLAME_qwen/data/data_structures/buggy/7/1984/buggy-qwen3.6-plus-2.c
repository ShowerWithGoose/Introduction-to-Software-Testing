#include<stdio.h>
#include<stdalign.h> // @@ This header is C11-specific and may cause compilation errors on older compilers or environments that do not support it. It is also unused.
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    struct tree * f,*l,*r;
    int depth;
}tree;

tree *p = NULL,*q = NULL,*top = NULL;
int num;

void Visit(tree *t){
    printf("%d %d\n",t->data,t->depth); 
}

void preorder(tree *t){
    if(t != NULL){
        preorder(t->l);
        preorder(t->r);
        if(t->l == NULL && t->r == NULL){
            //TODO
            Visit(t);
        }
    }
}

void insert(int num){
    q = (tree*)malloc(sizeof(tree));
    q->data = num;
    q->l = NULL;
    q->r = NULL;
    if(p == NULL){
        //TODO
        p = q;
        p->f = NULL;
        p->l = NULL;
        p->r = NULL;
        p->depth = 1;
        top = p;
        return;
    }else{
        if(num < p->data){
            //去左边
            if(p->l == NULL){
                q->depth = p->depth+1;
                p->l = q;
                q->f = p;
                p = top;
                return;
            }else{
                p = p->l; // @@ Logical error: The global pointer p is not reset to top after the recursive call, causing subsequent insertions to start from an incorrect node and corrupting the tree structure.
                insert(num);
            }
        }else if(num > p->data){ // @@ Logical error: The problem specifies that the right child's value should be greater than or equal to the root. This condition should be num >= p->data to correctly handle duplicate values.
            //TODO
            if(p->r == NULL){
                //TODO
                q->depth = p->depth +1;
                p->r = q;
                q->f = p;
                p = top;
                return;
            }else{
                p = p->r; // @@ Logical error: The global pointer p is not reset to top after the recursive call, causing subsequent insertions to start from an incorrect node and corrupting the tree structure.
                insert(num);
            }
        }
    }
    return;
}
/*
读入
    看是不是第一个
        是：作为top，
        不是：
    看与前面p的大小关系：//要递归吗？好像不用
        小：
        去左边；
            左边空，成为左节点; 更新 p = top
            左边有，更新p=左边；
        大：去右边；
            右边空，当右节点；
            右边有，更新p= 右边 ；更新p = top
*/
int main(){
    top = (tree*)malloc(sizeof(tree)); // @@ Unnecessary allocation. top is immediately overwritten in insert when p is NULL, and its l/r fields remain uninitialized, risking undefined behavior.
    p = (tree*)malloc(sizeof(tree)); // @@ Unnecessary allocation. p is immediately set to NULL on the next line, causing a memory leak.
    p = NULL;
    top->depth = 1;
    top -> f = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //TODO
        scanf("%d",&num);
        insert(num);
    }
    preorder(top);
    return 0;
}