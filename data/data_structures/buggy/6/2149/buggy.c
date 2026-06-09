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
                stack[top]=a;
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
