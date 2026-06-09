#include<stdio.h>
int stack[100];
int main()
{
    int top=0;
    int a;
    scanf("%d",&a);
    while(a!=-1)
    {
        if(a==1)
        {
            if(top==100)
            {
                printf("error ");
                continue; // @@ Error: 'continue' skips the scanf at the end of the loop, causing an infinite loop and failing to consume the input value intended for the push operation.
            }
            else
            {
                stack[top]=a; // @@ Error: pushes the operation code 1 instead of the actual value to be pushed. It also misses reading the value from input using scanf.
                top++;
            }
        }
        else if(a==0)
        {
            if(top==0)
            {
                printf("error ");
                continue; // @@ Error: 'continue' skips the scanf at the end of the loop, causing an infinite loop when the stack is empty.
            }
            else{
                printf("%d ",stack[top-1]);
                top--;

            }
        }
        scanf("%d",&a);

    }
    return 0;

}