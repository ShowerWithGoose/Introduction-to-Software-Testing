#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1)
    {
        if(t==1)
        {
            n++;
            scanf("%d",&s[n]);
            
        }
        if(t==0&&n!=-1) // @@ This condition does not handle the case when t==0 and n==-1 correctly; the else block below will execute for t==1 as well, causing "error " to be printed incorrectly.
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else
        {
            if(n==-1)
            {
                 printf("error ");
                          
            }
        }
    }
    return 0;
 }