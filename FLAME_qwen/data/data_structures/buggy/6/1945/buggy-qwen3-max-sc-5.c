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
                printf("%d ",a[i-1]); // @@ [The original code does not print the popped element; it just sets a[i]=0 and decrements i. According to the problem, every pop operation (x==0) must output the popped value. The current code only handles printing for push errors or pop errors but not successful pops. Also, the 'else' block treats any non-1 and non--1 input as a pop, which is correct per problem (since only 1, 0, -1 are valid), but missing the print statement for successful pop.]
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}