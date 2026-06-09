#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100];
int main()
{    int op,top=-1;
    while(1)
    {scanf("%d",&op);
    if(op==1)
    {top++;
    if(top<100)
    scanf("%d",&stack[top]);
    else
    {printf("error ");
    top--;
    }
    }
    else if(op==0)
    {if(top>=0)
    {printf("%d ",stack[top]);
    top--;
    }
    else
    printf("error ");
    }
    else if(op==0) // @@ [This condition is redundant and unreachable because the previous 'else if(op==0)' already handles op==0. The termination condition should be 'else if(op==-1)' to match the problem description, but here it incorrectly checks for op==0 again, so the loop never breaks on -1 input.]
    break;
    }
    

return 0;
}