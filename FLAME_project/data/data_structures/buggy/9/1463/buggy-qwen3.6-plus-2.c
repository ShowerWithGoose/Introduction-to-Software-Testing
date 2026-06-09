#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct location
{
    int startx;
    int starty;
    int lastx;
    int lasty;
    int num;
 } loca;//定义一个类型 struct location，叫loca 
 loca loc[10000];
 


int cmpfuc(const void *a, const void *b)        
{                                                    
    loca *c = (loca *)a;                        
    loca *d = (loca *)b;
    if(c->startx!=d->startx) return d->startx - c->startx;
    else return d->starty - c->starty;
}
 
 
int main()
{
    int i,j;
    loca loc[10000];
    int n;
    scanf("%d",&n);
    i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&loc[i].startx ,&loc[i].starty ,&loc[i].lastx ,&loc[i].lasty );
        loc[i].num =1;
    }
    qsort(loc,n,sizeof(loc[0]),cmpfuc);//快排，按起始点从大往小排 
    
    for(i=0;i<n-1;i++)//计算所有线段的长度 
    {
        for(j=i;j<n-1;j++) // @@ The inner loop logic is incorrect. It checks if loc[i] connects to loc[j+1], but since the array is sorted by start coordinates in descending order, a segment starting at loc[i] can only connect to a segment ending at loc[i]'s start if that segment appears later in the sorted list (having a smaller start coordinate). However, the condition `loc[i].startx == loc[j+1].lastx` checks if the *start* of the current outer loop segment matches the *end* of an inner loop segment. This implies we are looking for a predecessor. But the accumulation `loc[i].num += loc[j+1].num` suggests we are building the chain forward or backward incorrectly. More importantly, this nested loop structure does not correctly propagate the chain length. If A->B->C, and we process A, we might find B. But if we process B later, we find C. The count for A needs to include B's count (which includes C). The current loop doesn't ensure that `loc[j+1].num` is fully calculated before adding it to `loc[i].num`. Additionally, the loop range and condition don't guarantee finding the *immediate* next segment in the chain uniquely or correctly accumulating the total length of the chain starting at `loc[i]`. The standard approach is to sort by start coordinate ascending, then iterate to find chains, or use a map/lookup. Here, sorting descending means `loc[0]` has the largest start X. A chain goes from small X to large X. So `loc[0]` is likely the *end* of a chain, not the start. The code tries to find segments that end where `loc[i]` starts. This builds the chain backwards. But `loc[i].num` is initialized to 1. If `loc[i]` connects to `loc[j+1]`, it adds `loc[j+1].num`. This assumes `loc[j+1]` is the rest of the chain. However, the loop `for(j=i...` scans many segments. It might add multiple disjoint segments if they happen to share the same endpoint (violating constraint 2, but still logically flawed if multiple matches were possible or if the order isn't right). The critical error is that the problem asks for the *starting point* of the continuous line. The continuous line goes from smallest X to largest X. The code sorts by Start X descending. So `loc[flag]` will be the segment with the largest Start X. If this segment is part of a chain, it is likely the *last* segment or near the end. The "starting point" of the whole continuous line is the start of the *first* segment in the chain (smallest X). The code outputs `loc[flag].startx`, which is the start of the segment with the highest X coordinate in the chain (or the segment itself if it's the head of the reverse search). In the test case: Segments: (12,12)-(13,13) and (13,13)-(50,76). Sorted Descending by Start X: 1. (13,13)-(50,76), 2. (12,12)-(13,13). 
        // i=0: loc[0] is (13,13)-(50,76). Inner loop j=0. Check loc[0].start (13,13) == loc[1].last (13,13). Match. loc[0].num += loc[1].num (1+1=2).
        // i=1: loc[1] is (12,12)-(13,13). Inner loop doesn't run (j<1 fails immediately if n=2, j starts at 1, 1<1 false). loc[1].num remains 1.
        // Max num is 2 at flag=0.
        // Output: 2, loc[0].startx (13), loc[0].starty (13).
        // Expected: 2, 12, 12.
        // The error is that `loc[flag]` identifies the segment with the largest starting X in the chain (the "top" of the reverse chain), but the question asks for the coordinates of the *starting point* of the continuous line, which corresponds to the segment with the *smallest* X coordinates (the beginning of the geometric line). The code finds the chain length correctly attached to the "highest" segment, but reports the wrong endpoint. It should report the start of the chain, which is the `start` of the segment with the smallest X in the chain. Since the chain is built backwards in this logic, `loc[flag]` is the end of the geometric line. We need the start.
    }
    int max=-1;
    int flag=0;
    i=0;
    for(i=0;i<n;i++)
    {
        if (loc[i].num >max)
        {
            max=loc[i].num ;
            flag=i;
        }
     }
     printf("%d %d %d",max,loc[flag].startx ,loc[flag].starty ); // @@ This prints the start coordinates of the segment with the largest X (the end of the continuous line), but the problem requires the starting point of the continuous line (the segment with the smallest X). To fix this, one would need to trace back to the beginning of the chain or store the true start point during the chain calculation.
    return 0;
 }