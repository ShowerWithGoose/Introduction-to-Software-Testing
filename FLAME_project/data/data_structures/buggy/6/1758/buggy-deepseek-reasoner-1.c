#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1) // @@ Missing handling for the -1 end-of-operations marker; the loop should break when t==-1, but instead it continues and the else block incorrectly prints "error" for -1 after the stack becomes empty.
    {
        if(t==1)
        {
            n++; // @@ No overflow check: before incrementing n, must verify that n < 99 (since capacity is 100, top index before push must be ≤ 98) to avoid writing beyond array bounds and to properly report "error" when stack is full.
            scanf("%d",&s[n]);
            
        }
        if(t==0&&n!=-1)
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else
        {
            if(n==-1) // @@ This condition is true not only when a pop is attempted on an empty stack but also when the operation is -1 (end marker) and the stack is empty, causing an erroneous "error" output.
            {
                 printf("error ");
                          
            }
        }
    }
    return 0;
 }