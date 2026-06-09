#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int date;
    int high;
    struct node *lchild,*rchild;
};
typedef struct node *BTNodeptr;
typedef struct node BTNode;
BTNodeptr root=NULL,p,q;

void insertBST(int n)
{
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->date=n;
    p->lchild=NULL;
    p->rchild=NULL;
    if(root==NULL)
    {
        p->high=1;
        root=p;
    }
    else
    {
        q=root;
        while(1)
        {
            if(n<q->date)
            {
                if(q->lchild==NULL)
                {
                    p->high=q->high+1;
                    q->lchild=p;
                    break;
                }
                else
                {
                    q=q->lchild;
                }
            }
            else
            {
                if(q->rchild==NULL)
                {
                    p->high=q->high+1;
                    q->rchild=p;
                    break;
                }
                else
                    q=q->rchild;
            }
        }   
    }
}

void searchBST(BTNodeptr q)
{   
    if(q!=NULL)
    {
        if(q->lchild==NULL&&q->rchild==NULL)
            printf("%d %d\n",q->date,q->high);
        searchBST(q->lchild);
        searchBST(q->rchild);
    }

}
signed main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        insertBST(m);
    }
    q=root;
    searchBST(q);
    return 0;
}
