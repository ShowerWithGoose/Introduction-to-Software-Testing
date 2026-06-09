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
                continue; // @@ [continue causes infinite loop because it skips the next scanf, and a remains 1, leading to repeated error]
            }
            else
            {
                stack[top]=a; // @@ [should read the value to push, not use a. Missing scanf for the push value.]
                top++;
            }
        }
        else if(a==0)
        {
            if(top==0)
            {
                printf("error ");
                continue; // @@ [continue causes infinite loop because it skips the next scanf, and a remains 0, leading to repeated error]
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