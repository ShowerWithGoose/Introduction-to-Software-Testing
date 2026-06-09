#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[110];
int main()
{
    int top=0; // @@ [The initial value of 'top' should be -1 to indicate an empty stack. Using 0 causes the first element to be placed at index 0, but pop operations will incorrectly access stack[top] (i.e., stack[0]) before decrementing, and when the stack is empty (top=0), it fails to detect underflow correctly in some interpretations. However, the real bug is in the pop operation indexing.]
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(top==99)
            printf("error ");
            else
            {
                stack[top]=num;
                top++;
            }
        }
        else if(op==0)
        {
            if(top==0)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [This accesses stack[top], which is one past the last valid element. Since 'top' points to the next available slot, the top element is at stack[top-1]. This causes reading from an uninitialized or incorrect memory location, leading to wrong output like printing 0 instead of 567.]
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}