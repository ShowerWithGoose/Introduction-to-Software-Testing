#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct bstnode{
    int data;
    int degree;
    struct bstnode *lchild, *rchild;
} bst;
bst *root = NULL;
void bst_insert(int data){
    bst *p, *q;
    p = (bst *)malloc(sizeof(bst));
    p->data = data;
    p->degree = 1;
    p->lchild = p->rchild = NULL;
    if(root == NULL){
        root = p;
    }
    else{
        q = root;
        while(1){
            p->degree += 1; // 每进行一次循环，度就会加一
            if(data < q->data){ // 数据小于当前节点则向左走
                if(q->lchild == NULL){ // 左孩子为空
                    q->lchild = p; // 直接赋值
                    break;
                }
                else{ // 左孩子不为空则将节点移动至左孩子
                    q = q->lchild;
                }
            }
            else if(data >= q->data){ // 数据大于当前节点则向右走
                if(q->rchild == NULL){ // 右孩子为空
                    q->rchild = p; // 直接赋值
                    break;
                }
                else{ // 右孩子不为空则将节点移动至右孩子
                    q = q->rchild;
                }
            }
        }
    }
    return;
}
void traverse(bst *p){
    if(p != NULL){
        traverse(p->lchild);
        traverse(p->rchild);
        if((p->lchild == NULL) && (p->rchild == NULL)){
            printf("%d %d\n", p->data, p->degree);
        }
    }
    return;
}
int main()
{
    int n, i, data;
    scanf("%d", &n);
    for(i=1; i<=n; ++i){
        scanf("%d", &data);
        bst_insert(data);
    }
    traverse(root);
    system("pause");
    return 0;
}
