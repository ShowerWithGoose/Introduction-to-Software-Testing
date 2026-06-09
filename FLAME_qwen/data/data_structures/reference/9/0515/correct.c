#include<stdio.h>
typedef struct line{
		int x1;
		int y1;
		int x2;
		int y2;
		struct line *link;
	} line;
line data[100],*m,*p;
int main()
{
	int i,j,k,n,max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
		if(i!=0)
		{
			for(j=0;j<i+1;j++)
			{
				for(k=0;k<i+1;k++)
				{
					if(data[j].x2==data[k].x1&&data[j].y2==data[k].y1)
					{
						data[j].link=&data[k];
					}
				}
			}
		}
	}
	for(i=0,max=0;i<n;i++)
	{
		j=1;
		p=&data[i];
		while(p->link!=NULL)
		{
			p=p->link;
			j++;
		}
		if(j>max)
		{
			max=j;
			m=&data[i];
		}
	}
	printf("%d %d %d",max,m->x1,m->y1);
	return 0;
}

