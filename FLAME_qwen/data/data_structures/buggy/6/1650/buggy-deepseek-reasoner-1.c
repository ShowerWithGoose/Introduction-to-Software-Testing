#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [stack should be int type because pushed values are integers, not characters; char cannot properly store arbitrary integer values.]
int top=-1;
int main()
{
    int a,b;
    scanf("%d",&a);
    while(a!=-1)
    {
        if(a==1)
        {
            scanf("%d",&b);
            if(top==100) // @@ [Condition should be top==MAX-1 or top==99; using top==100 will never detect a full stack (top never reaches 100 before overflow), and allows out-of-bounds access.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [If top==99, ++top becomes 100, writing to stack[100] which is out-of-bounds; also type mismatch (char vs int).]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [stack is char, but %d expects int; values may be truncated or printed incorrectly.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}