#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ [The loop condition does not stop at -1; it reads until EOF, causing extra values to be read beyond -1 and leading to incorrect processing of operations.]
    {
        i++;
    }
    int j=0,k=0;
    while(j<i)
    {
        if(n[j]==1)
        {
            if(k==100)
            {
                printf("error ");
                j++;
                continue;
            }
            m[k]=n[j+1];
            k++;
        }
        if(n[j]==0) // @@ [This should be 'else if' to avoid checking for pop operation immediately after a push; otherwise, when an operation is 1 (push), the next value (the pushed number) might be misinterpreted as an operation (e.g., if it's 0).]
        {
            if(k==-1) // @@ [k starts at 0 and is decremented after pop, so empty stack is when k == 0, not k == -1. This causes incorrect "error" output only after underflow has already occurred.]
            {
                printf("error ");
                j++;
                continue;
            }
            printf("%d ",m[k-1]);
            m[k-1]=0;
            k--;
        }
        j++;
    }
    return 0;
}