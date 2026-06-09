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
    }
    
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
    }
    
    for(i=0;i<k;i++)
    {
        cnt=1;
        for(j=0;j<n;j++) // @@ The inner loop iterates through all segments in 'arr' linearly. This fails to correctly chain multiple segments because it doesn't ensure the next segment found is the immediate successor in a sorted sequence, nor does it handle the transitive property of chaining (A->B->C) correctly within a single pass without sorting or recursive/iterative deepening. Specifically, it modifies L[i] in place but scans 'arr' from start to end, potentially picking up disjoint segments or missing the correct order if 'arr' isn't sorted by connectivity.
        {
            if(flag==1)
            {
                j=0; // @@ Resetting j to 0 allows re-scanning, but since 'arr' is not sorted by connectivity or coordinates, this greedy approach without proper ordering or visited tracking can lead to incorrect chains or infinite loops if not carefully managed (though flag logic prevents infinite loop here, it doesn't guarantee the longest valid geometric chain). The primary issue is that the algorithm assumes a simple linear scan can build the chain, but without sorting the segments by their start/end coordinates, the "next" segment found might not be the correct geometric continuation if there are branches or if the input order is arbitrary. However, the specific failure in the test case suggests the chain building logic is flawed.
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
    printf("%d %d",L[max_k].x1,L[max_k].y1);
    return 0;
}