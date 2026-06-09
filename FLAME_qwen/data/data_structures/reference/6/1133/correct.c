#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct stack
    {
    int top;
    int x[1000];
};
struct stack s;

int main()
{
    int a,b,i,j;
    s.top=0;
    while(~scanf("%d",&a))
    {
        if(a==1)
        {
            scanf("%d",&b);
            if(s.top<100)
            {
                s.x[s.top]=b;s.top++;
            }
            else printf("error ");
        }
        else if(a==0)
        {
            if(s.top>=1)
            {
                printf("%d ",s.x[s.top-1]);s.top--;
            }
            else printf("error ");
        }
        else break;
    }
    return 0;
    
}

