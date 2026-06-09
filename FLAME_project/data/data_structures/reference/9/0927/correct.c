#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct seg			
{
    int beginx;
    int beginy;
    int endx;
    int endy;
    int num;			
}seg[132];



int cmpfuc(const void *a, const void *b)		
{												
    struct seg *c = (seg *)a;						
    struct seg *d = (seg *)b;
    if(c->beginx!=d->beginx) return d->beginx - c->beginx;
    else return d->beginy - c->beginy;
}
int main()
{
    struct seg seg[132];
    int n;
    scanf("%d",&n);									
    int i,j;
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d",&seg[i].beginx,&seg[i].beginy,&seg[i].endx,&seg[i].endy),seg[i].num = 1;

    qsort(seg,n,sizeof(seg[0]),cmpfuc);				


    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)				
        {										
            if(seg[i].beginx==seg[j+1].endx && seg[i].beginy == seg[j+1].endy)
            {
                seg[j+1].num += seg[i].num;
            }
        }
    }
    int max = -1; int flag = 0;
    for(i = 0; i < n; i++)
    {
        if(seg[i].num > max)
            max = seg[i].num,flag = i;			
    }
    printf("%d %d %d",max,seg[flag].beginx,seg[flag].beginy);		
    return 0;
}


