#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ The loop condition checks for return value -1, but should check if the read value is -1 to stop processing operations as per problem description. Also, scanf returns EOF on failure, not necessarily -1 for the value read.
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
        if(n[j]==0)
        {
            if(k==-1) // @@ The condition for an empty stack is k==0, not k==-1. k represents the number of elements in the stack (or the index of the next free slot). If k is 0, the stack is empty.
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