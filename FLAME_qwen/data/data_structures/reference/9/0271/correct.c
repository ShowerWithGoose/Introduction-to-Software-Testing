#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct Lines{
	int p11;
	int p12;
	int p21;
	int p22;
	int num;
}line[100];
int Cmp(const void *a,const void *b)
{
	struct Lines *c=(struct Lines *)a;
	struct Lines *d=(struct Lines *)b;
	if(c->p11==d->p11) return (c->p12-d->p12);
	return (c->p11-d->p11);
}
int cmp(const void *a,const void *b)
{
	struct Lines *c=(struct Lines *)a;
	struct Lines *d=(struct Lines *)b;
	return(c->num-d->num);
}
int a[200];
int n=0;
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("\n%d %d %d %d",&line[i].p11,&line[i].p12,&line[i].p21,&line[i].p22);	
	qsort(line,n,sizeof(line[0]),Cmp);//将线段的左端点排序 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j||(line[j].p21==0&&line[j].p22==0))
			{
				continue;
			}
			else
			{
				if(line[i].p21==line[j].p11&&line[i].p22==line[j].p12)
				{
					line[i].p21=line[j].p21;
					line[i].p22=line[j].p22;
					line[j].p11=0,line[j].p12=0,line[j].p21=0,line[j].p22=0;
					line[i].num++;	
				}
			}
		}
	}
	qsort(line,n,sizeof(line[0]),cmp);
	printf("%d %d %d\n",line[n-1].num+1,line[n-1].p11,line[n-1].p12);
	return 0;
}

