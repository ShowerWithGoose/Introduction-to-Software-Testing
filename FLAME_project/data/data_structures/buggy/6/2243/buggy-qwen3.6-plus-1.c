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
    else if(op==0) // @@ The condition checks for op==0 again, which was already handled in the previous else-if block. It should check for op==-1 to break the loop. Because it never breaks on -1, the loop continues indefinitely waiting for more input or failing to terminate, causing Time Limit Exceeded.
    break;
    }
    

return 0;
}