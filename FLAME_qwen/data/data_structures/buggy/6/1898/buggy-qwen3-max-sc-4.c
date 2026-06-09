#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ [The loop condition does not stop when reading -1; it continues until EOF, which may read beyond the intended input and cause undefined behavior or infinite loop if input doesn't end with EOF. The problem specifies that -1 marks the end of operations, so the loop should break when n[i] == -1.]
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
            m[k]=n[j+1]; // @@ [When j is the last valid index (i-1), accessing n[j+1] reads out of bounds because the input ends with -1 and there's no guarantee that a number follows the final 1. This leads to undefined behavior.]
            k++;
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ [k starts at 0 and is decremented only after a pop, so k can never be -1 before a pop. The correct underflow check is k == 0, not k == -1. This causes the program to miss detecting empty-stack pop errors.]
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