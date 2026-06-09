#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top;
void initStack()
{
    top=NULL;
}
int isEmpty()
{
    return top==NULL;
};
void push(int n)
{
    struct node* p;
    if((p=(struct node*)malloc(sizeof(struct node)))==NULL)
        printf("error ");
    else
    {
        p->data=n;
        p->link=top;
        top=p;
    }
};
void pop()
{
    struct node* p;
    int n;
    if(isEmpty())
        printf("error ");
    else
    {
        p=top;
        n=p->data;
        top=top->link;
        free(p);
        printf("%d ",n);
    }
};
int main()
{
    int com,num;
    initStack();
    scanf("%d",&com);
    while(com!=-1)
    {
        if(com==1)
        {   scanf("%d",&num); 
            push(num);}
        else
            pop();
        scanf("%d",&com);

    }
    return 0;
}
