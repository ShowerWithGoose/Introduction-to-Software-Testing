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
                j++; // @@ [Should increment j by 2 to skip both the operation code and the value; otherwise the value will be processed as next operation]
                continue;
            }
            m[k]=n[j+1];
            k++; // @@ [After storing the value, need to increment j to skip the value element; otherwise the value will be processed as next operation]
        }
        if(n[j]==0)
        {
            if(k==-1) // @@ [Condition should be k==0 to correctly detect empty stack]
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