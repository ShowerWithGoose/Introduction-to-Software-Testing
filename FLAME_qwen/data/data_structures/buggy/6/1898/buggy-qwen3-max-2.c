#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ [The loop does not stop when reading -1; it continues until EOF, which may read beyond the intended input and cause undefined behavior or infinite loop if input is not terminated by EOF.]
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
            m[k]=n[j+1]; // @@ [When j is the last index (j == i-1), n[j+1] accesses out-of-bounds memory because the input ends with -1 and there's no guarantee that a value follows the last '1'.]
            k++;
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ [k is never negative because it starts at 0 and is only decremented after a pop. The correct check for empty stack is k == 0, not k == -1.]
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