#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Tree_Node
{
    int number;
    int lay;
    struct Tree_Node *ltree,*rtree;
}*Nodeptr;
Nodeptr p,q,head;
int sum;
void Tree_Create(Nodeptr,int);
void Tree_output(Nodeptr);
int main()
{
    int num;
    scanf("%d",&sum);
    scanf("%d",&num);
    p=(Nodeptr)malloc(sizeof(struct Tree_Node));
    p->number=num;
    p->lay=1;
    p->ltree=NULL;
    p->rtree=NULL;
    head=p;
    for(int i=1;i<sum;i++)
    {
        scanf("%d",&num);
        Tree_Create(head,num);
    }
    Tree_output(head);
    return 0;
}
void Tree_Create(Nodeptr head,int index)//它不负责搭建头节点
{
    p=(Nodeptr)malloc(sizeof(struct Tree_Node));
    p->number=index;
    p->lay=2;
    p->ltree=NULL;
    p->rtree=NULL;
    for(q=head;;)
    {
        if(p->number<q->number)
        {
            if(q->ltree==NULL)
            {
                q->ltree=p;
                return;
            }
            else
            {
                q=q->ltree;
                p->lay++;
            }
        }
        else if(p->number>=q->number)
        {
            if(q->rtree==NULL)
            {
                q->rtree=p;
                return;
            }
            else
            {
                q=q->rtree;
                p->lay++;
            }
        }
    }
    
}
void Tree_output(Nodeptr p)//此时应该用中序遍历
{
    if(sum==0)
        return;
    if((p->ltree==NULL)&&(p->rtree==NULL))
        {
        printf("%d %d\n",p->number,p->lay);
        //sum--;
        return;
        }
    else
    {
    if(p->ltree!=NULL)
        {
        Tree_output(p->ltree);
        //puts("To the left!!!");
        }
    if(p->rtree!=NULL)
        {
        Tree_output(p->rtree);
        //puts("To the right!!!");
        }
    }
    sum--;
}
