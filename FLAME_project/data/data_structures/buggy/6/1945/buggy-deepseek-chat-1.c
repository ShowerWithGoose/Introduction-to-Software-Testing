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
                a[i]=0; // @@ The pop operation should output the popped element, but here it only sets the array element to 0 without printing anything. Additionally, the stack top should be decremented before or after output, but the logic here incorrectly sets a[i]=0 and then decrements i, which does not match the expected behavior of a stack pop.
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}