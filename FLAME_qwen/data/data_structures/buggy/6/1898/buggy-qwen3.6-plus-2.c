#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ scanf returns the number of successfully read items, not the value read. It will not terminate when -1 is input. Should check if n[i] == -1.
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
                j++; // @@ Only skips the '1' operation code, but fails to skip the subsequent value to be pushed. The value will be processed as an operation in the next iteration. Should be j += 2;
                continue;
            }
            m[k]=n[j+1];
            k++;
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ k tracks the number of elements. When empty, k is 0, not -1. This condition never triggers for an empty stack, causing out-of-bounds access m[-1]. Should be k == 0.
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