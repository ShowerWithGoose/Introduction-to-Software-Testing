#include<stdio.h>
#include<stdalign.h>
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
                p = p->l;
                insert(num);
            }
        }else if(num > p->data){
            //TODO
            if(p->r == NULL){
                //TODO
                q->depth = p->depth +1;
                p->r = q;
                q->f = p;
                p = top;
                return;
            }else{
                p = p->r;
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
    top = (tree*)malloc(sizeof(tree)); // @@ [This allocation is unnecessary and leaks memory because `top` is immediately overwritten in `insert()` when the first node is inserted. Also, `p` is set to NULL right after, making this allocation useless.]
    p = (tree*)malloc(sizeof(tree)); // @@ [This allocation is immediately leaked because `p` is reassigned to NULL on the next line.]
    p = NULL;
    top->depth = 1; // @@ [Dereferencing `top` here is invalid because if the input has zero nodes, `top` points to an unused allocated block; but more critically, for non-zero inputs, `top` gets overwritten in `insert()`, so this assignment has no effect. Also, if `n == 0`, this causes undefined behavior as nothing is printed but tree traversal is attempted.]
    top -> f = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //TODO
        scanf("%d",&num);
        insert(num);
    }
    preorder(top); // @@ [If `n == 0`, `top` still points to the initially allocated dummy node (which was never properly initialized as a real tree node with `data`), leading to incorrect traversal. But more importantly, the insertion logic fails to handle duplicate values (`num == p->data`). According to the problem, right child should be used for values >= root, but the code only handles `<` and `>`, skipping insertion entirely when `num == p->data`. This causes the second `100` in the test case to be ignored, which is why the leaf node `100` (the duplicate) is missing from the output.]
    return 0;
}