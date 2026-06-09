#include<stdio.h>
/*typedef struct node
{
    int data;
    struct node *link;
}stack;
void init(stack *p)
{
    p=NULL;
}
int isempty(stack *p)
{
    return (p==NULL);
}
int gettop(stack *p,int *x)
{
    if(isempty(p)) return 0;
    else
    {
        *x=p->data;
        return 1;
    }
}
int push(stack *top,int x)
{
    stack *p;
    if(!p=(stack*)malloc(sizeof(stack))) return 0;
    else
    {
        p->data=x;
        p->link=top;
        top=p;
        return 1;
    }
}
int pop(stack *top,int x)
{
    if(isempty(top)) return 0;
    else
    {
        p=top;
        top=top->link;
        free(p);
        return 1;
    }
}*/
int main()
{
    int stack[100],op,i,in[200]={0},j,u;
    for(i=0;op!=-1;i++)
    {
        scanf("%d",&op);
        in[i]=op;
    }
    //printf("1\n");
    for(j=0,u=0;j<i;j++)
    {
        if(in[j]==1)
        {
            if(u<100)  stack[u++]=in[++j];
            else printf("error ");
        }
        else if(in[j]==0)
        {
            if(u>0)  printf("%d ",stack[--u]);
            else printf("error ");
        }
    }
    return 0;
}























