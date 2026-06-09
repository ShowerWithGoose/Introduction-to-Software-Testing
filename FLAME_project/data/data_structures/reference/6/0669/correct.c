#include<stdio.h>
int stack[110];
int top=-1;
int item,op;
int main()
{
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&item);
            stack[++top]=item;
        }
        else if(op==0)
        {
            if(top==-1) printf("error ");
            else printf("%d ",stack[top--]);
        }
        else if(op==-1) break;
    }
}
