#include<stdio.h>
int top;
int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==99;
}
int main()
{
    int i,x;
    int stack[100];
    top=-1;
    scanf("%d",&i);
    while(i!=-1)
    {       
        switch(i)
        {
            case 1:
            scanf("%d",&x);
            if(isfull())
            {
                printf("error ");
                break;
            }
            else
            {
                stack[++top]=x;
                break;
            }
            case 0:
            if(isempty())
            {
                printf("error ");
                break;
            }
            else
            {
                printf("%d ",stack[top--]);
                break;
            }
        }
        scanf("%d",&i);
    }
}
