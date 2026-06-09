#include<stdio.h>
#include<stdlib.h>
typedef struct line{
	
	int beginx;
	int beginy;
	int endx;
	int endy;
	
}LINE;
LINE line_[1000];
int cmp(void const *a,void const *b)
{
	LINE *c=(LINE *)a;
    LINE *d=(LINE *)b;
	if(c->beginx>d->beginx) return 1;
	if(c->beginx==d->beginx&&c->beginy<d->beginy) return 1;
	else return -1;
}
int n;
int op(int begin)
{
	int ji=1;
	int now=begin;
	for(int i=begin+1;i<n;i++)
	{
		 if(line_[i].beginx==line_[now].endx&&line_[i].beginy==line_[now].endy)
		 {
		 	ji++;
		 	now=i;
		 }
	}
	
	return ji;
}
int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line_[i].beginx,&line_[i].beginy,&line_[i].endx,&line_[i].endy);
	}
	qsort(line_,n,sizeof(line_[1]),cmp);
	int max=-1;
	int mark;
	for(int i=0;i<n;i++)
	{
		int d=op(i);
		if(d>max)
		{
			max=d;
			mark=i;
		}
	
		
	}
	printf("%d %d %d",max,line_[mark].beginx,line_[mark].beginy); 
	
	
}

