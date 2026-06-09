#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXNUM 100

int stack[MAXNUM];
int top=-1;

int main()
{
    int op,num;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==-1)
        {
            system("pause");
            return 0;
        }
        else if(op==1)
        {
            scanf("%d",&num);
            if(top==MAXNUM-1)
            {
                printf("error ");
            }
            else
            {
                stack[++top]=num;
            }
        }
        else if(op==0)
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",stack[top--]);
            }
        }
    }
    return 0;
}
