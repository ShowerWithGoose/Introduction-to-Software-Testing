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

    qsort(gather,all,sizeof(line),cmp); // @@ [The comparison function 'cmp' does not match the expected signature for qsort; it should take 'const void*' parameters, not 'void*'. This causes undefined behavior and may lead to incorrect sorting or runtime errors.]

    for(i=all-1;i>0;i--)
    {
        for(j=i-1;gather[j].endx>=gather[i].satx;j--) // @@ [This loop condition may cause out-of-bounds access when j becomes negative. There is no check to ensure j >= 0 before accessing gather[j].]
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