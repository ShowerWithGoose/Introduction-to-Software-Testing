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
    } // @@ [This loop only stores segments where x1 < x2, but the problem guarantees this condition already. However, it may skip storing some input lines if x1 >= x2 (which shouldn't happen per problem), but more critically, it uses cnt_i to index arr while looping i from 0 to n-1, causing fewer than n segments to be stored if any segment violates x1<x2 — but even worse: if all segments satisfy x1<x2, then cnt_i becomes n, but the loop runs n times, so arr[0..n-1] is filled correctly. However, later loops iterate up to 'n' assuming all inputs are stored in arr[0..n-1], but if any segment had x1>=x2 (which shouldn't per problem), it would store fewer. But the real bug is below.]

    
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
    } // @@ [This loop tries to find starting segments (those not ending at another's start). However, it assumes all n input segments are stored in arr[0..n-1], but if the first loop skipped any (due to x1>=x2), then arr[i] for i beyond cnt_i-1 is uninitialized (garbage). Even if all are stored, the logic is flawed: it checks if segment i starts where segment j ends — but the condition arr[i][0]==arr[j][2] means segment i's start equals segment j's end, so segment j comes before i. Thus, if such a j exists, segment i is NOT a start. So this part is logically correct for finding starts. However, the bigger issue is that the first loop may not have stored all n segments into arr[0..n-1] if cnt_i != n, leading to reading uninitialized data here.]

    
    for(i=0;i<k;i++)
    {
        cnt=1;
        for(j=0;j<n;j++)
        {
            if(flag==1)
            {
                j=0; // @@ [Resetting j to 0 inside the loop causes infinite loop or incorrect traversal. When flag==1, j is set to 0, then the loop increments j to 1, but if another match is found, it resets again. This leads to unpredictable behavior and likely infinite looping or missing segments. Also, 'flag' is used without being initialized at the start of the outer loop.]
                flag=0;
            }
            if(L[i].x2==arr[j][0]&&L[i].y2==arr[j][1])
            {
                L[i].x2=arr[j][2];
                L[i].y2=arr[j][3];
                flag=1;
                cnt++;
            }
        }
        if(cnt>=max)
        {
            max=cnt;
            max_k=i;
        }
    }
    
    printf("%d ",max);
    printf("%d %d",L[max_k].x1,L[max_k].y1); // @@ [If no valid chain is found (e.g., max_k remains -1), this accesses L[-1], causing undefined behavior. Also, if k==0 (no starting segments found), L is empty and max_k=-1 leads to crash.]
    return 0;
}