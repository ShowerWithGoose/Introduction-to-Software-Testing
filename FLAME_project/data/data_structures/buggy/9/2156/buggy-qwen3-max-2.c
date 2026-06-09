#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct l
{
    int satx,saty,endx,endy,link;
}line;
int cmp(void *p1,void *p2)
{
    line *i1=(line*)p1,*i2=(line*)p2;
    return i1->satx -i2->satx;
}
int main()
{
    int all,i,j=0,max=0,maxnum=0;
    scanf("%d",&all);
    line* gather;
    gather=(line*)malloc(sizeof(line)*all);
    for(i=0;i<all;i++)
    {
        scanf("%d%d%d%d",&gather[i].satx,
        &gather[i].saty,
        &gather[i].endx,
        &gather[i].endy);
        gather[i].link =1;
    }

    qsort(gather,all,sizeof(line),cmp);

    for(i=all-1;i>0;i--)
    {
        for(j=i-1;gather[j].endx>=gather[i].satx;j--) // @@ [The inner loop condition `gather[j].endx >= gather[i].satx` is incorrect. It assumes segments are sorted by start x and tries to find predecessors, but this condition may skip valid connections where a segment ends exactly at the start of another even if other segments have larger end x. More critically, it does not ensure we only check segments that actually connect (same endpoint), and the loop may access `gather[-1]` when j becomes negative, causing undefined behavior. Also, the logic only propagates link counts forward in a single pass from right to left, which fails to handle chains longer than 2 segments properly because it doesn't consider that a segment might be extended by multiple successors or that the best chain ending at a point should be computed correctly.]
        {
            
            if(gather[i].satx==gather[j].endx&&gather[i].saty==gather[j].endy)
            {
            gather[j].link +=gather[i].link ; // @@ [This updates the predecessor's link count by adding the current segment's link count, but if a segment can connect to multiple successors (which shouldn't happen per constraints, but more importantly, if multiple predecessors connect to the same successor), this approach fails. However, the bigger issue is that the algorithm processes segments from high index to low, but due to sorting by `satx`, a segment with smaller `satx` comes first, so when processing backwards, we may update a predecessor before considering all its possible extensions. In particular, if a chain is A->B->C->D, when processing D, then C gets updated; when processing C (now with link=2), B gets updated to 3; but if there's another path to C, it might not be considered. However, the main flaw is that the inner loop starts at `i-1` and goes downward, but after sorting by `satx`, segments that end at `gather[i].satx` might appear anywhere before `i`, not necessarily contiguous, and the loop breaks too early due to the `gather[j].endx >= gather[i].satx` condition, missing potential connections. For example, a segment with very small `endx` might still connect if its endpoint matches, but the loop stops when `gather[j].endx < gather[i].satx`, skipping it even if coordinates match by y. But since x must match exactly for connection, and `satx` of current is fixed, only segments with `endx == gather[i].satx` can connect, so the condition should be `j >= 0` and check equality, not use `>=` as a bound. This causes missed connections and undercounting.]
                
            }
            
        }
    }
    for(j=0;j<all;j++)
    {
        if(gather[j].link>max)max=gather[j].link,maxnum=j;
    }
    printf("%d %d %d",gather[maxnum].link,gather[maxnum].satx,gather[maxnum].saty);
}