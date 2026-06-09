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
        for(j=i;j<n-1;j++) // @@ The inner loop logic is incorrect. It only checks if segment i connects to segment j+1 directly, but fails to propagate the chain length correctly or check all possible successors in the sorted array properly for a DP-like accumulation. Specifically, with sorting by startx descending, we should check if loc[j].end matches loc[i].start. The current nested loop structure `for(j=i...` checking `loc[j+1]` against `loc[i]` is flawed because it doesn't accumulate counts from intermediate segments correctly if the chain is longer than 2, or if the matching segment isn't immediately at `j+1` relative to `i` in a way that respects the transitive property. More critically, the condition `loc[i].startx == loc[j+1].lastx` checks if segment `i` starts where segment `j+1` ends. Since sorted by startx descending, `loc[i]` has larger/equal startx. If `loc[i]` starts where `loc[j+1]` ends, then `loc[j+1]` comes before `loc[i]` in the geometric chain (left to right), but in our sorted array (right to left), `loc[i]` is "earlier" in the array index if it's further right. Wait, if sorted by startx descending, the rightmost segment is at index 0. If segment A is to the right of segment B, A.startx > B.startx. So A appears before B in the array. If A connects to B, A.end == B.start. We want to add B's count to A's count? No, we want the total length. If we process from right to left (index 0 to n-1), and we find a segment `k` such that `loc[k].start` matches `loc[current].end`, we can add `loc[k].num` to `loc[current].num`. The current code checks `loc[i].start` against `loc[j+1].last`. This implies looking for a segment `j+1` that ends where `i` starts. This means `j+1` is to the left of `i`. In the sorted array (descending startx), segments to the left have smaller startx, so they appear later in the array (higher index). So `j+1 > i` is likely. But the loop `j=i` to `n-2` checks `j+1`. This part might technically iterate through candidates. However, the critical error is that `loc[i].num += loc[j+1].num` assumes `loc[j+1].num` is already fully calculated including its own successors. Since `i` goes from 0 to n-1, and `j+1` > `i`, `loc[j+1]` (which is further left in geometry, higher index in array) has NOT been processed yet if we are accumulating from right to left. Actually, if we sort descending, index 0 is rightmost. A chain goes Right -> Left. So Index 0 -> Index K. We should process from High Index (Leftmost) to Low Index (Rightmost)? No, if we want to accumulate counts, we should process from the end of the chain backwards. The end of the chain is the leftmost segment (smallest startx). In descending sort, this is the last element. So we should iterate `i` from `n-1` down to `0`. Inside, look for `j` such that `loc[j].start == loc[i].end`. Since `loc[j]` is to the right of `loc[i]`, `loc[j].startx > loc[i].startx`, so `j < i`. If we iterate `i` from `n-1` downwards, then when we are at `i`, any `j < i` has already been processed? No, `j` is to the right, so `j` has smaller index. If we go `n-1` down to `0`, we process left to right geometrically. When we are at `i` (left), we look for `j` (right, `j<i`). `j` has already been processed? Yes, if we go downwards. So `loc[j].num` is complete. Then `loc[i].num += loc[j].num`. The current code goes `i` from `0` to `n-1`. This processes Right to Left geometrically. When at `i` (Right), it looks for `j+1` (Left, `j+1 > i`). `loc[j+1]` has not been fully processed yet in this forward loop if it depends on even further left segments. Thus, the DP order is wrong.]
        {
            if(loc[i].startx ==loc[j+1].lastx &&loc[i].starty ==loc[j+1].lasty )
            {
                loc[i].num +=loc[j+1].num;
             } 
        }
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
     printf("%d %d %d",max,loc[flag].startx ,loc[flag].starty ); 
    return 0;
 }