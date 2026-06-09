#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ This loop does not stop when reading the terminating -1; it reads until EOF, which may cause the -1 to be stored and processed incorrectly. Should break when n[i]==-1.
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
            m[k]=n[j+1]; // @@ Missing increment of j to skip the pushed value. The program should increment j after using n[j+1] to avoid treating the value as an operation in subsequent iterations.
            k++;
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ Incorrect empty stack condition. Should be `if(k==0)` because k represents the number of elements. k==-1 will never be true, so pop on empty stack will not print "error" and will access out-of-bounds memory.
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