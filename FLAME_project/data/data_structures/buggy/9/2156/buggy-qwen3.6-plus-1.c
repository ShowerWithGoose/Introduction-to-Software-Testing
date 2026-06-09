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
        for(j=i-1;gather[j].endx>=gather[i].satx;j--) // @@ The loop condition `gather[j].endx>=gather[i].satx` is incorrect for stopping the search. Since the array is sorted by start x (`satx`), `gather[j].satx` decreases as `j` decreases. However, `gather[j].endx` is not necessarily sorted. More importantly, we only want to connect if `gather[j]` ends exactly where `gather[i]` starts. The current loop continues as long as the end of j is greater than or equal to start of i. This might skip valid predecessors if their endx is small but still matches, or include invalid ones. But the critical logical error is that it doesn't stop when `gather[j].endx < gather[i].satx` is false in a way that guarantees we found all matches? Actually, since `satx` is sorted, if `gather[j].endx < gather[i].satx`, it's possible that `gather[j-1].endx` is even smaller or larger. There is no monotonic property on `endx`. So this optimization is invalid. We must check all `j < i`.
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