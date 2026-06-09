#include<stdio.h>
struct xy
{
    int x1;
    int y1;
    int x2;
    int y2;
};
int cmp(const void *aa,const void *bb)
{
    if((*(struct xy*)aa).x1>(*(struct xy*)bb).x1)
    {
        return 1;
    }
    else if((*(struct xy*)aa).x1<(*(struct xy*)bb).x1)
    {
        return -1;
    }
    return 0;
}
int main()
{
    int n,max=0,num[101]={};
    int x=0,y=0;
    scanf("%d",&n);
    struct xy wz[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&wz[i].x1,&wz[i].y1,&wz[i].x2,&wz[i].y2);
    }
    qsort(wz,n,sizeof(struct xy),cmp);
    for(int i=n-1;i>0;i--) // @@ The loop condition `i>0` skips the segment at index 0. If the longest chain starts with the first segment (index 0) in the sorted array, its length contribution is never calculated or propagated correctly to predecessors (though there are none here, the initialization of max might fail if the chain ends at 0). More critically, the inner loop logic is flawed.
    {
        for(int j=n-1;j>0&&j!=i;j--) // @@ The search for a successor `j` such that `i` connects to `j` (`i.end == j.start`) should look for `j` where `j.x1 > i.x1`. Since the array is sorted by `x1`, successors of `i` will have indices greater than `i`. However, this loop iterates backwards from `n-1`. The condition `j!=i` is good. But `num[i] = num[j] + 1` assumes `j` is already computed. Since we iterate `i` downwards, `j` (which is likely > `i` if it's a successor in x-coordinate order? No, wait. If `i` connects to `j`, then `i.x2 == j.x1`. Since `x1 < x2` for each segment, and segments are sorted by `x1`, generally `j` will have a larger index than `i` if `j` starts where `i` ends. So iterating `i` from `n-1` down to 0 is correct for DP because `num[j]` would have been computed already if `j > i`. BUT, the inner loop range `j>0` excludes `j=0`. If the successor is at index 0, it won't be found. Also, `max` and `x,y` are only updated inside the `if` connection block. If a segment has no successor, its chain length is 1 (implicit). But `max` is initialized to 0. If the longest chain is length 1, `max` remains 0, and `x,y` remain 0,0. This causes the Wrong Answer for single segments or when the best segment doesn't connect to anything further but is the start of a chain of length 1? No, `num[i]` is 0 by default. `num[i] = num[j]+1`. If `i` connects to `j`, length is `num[j]+1`. If `i` doesn't connect, `num[i]` stays 0. The final print is `max+1`. If no connections are found, `max` is 0, output is 1. This part is logically okay for length calculation IF `x,y` are tracked correctly. The problem is `x,y` are only updated when a connection is found. If the longest chain is just 1 segment, `max` stays 0, `x,y` stay 0,0. This explains the output `1 0 0`. We need to initialize `max` to 0 (representing length 1 effectively via `max+1`?) No, if max=0, length=1. But `x,y` must be set to the start of that segment. Currently `x,y` are only set inside the `if`.
        {
            if(wz[i].x2==wz[j].x1&&wz[i].y2==wz[j].y1)
            {
                num[i]=num[j]+1;
                if(num[i]>max)
                {
                    max=num[i];
                    x=wz[i].x1;
                    y=wz[i].y1;
                }
            }
        } 
    }
    
    printf("%d %d %d",max+1,x,y);
    return 0;
}