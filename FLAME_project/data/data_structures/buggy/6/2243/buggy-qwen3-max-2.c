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
    else if(op==0) // @@ [This condition is unreachable because it duplicates the previous 'else if(op==0)' block. The intended condition should be 'else if(op==-1)' to break the loop when -1 is encountered. As a result, the loop never terminates on input -1, causing infinite loop and Time Limit Exceeded.]
    break;
    }
    

return 0;
}