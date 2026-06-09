#include <stdio.h>
struct node
{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;//
int deep = 1;//
BTNodeptr  insertBST(BTNodeptr p, int item);//
void  preorder(BTNodeptr t);//
int main()
{
    int n, i, item;
    BTNodeptr  root=NULL;//
    scanf("%d",&n);//
    for(i=0; i<n; i++)  //构造一个有n个元素的BST树
    {
         scanf("%d", &item);
         root = insertBST(root, item);
    }
    preorder(root);   //前序遍历
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, int item)
{
    if(p == NULL)   //找到位置 建立结点
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));//
        p->data = item;//
        p->lchild = p->rchild = NULL;//
    }
    else if( item < p->data)    //向左插入
        p->lchild = insertBST(p->lchild, item);
    else if( item >= p->data)    //向右插入
       p->rchild = insertBST(p->rchild,item);
    return p;
}
void preorder(BTNodeptr t) //前序遍历
{
    if(t!=NULL)
    {
        if(t->lchild==NULL && t->rchild==NULL)
            printf("%d %d\n",t->data,deep);//
        deep++;
        preorder(t->lchild);//
        preorder(t->rchild);//
        deep--;
    }
    return;
}


