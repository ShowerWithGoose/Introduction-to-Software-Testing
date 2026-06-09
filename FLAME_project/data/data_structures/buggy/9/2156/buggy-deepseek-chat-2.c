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
        for(j=i-1;gather[j].endx>=gather[i].satx;j--) // @@ [Error: The loop condition uses `gather[j].endx >= gather[i].satx` but does not check if `j` goes out of bounds (j < 0). When j becomes -1, accessing gather[-1] causes undefined behavior. Additionally, the condition should ensure that only segments with matching endpoints are considered, but the loop may skip valid connections because it stops too early or accesses invalid indices.]
        {
            
            if(gather[i].satx==gather[j].endx&&gather[i].saty==gather[j].endy)
            {
            gather[j].link +=gather[i].link ; // @@ [Error: This adds the link count of the later segment to the earlier one, but it does not account for the fact that multiple segments might connect to the same earlier segment. Since only one continuous line segment contains the maximum number of segments, this approach may incorrectly accumulate counts from different branches, leading to an overcount or wrong starting point.]
                
            }
            
        }
    }
    for(j=0;j<all;j++)
    {
        if(gather[j].link>max)max=gather[j].link,maxnum=j;
    }
    printf("%d %d %d",gather[maxnum].link,gather[maxnum].satx,gather[maxnum].saty);
}