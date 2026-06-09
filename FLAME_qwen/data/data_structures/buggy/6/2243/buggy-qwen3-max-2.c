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
    else if(op==0) // @@ [This condition is redundant and unreachable because the previous 'else if(op==0)' already handles op==0. The intended condition to break the loop is 'op == -1', but it's missing. As a result, when op is -1, none of the conditions match, causing an infinite loop instead of terminating.]
    break;
    }
    

return 0;
}