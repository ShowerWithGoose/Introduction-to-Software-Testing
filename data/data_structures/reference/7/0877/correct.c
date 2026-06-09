#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int floornow=1;

struct node
{
    int num;
    int floor;
    struct node* lchild,* rchild;
};

struct node* insertT(struct node* p,int numin,int floor)
{
    if(p==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->num=numin;
        p->floor=floor+1;
        p->lchild=NULL;
        p->rchild=NULL;
    }
    else if(numin>=(p->num))
    {
        p->rchild=insertT(p->rchild,numin,p->floor);
    }
    else if(numin<(p->num))
    {
        floornow++;
        p->lchild=insertT(p->lchild,numin,p->floor);
    }
    return p;
}

void printleaf(struct node*p)
{
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->num,p->floor);
    }
    if(p->lchild!=NULL)
    {
        printleaf(p->lchild);
    }
    if(p->rchild!=NULL)
    {
        printleaf(p->rchild);
    }
}

int main()
{
    int n,tempnum;
    struct node *head;
    head=NULL;
    scanf("%d\n",&n);
    //printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tempnum);
        //printf("%d ",tempnum);
        head=insertT(head,tempnum,0);
    }
    printleaf(head);
    system("pause");
    return 0;
}
