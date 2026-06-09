#include <stdio.h>
#include <stdlib.h>
struct node
{
    int deep;
    int num;
    struct node *lchild, *rchild;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,int item,int temdeep);
void print(BTNodeptr p);
int main(int argc, char const *argv[])
{
    int n,i,data;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int temdeep=0;
        scanf("%d",&data);
        root=insertBST(root,data,temdeep);
    }
    print(root);
    return 0;
}
BTNodeptr insertBST(BTNodeptr p,int item,int temdeep)
{
    temdeep++;
    if(p==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->num=item;
        p->lchild=NULL;
        p->rchild=NULL;
        p->deep=temdeep;
    }
    else if(item<p->num)
    {
        p->lchild=insertBST(p->lchild,item,temdeep);
    }
    else if(item>=p->num)
    {
        p->rchild=insertBST(p->rchild,item,temdeep);
    }
    return p;
}
void print(BTNodeptr p)
{
    if(p!=NULL)
    {
        if(p->lchild==NULL&&p->rchild==NULL)
        {
            printf("%d %d\n",p->num,p->deep);
        }
        print(p->lchild);
        print(p->rchild);
    }
}
