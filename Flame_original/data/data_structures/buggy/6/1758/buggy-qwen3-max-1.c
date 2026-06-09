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
        if(t==0&&n!=-1)
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
 } // @@ [The loop condition `scanf("%d",&t)!=-1` does not stop on input -1 as required; it continues until EOF or read error. Also, the logic for handling pop (0) incorrectly uses an else that triggers even for non-zero operations, causing spurious "error" prints. Additionally, stack overflow (push when full) is not checked.]