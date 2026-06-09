#include <stdio.h>
struct line{
	int startx;
	int starty;
	int endx;
	int endy;
	struct line *next;
}l[101];
int main()
{
	int i,j,n,sign[105]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&l[i].startx,&l[i].starty,&l[i].endx ,&l[i].endy);
		l[i].next=NULL;
		for(j=i-1;j>=0;j--)
		{
			if(l[i].startx ==l[j].endx &&l[i].starty ==l[j].endy )//i的起点是j的终点 
			{
				l[j].next =&l[i];
				sign[j]=1;
				sign[i]=0; 
			}
			else if(l[i].endx ==l[j].startx &&l[i].endy ==l[j].starty )//j的起点是i的终点 
			{
				l[i].next =&l[j];
				sign[i]=1;
				sign[j]=0;
			}
		}
	}
	struct line *p;
	for(i=0;i<n;i++)
	{
		p=&l[i];
		while(p->next !=NULL)
		{
			p=p->next;
			sign[i]++;
		}
//		printf("%d ",sign[i]);
	}
	int max=sign[0];
	for(i=0,j=0;i<n;i++)
	{
		if(sign[i]>max)
		{
			max=sign[i];
			j=i;
		}
	}
	printf("%d %d %d",max,l[j].startx,l[j].starty);
	return 0;
}

