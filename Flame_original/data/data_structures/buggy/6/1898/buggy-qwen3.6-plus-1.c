#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ scanf returns the number of successfully read items, not the input value. The loop should terminate when the read value is -1, not when scanf returns -1 (EOF).
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
            m[k]=n[j+1]; // @@ After pushing the value, j should be incremented again to skip the value in the next iteration; otherwise, the pushed value will be incorrectly processed as a stack operation.
            k++;
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ k represents the number of elements in the stack and starts at 0. The condition to check for an empty stack should be k==0, not k==-1.
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