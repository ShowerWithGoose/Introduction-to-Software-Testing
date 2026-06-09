#include<stdio.h>
int a[100]={0};
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x==1)
        {
            scanf("%d",&x);
            if(i==99)
            {
                printf("error ");
            }
            else
            {
                a[i]=x;
                i++;
            }
        }
        else
        {
            if(i==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",a[i-1]); // @@ [When popping, the program should output the top element of the stack (which is at index i-1), but the original code does not print anything and instead sets a[i]=0, which is incorrect behavior.]
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}