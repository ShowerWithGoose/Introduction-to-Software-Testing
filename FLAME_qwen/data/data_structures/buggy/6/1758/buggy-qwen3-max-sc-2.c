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
 } // @@ The loop condition `scanf("%d",&t)!=-1` does not stop at -1 as required by the problem; it continues until EOF or read error. Also, the logic for handling pop on empty stack is flawed because the `else` block executes for any non-push operation when `n==-1`, including after a valid push or when reading -1. Additionally, there's no check for stack overflow during push (max capacity 100), and the program doesn't terminate input processing upon reading -1.