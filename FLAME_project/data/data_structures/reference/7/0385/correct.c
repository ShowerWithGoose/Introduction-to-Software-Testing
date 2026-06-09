#include <stdio.h>
#include <stdlib.h>

typedef struct BTN{
    int data;//数据
    struct BTN *lchild, *rchild;
    int dep;//深度
}BTNode, *BTNodeptr;

BTNodeptr root = NULL, p, q;
void build_tree(BTNodeptr *t, int d, int depth);//创建完整的树
void output(BTNodeptr t);//输出结果
void front_tra_tree(BTNodeptr t);//前序遍历树

int main()
{
    int n;//输入数据个数
    int sta;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &sta);
        build_tree(&root, sta, 1);
    }
    front_tra_tree(root);
    return 0;
}

void build_tree(BTNodeptr *t, int d, int depth)
{
    if((*t) == NULL){
        (*t) = (BTNodeptr)malloc(sizeof(BTNode));
        (*t)->lchild = (*t)->rchild = NULL;
        (*t)->data = d;
        (*t)->dep = depth;

    }else{
        if((*t)->data > d)
            build_tree(&((*t)->lchild), d, depth + 1);
        else
            build_tree(&((*t)->rchild), d, depth + 1);
    }
}

void output(BTNodeptr t){
    printf("%d %d\n",t->data, t->dep);
}

void front_tra_tree(BTNodeptr t){
    if(t != NULL){
        if(t->lchild == NULL && t->rchild == NULL)
            output(t);
        front_tra_tree(t->lchild);
        front_tra_tree(t->rchild);
    }
}


