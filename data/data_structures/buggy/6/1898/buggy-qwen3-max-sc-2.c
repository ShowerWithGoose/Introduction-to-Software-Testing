#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1)
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
            j++; // @@ [After pushing, we must skip the next element (the value to push), otherwise it will be treated as an operation in the next iteration. The original code does not increment j here, causing the pushed value to be reinterpreted as an operation.]
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ [k represents the number of elements in the stack, so when the stack is empty, k should be 0, not -1. Checking k==-1 will never be true because k starts at 0 and is decremented only after a pop. This leads to popping from an empty stack without detecting the error.]
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