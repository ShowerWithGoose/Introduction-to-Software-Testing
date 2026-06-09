#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int top=0;
int a[110];
int main()
{
    int op,n;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==1)
        {
            scanf("%d",&n);
            if(top>=100)
            {
                printf("error ");
            }
            else
            {
                a[top]=n;
                top++;
            }
        }
        else if(op==0)
        {
            if(top<=0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",a[top-1]);
                top--;
            }
        }
        else if(op==-1)
        {
            break;
        }
    }

return 0;
}

