#include<stdio.h>
#include<stdlib.h>
struct line{
	int x,y,z,w;
	struct line* p;
}linee[128];
int cmp(const void *a,const void *b){
	struct line *g=a;
	struct line *p=b;
	return (*g).x-(*p).x;
}
int main()
{
	int n,i,j;scanf("%d",&n);
	int much =0,lon;
	struct line *s;
	int start[2]={0};
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&linee[i].x,&linee[i].y,&linee[i].z,&linee[i].w);
	qsort(linee,n,sizeof(linee[0]),cmp);
	for(i=0;i<n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(linee[i].z==linee[j].x&&linee[i].w==linee[j].y)
			{
				linee[i].p=&linee[j];
				break;
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		lon=1;
		s=&linee[i];
		while((*s).p!=NULL)
		{
			s=(*s).p;lon++;
		}
		if(lon>much)
		{
			start[0]=linee[i].x;
			start[1]=linee[i].y;
			much=lon;
		}
	}
	printf("%d %d %d",much,start[0],start[1]);
}

