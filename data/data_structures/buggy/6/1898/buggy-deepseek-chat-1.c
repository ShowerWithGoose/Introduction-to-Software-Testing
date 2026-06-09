#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ The scanf function returns the number of items read, not -1 on end-of-file. It returns EOF (which is typically -1) on error or end-of-file, but the comparison should be != EOF. Also, the loop will never terminate because scanf returns 1 on successful read, not -1.
    {
        i++;
    }
    int j=0,k=0;
    while(j<i)
    {
        if(n[j]==1)
        {
            if(k==100) // @@ The stack capacity is 100, but k represents the top index (number of elements). When k==100, the stack is full (indices 0-99), so this condition correctly checks for full, but the error message should be printed and then j should be incremented by 2 to skip the push value, not just j++. Also, the continue will skip the increment of j at the end, causing an infinite loop.
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
            if(k==-1) // @@ k is initialized to 0, so k==-1 will never be true. The condition for empty stack should be k==0.
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