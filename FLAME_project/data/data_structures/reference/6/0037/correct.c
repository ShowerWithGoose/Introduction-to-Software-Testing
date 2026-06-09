#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct strack
{
    int top;
    int num[101];
};

int main()
{
    struct strack a;
    int n,m;
    a.top=-1;
    while(scanf("%d",&n)!=-1)
    {
        if(n==1)
        {
            scanf("%d",&m);
            if(a.top>=100)
            {
                printf("error !");
            }
            else
            {
                a.top++;
                a.num[a.top]=m;
            }
        }
        else if(n==0)
        {
            if(a.top<=-1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",a.num[a.top]);
                a.top--;
            }
        }

    }
}

