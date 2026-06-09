
#include <stdio.h>

struct node
{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;

int deep = 1;
BTNodeptr  insertBST(BTNodeptr p, int item);
void  preorder(BTNodeptr t);

int main()
{
    int n, i, item;
    BTNodeptr  root=NULL;
    scanf("%d",&n);
    i=0;
    while( i<n)  
    {
         scanf("%d", &item);
         root = insertBST(root, item);
         i++;
    }
    preorder(root);  
    return 0;
}

BTNodeptr  insertBST(BTNodeptr p, int item)
{
    if(p == NULL)  
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->lchild = p->rchild = NULL;
    }
    else if( item < p->data)    
        p->lchild = insertBST(p->lchild, item);
    else if( item >= p->data)   
       p->rchild = insertBST(p->rchild,item);
    return p;
}

void preorder(BTNodeptr t) 
{
    if(t!=NULL)
    {
        if(t->lchild==NULL && t->rchild==NULL)
            printf("%d %d\n",t->data,deep);
        deep++;
        preorder(t->lchild);
        preorder(t->rchild);
        deep--;
    }
    return;
}



