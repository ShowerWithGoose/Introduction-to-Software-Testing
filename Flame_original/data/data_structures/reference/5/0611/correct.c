#include<stdio.h>

#include<stdlib.h>
#include<ctype.h>
typedef struct NUM{
  int xi;
  int zh;
}xiang;

xiang a[3000],b[3000],c[3000];
int rank(xiang*p1,xiang*p2)
{
    return p2->zh-p1->zh;
}
int main()
{
	int i,j,k=0;
	int x1=0,x2=0;
	char ch;
	do
	{
		scanf("%d%d%c",&a[x1].xi,&a[x1].zh,&ch);
		x1++;
	}while(ch!='\n');
	do
	{
		scanf("%d%d%c",&b[x2].xi,&b[x2].zh,&ch);
		x2++;
	}while(ch!='\n');
	qsort(a,x1,sizeof(xiang),rank);
	qsort(b,x2,sizeof(xiang),rank);
	for(i=0;i<x1;i++)
	{
		for(j=0;j<x2;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zh=a[i].zh+b[j].zh;
			k++;
		}
	}
	qsort(c,k,sizeof(xiang),rank);
	for(i=0;i<k;i++)
	{
		if(c[i].zh == c[i+1].zh && c[i].zh!=0)
		{
			c[i+1].xi+=c[i].xi;
			c[i].xi=0;
		}
	}
	qsort(c,k,sizeof(xiang),rank);
	for(i=0;i<k;i++)
	{
		if(c[i].xi==0)
		{
			continue;
		}
		else
		{
			printf("%d %d ",c[i].xi,c[i].zh);
		}
	}
	return 0;
}

