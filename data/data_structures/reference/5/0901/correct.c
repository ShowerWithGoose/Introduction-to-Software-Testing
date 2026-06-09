#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct xiang
{
    int xishu;
    int zhishu;				
}line1[10000],line2[10000],line3[10000];

int cmp(const void *a, const void *b)			
{												
    struct xiang*c=(struct xiang*)a;
    struct xiang*d = (struct xiang*)b;
    return d->zhishu- c->zhishu;
}

int main()
{
	char c=' ';
	int x=0;
	while(c!='\n') 
	{
        scanf("%d%d%c",&line1[x].xishu,&line1[x].zhishu,&c); x++;	
	}
	c=' ';
	int y=0;
	while(c!='\n') 
	{
        scanf("%d%d%c",&line2[y].xishu,&line2[y].zhishu,&c); y++;	
	}
	int p=0;
	for(int i=0;i<x;i++)
	{
		for(int ii=0;ii<y;ii++)
		{
			line3[p].xishu=line1[i].xishu*line2[ii].xishu;
			line3[p].zhishu=line1[i].zhishu+line2[ii].zhishu;
			p++;
		}
	}
	qsort(line3,p,sizeof(line3[0]),cmp);
	for(int i=0;i<p;i++)
	{
		if(line3[i].zhishu==line3[i+1].zhishu&&line3[i].zhishu!=0) 
		{
			    line3[i+1].xishu+=line3[i].xishu;
			    line3[i].xishu=0;	
		}
	}
	for(int i=0;i<p;i++)
	{
		if(line3[i].xishu!=0)
		printf("%d %d ",line3[i].xishu,line3[i].zhishu);
	}
    return 0;
}



