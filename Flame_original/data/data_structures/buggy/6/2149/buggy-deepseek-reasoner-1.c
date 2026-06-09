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
                continue; // @@ [This continue causes an infinite loop when stack is full; after printing error, the program should read the next operation (including the value that was supposed to be pushed), not skip it.]
            }
            else
            {
                stack[top]=a; // @@ [Incorrectly stores the operation code 1 instead of the actual integer to push. The program does not read the value after the operation, causing data misalignment and incorrect stack content.]
                top++;
            }
        }
        else if(a==0)
        {
            if(top==0)
            {
                printf("error ");
                continue; // @@ [This continue causes an infinite loop when popping from empty stack; after printing error, the program should read the next operation, not skip it.]
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