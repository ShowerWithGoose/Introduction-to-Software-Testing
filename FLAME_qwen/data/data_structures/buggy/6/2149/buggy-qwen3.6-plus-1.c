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
                continue; // @@ Skips reading the integer to be pushed, causing the input stream to misalign and creating an infinite loop since 'a' remains 1.
            }
            else
            {
                stack[top]=a; // @@ Assigns the operation code '1' to the stack instead of reading and pushing the actual integer value provided in the input.
                top++;
            }
        }
        else if(a==0)
        {
            if(top==0)
            {
                printf("error ");
                continue;
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