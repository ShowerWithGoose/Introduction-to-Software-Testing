#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int isEmpty( )
{
    return top==-1;
} 
int isFull(  )
{
    return top==99;
}
int push()
{
    if(isFull()==1)
    {
        printf("error ");
        return 0;
    } 
    else
    {
        scanf("%d",&stack[++top]);
        return 1;
    }
}
int  pop()
{
    if(isEmpty()==1)
    {
        printf("error ");
        return 0;
    } 
    else
    {
        printf("%d ",stack[top--]);
        return 1;
    }
}
int main()
{
    int act=0;
    while(scanf("%d",&act)!=EOF)
    {
        if(act==1)
        {
            push();
        }
        else if(act==0)
        {
            pop();
        }
        else if(act==-1)
            break;
    }
    return 0;
}
