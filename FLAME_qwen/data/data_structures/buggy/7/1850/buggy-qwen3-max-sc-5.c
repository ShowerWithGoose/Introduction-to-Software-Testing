#include<stdio.h>
#include<stdlib.h>
typedef struct num{
    int num;
    int high;
    struct num* lchild;
    struct num* rchild;
}num;
num *tree=NULL;
void add(int x)
{
    int h=1;
    num *p,*q=tree;
    p=malloc(sizeof(num));
    if(tree==NULL)
    {
        p->num=x;
        p->high=1;
        p->lchild=NULL;
        p->rchild=NULL;
        tree=p;
    }
    else
    {
        while(1)
        {
            if(x<q->num)
            {
                if(q->lchild!=NULL)
                {
                    q=q->lchild;
                    h++;
                }
                else
                {
                    p->num=x;
                    p->high=h+1;
                    p->lchild=NULL;
                    p->rchild=NULL;
                    q->lchild=p;
                    break;
                }
            }
            else
            {
                if(q->rchild!=NULL)
                {
                    q=q->rchild;
                    h++;
                }
                else
                {
                    p->num=x;
                    p->high=h+1;
                    p->lchild=NULL;
                    p->rchild=NULL;
                    q->rchild=p;
                    break;
                }
            }
        }
    }
    return ;
}
void print(num* p)
{
    if(p==NULL) return; // @@ [Missing null check before accessing p->lchild and p->rchild, leading to potential segmentation fault when called on NULL child]
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->num,p->high);
        return ;
    }
    print(p->lchild);
    print(p->rchild);
}
int main()
{
    int n,x,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        add(x);
    }
    print(tree);
    return 0;
}