#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct Line{
	int amo;
	int x1;
	int y1;
	int x2;
	int y2;
};
typedef struct Line LINE;
int cmp(const void *a,const void *b){
    struct Line *c=(struct Line*)a;
	struct Line *d=(struct Line*)b;
	if(c->x1!=d->x1)
	{
		return c->x1-d->x1;
	}
	else
	{
		return c->y1-d->y2;
	}
}

int main()
{
	int n,i,j;
	int tmp=1;
    LINE line[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	qsort(line,n,sizeof(LINE),cmp);
	for(i=0;i<n;i++)
	{
		line[i].amo=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i!=j)&&(line[j].x1==line[i].x2&&line[j].y1==line[i].y2))
			{
				line[i].x2=line[j].x2;
				line[i].y2=line[j].y2;
				line[i].amo=line[i].amo+line[j].amo;
				line[j].amo=0;
				line[j].x1=0;
				line[j].y1=0;
				line[j].x2=0;
				line[j].y2=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(line[i].amo>tmp)
		{
			tmp=line[i].amo;
		}
	}
	for(i=0;i<n;i++)
	{
		if(line[i].amo==tmp)
		{
			break;
		}
	}
	printf("%d %d %d\n",tmp,line[i].x1,line[i].y1);
    return 0;
}


