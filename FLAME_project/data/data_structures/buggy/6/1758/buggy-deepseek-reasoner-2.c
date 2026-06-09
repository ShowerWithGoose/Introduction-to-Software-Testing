#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1) // @@ [Loop should break when t==-1 to stop processing; current condition only breaks on EOF, causing -1 to be treated as a command]
    {
        if(t==1)
        {
            n++;
            scanf("%d",&s[n]);
            
        }
        if(t==0&&n!=-1)
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else // @@ [This else catches all cases where t is not 0 or where n==-1 for t==0, including t==-1. It should only handle pop when empty, i.e., t==0 && n==-1, but it incorrectly triggers for -1.]
        {
            if(n==-1)
            {
                 printf("error "); // @@ [Prints error when processing -1 because condition t==0 failed and n==-1 is true]
                          
            }
        }
    }
    return 0;
 }