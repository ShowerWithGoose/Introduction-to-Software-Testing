#include<stdio.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int cmp(const void *p1,const void *p2)
{
	struct line *a=(struct line*)p1;
	struct line *b=(struct line*)p2;
	if(a->x1<=b->x1)return -1;
	else return 1;
}
int main()
{
	struct line table[100];
	int startx,starty,curx,cury;
	int curlen,maxlen=0;
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&table[i].x1,&table[i].y1,&table[i].x2,&table[i].y2);
	}
	qsort(table,n,sizeof(struct line),cmp);
	for(i=0;i<n;i++)
	{
		curlen=1;
		curx=table[i].x2;
		cury=table[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(table[j].x1==curx&&table[j].y1==cury)
			{
				curlen++;
				curx=table[j].x2;
				cury=table[j].y2;
			}
		}
		if(curlen>maxlen)
		{
			maxlen=curlen;
			startx=table[i].x1;
			starty=table[i].y1;
		}
	}
	printf("%d %d %d",maxlen,startx,starty);
	return 0;
}

