#include <stdio.h>
#include <stdlib.h>
int cop(const void* a1,const void* b1);
struct con
{
	int an;
	int n;
};
struct con *ex,cons1[100],cons2[100],cons3[100];
int main()
{
	ex=&cons1[0];
	int ins3=0,ins=0,k,anex,nex,i,j,co1=0,co2=0;
	for(i=1;i<=100;i++)
	{
		cons3[i-1].an=0;
		cons3[i-1].n=0;
	}
	char cd='\0';
	while(cd!='\n')
	{
		scanf("%d%d%c",&cons1[co1].an,&cons1[co1].n,&cd);
		co1++;
	}
	cd='\0';
	while(cd!='\n')
	{
		scanf("%d%d%c",&cons2[co2].an,&cons2[co2].n,&cd);
		co2++;
	}
	for(i=1;i<=co1;i++)
	{
		for(j=1;j<=co2;j++)
		{
			ins=0;
			anex=cons1[i-1].an*cons2[j-1].an;
			nex=cons1[i-1].n+cons2[j-1].n;
			if(nex==0)
			{
				cons3[0].an=cons3[0].an+anex;
			}
			else
			{
				for(k=1;k<=ins3;k++)
				{
					if(nex==cons3[k].n)
					{
						cons3[k].an=cons3[k].an+anex;
						ins=1;
					}
				}
				if(ins==0)
				{
					ins3++;
					cons3[ins3].an=anex;
					cons3[ins3].n=nex;
				}
			}
			
		}
	}
	qsort(cons3+1,100,sizeof(cons3[0]),cop);
	for(i=1;i<=ins3;i++)
	{
		printf("%d %d ",cons3[i].an,cons3[i].n);
	}
	if(cons3[0].an!=0)
		printf("%d %d",cons3[0].an,cons3[0].n);
	return 0;
}
int cop(const void* a1,const void* b1)
{
	struct con* a=(struct con*) a1;
	struct con* b=(struct con*) b1;
	return (a->n)<(b->n)?1:-1;
}

