#include<stdio.h>
int stack[100];
int i,j,c,n;
int top=-1;
int isfull()
{
    return top==99;
}
int isempty()
{
    return top==-1;
}
int main()
{
    while(1)
    {
        scanf("%d",&c);
        if(c)
        {
            scanf("%d",&n);
            //printf("%d",n);
            if(isfull())
                printf("error ");
            else
                {stack[++top]=n;
                //printf("%d",top);
                }

        }
        else if(c==0)
        {
            if(isempty())
                printf("error ");
            else
            {
                printf("%d ",stack[top--]);
                //top--;
            }
        }
        if(c==-1)
            return 0;
    }
}

