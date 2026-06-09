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
 } // @@ [The loop condition `scanf("%d",&t)!=-1` does not stop when input is -1 as required by the problem; it continues until EOF or read error. Also, the logic for handling pop (0) and error cases is flawed: the `else` block executes for any non-push operation (including valid pushes followed by other operations), leading to spurious "error" outputs. Additionally, stack overflow (push when full) is not checked.]