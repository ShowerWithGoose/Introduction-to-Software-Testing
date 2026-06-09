#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct _line
{
    int x1;
    int y1;
    int x2;
    int y2;
} Line,*Lineptr;

Line L[110];
int arr[110][4];

int main()
{
    int i,j,n,k=0,flag=0,max=0,cnt=1,max_k=-1,cnt_i=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&arr[cnt_i][0],&arr[cnt_i][1],&arr[cnt_i][2],&arr[cnt_i][3]);
        if(arr[cnt_i][0]<arr[cnt_i][2])
        {
            cnt_i++;
        }
    } // @@ [This loop only stores segments where x1 < x2, but the problem guarantees this condition. However, it uses cnt_i to index arr, which may result in reading uninitialized data later because not all n input lines are stored if some violate x1 < x2 (which shouldn't happen per input guarantee). But more critically, the loop runs 'n' times but only increments cnt_i conditionally, so arr may have fewer than n valid entries, yet later loops iterate up to 'n', accessing uninitialized or zero-initialized elements, leading to incorrect logic.]

    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(arr[i][0]==arr[j][2]&&arr[i][1]==arr[j][3])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            L[k].x1=arr[i][0];
            L[k].y1=arr[i][1];
            L[k].x2=arr[i][2];
            L[k].y2=arr[i][3];
            k++;
        }
        flag=0;
    } // @@ [This loop assumes arr[0..n-1] contains all original segments, but due to the previous loop's conditional increment of cnt_i, arr[i] for i >= cnt_i may be uninitialized (or zero), leading to incorrect identification of starting segments (those with no predecessor). This breaks the chain-building logic.]

    
    for(i=0;i<k;i++)
    {
        cnt=1;
        for(j=0;j<n;j++)
        {
            if(flag==1)
            {
                j=0;
                flag=0;
            }
            if(L[i].x2==arr[j][0]&&L[i].y2==arr[j][1])
            {
                L[i].x2=arr[j][2];
                L[i].y2=arr[j][3];
                flag=1;
                cnt++;
            }
        } // @@ [The inner loop resets j to 0 when flag==1, causing an infinite loop if multiple segments can extend the chain, because after resetting j=0, it will reprocess earlier segments and potentially match again, setting flag=1 repeatedly. Also, it doesn't mark used segments, so the same segment might be used multiple times in a chain, violating the problem constraints.]

        if(cnt>=max)
        {
            max=cnt;
            max_k=i;
        }
    }
    
    printf("%d ",max);
    printf("%d %d",L[max_k].x1,L[max_k].y1); // @@ [If no valid chain is found (e.g., max_k remains -1), this accesses L[-1], causing undefined behavior. Also, due to earlier logic errors, the chain length and start point may be incorrect.]

    return 0;
}