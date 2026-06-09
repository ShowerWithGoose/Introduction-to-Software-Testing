#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
    int data;
    int iscome;
    int depth;
    struct bst* front_small;
    struct bst* front_large;
}tree;
tree *list=NULL,*stack[1000]; 
tree* create(tree* ptr,int n)
{
    tree *p,*q;
    q=ptr;
    p=(tree*)malloc(sizeof(tree));
    p->data=n;
    p->iscome=0;
    p->depth=1;
    p->front_large=NULL;
    p->front_small=NULL;
    if(ptr==NULL)
    {
        p->data=n;
        return p;
    }
    else
    {
        for(;(n<q->data&&q->front_small!=NULL)||(n>=q->data&&q->front_large!=NULL);)
        {
            p->depth++;
            if(n<q->data) q=q->front_small;
            else q=q->front_large;
        }
        p->depth++;
        if(n<q->data)
        {
            q->front_small=p;
        }
        else
        {
            q->front_large=p;
        }
        return ptr;
    }
}
int main()
{
    int i,n,j;
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        scanf("%d",&n);
        list=create(list,n);
    }
    i=0;
    stack[0]=list;
    while(i!=-1)
    {
        if(stack[i]->front_small==NULL&&stack[i]->front_large==NULL)
        {
            printf("%d %d\n",stack[i]->data,stack[i]->depth);
            i--;
        }
        else if(stack[i]->iscome==0&&stack[i]->front_small!=NULL)
        {
            stack[i]->iscome=1;
            stack[i+1]=stack[i]->front_small;
            i++;
        }
        else if(stack[i]->iscome==0&&stack[i]->front_small==NULL)
        {
            stack[i]->iscome=1;
        }
        else if(stack[i]->iscome==1&&stack[i]->front_large!=NULL)
        {
            stack[i]->iscome=2;
            stack[i+1]=stack[i]->front_large;
            i++;
        }
        else if(stack[i]->iscome==1&&stack[i]->front_large==NULL)
        {
            stack[i]->iscome=2;
        }
        else if(stack[i]->iscome==2)
        {
            i--;
        }
    }
    return 0;
}
