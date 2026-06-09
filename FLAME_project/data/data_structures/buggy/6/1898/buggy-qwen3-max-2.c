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
            j++; // @@ [After pushing, we must skip the next element (the value to push), otherwise it will be treated as an operation in the next iteration. The original code only increments j once at the end of the loop, causing the pushed value to be reinterpreted as an operation.]
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ [The stack is empty when k == 0, not k == -1. Since k represents the number of elements in the stack (or the next available index), checking k == -1 is incorrect and will never trigger the "error" for popping from an empty stack. It should be if(k == 0).]
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