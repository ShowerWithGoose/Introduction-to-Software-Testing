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
        for(j=i-1;gather[j].endx>=gather[i].satx;j--) // @@ The loop condition `gather[j].endx >= gather[i].satx` is incorrect for stopping the search. Since the array is sorted by `satx`, we should stop when `gather[j].endx < gather[i].satx` is false? No, we want to find matches where `gather[j].endx == gather[i].satx`. Because `satx` is sorted, `gather[j].satx <= gather[i].satx`. However, `endx` is not sorted. The optimization of breaking early based on `endx` is flawed because `endx` values are arbitrary relative to the sort order of `satx`. More importantly, the loop goes backwards from `i-1`. It should check all `j < i` that could connect. The condition `gather[j].endx >= gather[i].satx` might skip valid candidates if `endx` is small but `satx` matches? No, the match requires `gather[j].endx == gather[i].satx`. If `gather[j].endx < gather[i].satx`, it can't match. So stopping when `endx < satx` is logically sound for *finding* matches IF the list was sorted by `endx` or if we were iterating in a way that `endx` was decreasing. But here `j` decreases, and `satx` decreases (or stays same). `endx` has no monotonic property with respect to `j`. Therefore, we cannot break early based on `endx`. We must check all `j < i`.
        {
            
            if(gather[i].satx==gather[j].endx&&gather[i].saty==gather[j].endy)
            {
            gather[j].link +=gather[i].link ;
                
            }
            
        }
    }
    for(j=0;j<all;j++)
    {
        if(gather[j].link>max)max=gather[j].link,maxnum=j;
    }
    printf("%d %d %d",gather[maxnum].link,gather[maxnum].satx,gather[maxnum].saty);
}