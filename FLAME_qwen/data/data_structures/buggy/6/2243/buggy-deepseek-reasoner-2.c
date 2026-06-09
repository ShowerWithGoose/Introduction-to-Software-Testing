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
    else if(op==0)  // @@ [Error: This condition should be `else if(op==-1)` or simply `else` to break when the end-of-operations sentinel (-1) is input. Using `op==0` again makes the break unreachable, causing an infinite loop.]
    break;
    }
    

return 0;
}