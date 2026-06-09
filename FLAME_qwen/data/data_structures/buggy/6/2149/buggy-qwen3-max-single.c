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
                continue;
            }
            else
            {
                stack[top]=a; // @@ [The program pushes the operation code '1' instead of the next integer from input. It should read another integer to push onto the stack.]
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