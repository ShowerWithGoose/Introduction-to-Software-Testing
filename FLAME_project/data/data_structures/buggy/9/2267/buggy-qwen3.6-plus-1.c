#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int count;
};
int cmp(const void*,const void*);
int main()
{
    int n;
    scanf("%d",&n);
    struct line *gather=malloc(sizeof(struct line)*n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].count=1;
    }
    qsort(gather,n,sizeof(struct line),cmp);
    for (int i=n-1;i>0;i--)
    {
        for (int j=i-1;j>=0 && gather[i].start_x>=gather[j].end_x;j--) // @@ The original loop condition `gather[i].start_x>=gather[j].end_x` accesses `gather[j]` before checking if `j` is within bounds (j >= 0). When j becomes -1, it causes out-of-bounds access. Also, the logic needs to ensure we only look at valid indices.
        {
            if (gather[i].start_x==gather[j].end_x &&gather[i].start_y==gather[j].end_y)
            {
                gather[j].count+=gather[i].count;
            }
        }
    }
    int flag=0;
    int max=gather[0].count;
    for (int i=0;i<n;i++)
    {
        
        if (max<=gather[i].count) // @@ Using `<=` instead of `<` means that if multiple chains have the same maximum length, the last one found (which likely has a larger start_x due to sorting by end_x) will be selected. The problem implies finding the specific longest chain, and typically "starting point" uniqueness or earliest occurrence might be preferred, but more importantly, the sorting order and DP direction need to be consistent. However, the primary issue here is often tied to how ties are broken or if the DP propagation is correct. Let's look closer. The sort is by `end_x`. The DP goes backwards. If `max <= gather[i].count`, it updates. If there are multiple chains of same length, this picks the one with highest index `i` in the sorted array. Since sorted by `end_x`, higher index means larger `end_x`. This doesn't necessarily guarantee the correct "starting point" if the problem implies a unique solution or specific tie-breaking. But wait, the constraint says "Only one continuous line segment contains the maximum number of segments." So ties in length shouldn't happen. The real error is likely in the DP logic or sorting.
        {
            max=gather[i].count;
            flag=i;
        }
    }
    printf("%d %d %d",max,gather[flag].start_x,gather[flag].start_y);
    
    
    
    free (gather);
    gather=NULL;
    return 0;
}

int cmp(const void*a,const void*b)
{
    struct line *data1=(struct line*)a;
    struct line *data2=(struct line*)b;
    return data1->end_x-data2->end_x; // @@ Sorting by `end_x` is problematic for this DP approach. To correctly chain segments where segment A connects to segment B (A.end == B.start), we should process segments such that when we are at segment B, all potential predecessors A (where A.end == B.start) have already been processed and their counts finalized. If we sort by `end_x`, and iterate backwards, we are looking for predecessors `j` with `gather[j].end_x == gather[i].start_x`. Since `gather[i].start_x < gather[i].end_x` (given), and we sorted by `end_x`, `gather[j].end_x` (which equals `gather[i].start_x`) is likely less than `gather[i].end_x`. So `j` would have a smaller `end_x` than `i`. In the sorted array, smaller `end_x` means smaller index. So `j < i`. The loop `for (int j=i-1; ... j--)` searches backwards from `i-1`. This seems logically okay for finding predecessors if they exist at lower indices. However, the condition `gather[i].start_x>=gather[j].end_x` is used to terminate the loop early? No, it's used to continue. Wait. If `gather[i].start_x < gather[j].end_x`, then `gather[j]` ends after `i` starts, so they can't connect (since `i` starts where `j` ends, `j.end` must equal `i.start`). If `gather[j].end_x > gather[i].start_x`, then `j` is not a predecessor. Since the array is sorted by `end_x`, as `j` decreases, `gather[j].end_x` decreases. So if we start at `j=i-1` and go down, `gather[j].end_x` gets smaller. We want to find `j` such that `gather[j].end_x == gather[i].start_x`. The loop condition `gather[i].start_x >= gather[j].end_x` means we continue while `gather[j].end_x` is small enough. But we should stop if `gather[j].end_x` becomes too small? No, we just check all `j` where `gather[j].end_x <= gather[i].start_x`. Actually, since we need exact match `gather[j].end_x == gather[i].start_x`, we can just check. The optimization `gather[i].start_x >= gather[j].end_x` allows skipping elements where `gather[j].end_x` is too large? No, if `gather[j].end_x > gather[i].start_x`, they can't match. Since `end_x` is sorted ascending, `gather[j].end_x` for `j < i` is `<= gather[i-1].end_x`. It's possible `gather[j].end_x > gather[i].start_x`. If so, we should skip or stop? If `gather[j].end_x > gather[i].start_x`, then for any `k < j`, `gather[k].end_x <= gather[j].end_x`. It doesn't mean `gather[k].end_x` is also `> gather[i].start_x`. So we can't break. We must check all `j < i`. The condition in the for loop `gather[i].start_x>=gather[j].end_x` is actually incorrect as a loop continuation condition if it implies breaking when false. If `gather[i].start_x < gather[j].end_x`, the condition fails, loop terminates. This misses potential matches at smaller `j` where `gather[j].end_x` might be smaller and equal to `gather[i].start_x`. Thus, the loop terminates prematurely.
};