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
    } // @@ [Only increments cnt_i when x1 < x2, but input guarantees x1 < x2, so this condition is redundant and causes fewer than n segments to be stored if any segment violates the condition (which shouldn't happen per problem statement). However, more critically, if a segment has x1 >= x2 (which shouldn't occur per input spec), it would be skipped, leading to uninitialized data being used later. But the real issue is that cnt_i starts at 0 and only increments after storing, so arr[0] is always written, but if n>0 and all inputs are valid, cnt_i becomes n. However, the loop runs n times regardless, so if an invalid segment were present (x1>=x2), cnt_i < n, and later loops over i from 0 to n-1 will access uninitialized arr[i] entries.]

    
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
    } // @@ [This loop tries to find starting segments (those not ending at another segment's start). However, it assumes arr[i] contains valid data for all i in [0, n-1], but if cnt_i < n due to the earlier condition, arr[i] for i >= cnt_i is uninitialized, leading to undefined behavior.]

    
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
        } // @@ [The inner loop attempts to chain segments by resetting j to 0 whenever a connection is found (via flag). However, resetting j=0 inside the loop causes infinite looping because the for-loop header does j++ after each iteration, so after setting j=0, it becomes j=1 next, skipping index 0. Also, this approach may count the same segment multiple times or miss connections due to improper traversal order. Moreover, it accesses arr[j] for j in [0, n-1], which again may be uninitialized if cnt_i < n.]

        if(cnt>=max)
        {
            max=cnt;
            max_k=i;
        }
    }
    
    printf("%d ",max);
    printf("%d %d",L[max_k].x1,L[max_k].y1); // @@ [If no valid chain is found (e.g., k=0), max_k remains -1, leading to accessing L[-1], which is undefined behavior. Also, if max is 0, printing L[max_k] is invalid.]
    return 0;
}