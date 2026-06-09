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
    scanf("%d",&stack[top]); // @@ The input number for the push operation is only read when the stack is not full. If the stack is full, the number remains in the input buffer, causing the next scanf("%d",&op) to read it as an operation code, leading to logical errors.
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
    else if(op==0) // @@ The condition to terminate the loop should check for op == -1 (end of operations), not op == 0. Additionally, this condition is unreachable because the previous else if(op==0) already handles the pop operation.
    break;
    }


return 0;
}