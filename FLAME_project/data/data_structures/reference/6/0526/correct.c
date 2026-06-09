#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct stack
{
    int num[105];
    int top
} s;

int n;

int main()
{
    s.top=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {
            scanf("%d",&s.num[s.top]);
            if(s.top>=100)
            {
                printf("error ");
            }
            else
                s.top++;
        }
        if(n==0)
        {
            if(s.top<1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",s.num[s.top-1]);
                s.top--;
            }

        }

        if(n==-1)
        {
            break;
        }
    }
    return 0;
}

