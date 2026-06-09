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
        if(t==0&&n!=-1) // @@ This condition does not handle the case when t is 0 and n is -1 correctly because the else branch will also execute for t==1 or other values, causing "error " to be printed incorrectly.
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else
        {
            if(n==-1) // @@ This condition is true for any t that is not 0 or when n is -1, including t==1, causing "error " to be printed after a push operation.
            {
                 printf("error ");
                          
            }
        }
    }
    return 0;
 }