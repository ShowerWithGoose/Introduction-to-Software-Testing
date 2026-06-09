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
    else if(op==0) // @@ [This condition is redundant and unreachable because op==0 is already handled above. The intended condition to break the loop is op==-1, not op==0 again. This causes the loop to never terminate on -1 input, leading to infinite loop or undefined behavior.]
    break;
    }
    

return 0;
}