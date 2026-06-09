#include <stdio.h>
int stack[100];
int top=-1;
int main()
{
    int op,t;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==1)
        {
            if(top<=98)
            {
                scanf("%d",&stack[top+1]);
                top++;
            }
            else
            {
                scanf("%d",&t);
                printf("error ");
            }
        }
        if(op==0)
            if(top>=0)
            {
                printf("%d ",stack[top]);
                top--;
            }
            else
            {
                printf("error ");
            }
        if(op==-1)
            break;
    }
    return 0;
}

