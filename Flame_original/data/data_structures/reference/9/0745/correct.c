#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
struct location{
	int lx;
	int ly;
	int rx;
	int ry;
	int num;
	
}line[101];
int n,i,j,k;
int cmp(const void*a,const void*b);
int cmp2(const void*a,const void*b);
void search()
{
	for(i=0;i<n;i++)
	{	
		///printf("%d %d %d %d\n",line[i].lx,line[i].ly,line[i].rx,line[i].ry);
		line[i].num=1;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if((line[i].rx==line[j].lx)&&(line[i].ry==line[j].ly))
				{
					line[i].rx=line[j].rx;
					line[i].ry=line[j].ry;
					line[i].num++;
				}
			}
		}
	}
}
int main()
{
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].lx,&line[i].ly,&line[i].rx,&line[i].ry);
	}
	qsort(line,n,sizeof(line[0]),cmp);
	search();
	qsort(line,n,sizeof(line[0]),cmp2);
	printf("%d %d %d",line[0].num,line[0].lx,line[0].ly);
	return 0;
}

int cmp(const void*a,const void*b)
{
	struct location*p=(struct location*)a;
	struct location*q=(struct location*)b;	
	if(q->lx!=p->lx)
		return p->lx-q->lx;
	else
	    return p->ly-q->ry;
}
int cmp2(const void*a,const void*b)
{
	struct location*p=(struct location*)a;
	struct location*q=(struct location*)b;	
	
		return q->num>p->num?1:-1;

}

