#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n[110],m[110];
    int i=0;
    while(scanf("%d",&n[i])!=-1) // @@ The loop condition checks for return value -1, but should check for EOF or the specific terminator -1 within the input stream logic properly. More critically, it doesn't stop reading when -1 is encountered as a data element, leading to reading beyond intended input if not handled. However, the primary logical error is below.
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
            if(k==-1) // @@ The condition for checking if the stack is empty is incorrect. 'k' represents the number of elements in the stack (or the index of the next free slot). If the stack is empty, k should be 0. Checking for k==-1 is wrong because k starts at 0 and decreases only after a pop. It will never be -1 inside this check unless underflowed previously, but the correct check for empty stack before popping is k==0.
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