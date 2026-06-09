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
            m[k]=n[j+1]; // @@ [When j is the last index (j == i-1), n[j+1] accesses out-of-bounds memory because the input ends with -1 and no value follows the last operation.]
            k++;
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ [k starts at 0 and is decremented after pop; it should be checked if k <= 0 or k == 0 for empty stack, not k == -1. This causes underflow check to fail when stack is actually empty (k == 0).]
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