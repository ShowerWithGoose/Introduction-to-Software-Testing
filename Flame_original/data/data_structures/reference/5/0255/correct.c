#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2);
typedef struct formula{
	int coe;
	int pow;
} fo,*pfo;
fo a[1000],b[1000],re[1000];
int main()
{
	int i,j,k=0,cnta=0,cntb=0;
	char temp;
	do 
	{
		scanf("%d %d%c",&a[cnta].coe,&a[cnta].pow,&temp);
		cnta++;
	}while (temp != '\n');
	do 
	{
		scanf("%d %d%c",&b[cntb].coe,&b[cntb].pow,&temp);
		cntb++;
	}while (temp != '\n');
	for (i=0;i<cnta;i++)
	{
		for (j=0;j<cntb;j++)
		{
			re[k].coe=a[i].coe*b[j].coe;
			re[k++].pow=a[i].pow+b[j].pow;
		}
	}
	qsort(re,k,sizeof(re[0]),cmp);
	for (i=0;i<k;i++)
	{
		if (re[i].pow ==-1)
			continue;
		for (j=i+1;j<k;j++)
		{
			if (re[j].pow==re[i].pow)
			{
				re[i].coe+=re[j].coe;
				re[j].pow=-1;
			}
		}
	}
	for (i=0;i<k;i++)
	{
		if (re[i].pow != -1)
		 printf("%d %d ",re[i].coe,re[i].pow);
	}
	return 0;
}
int cmp(const void *p1,const void *p2)
{
	pfo a =(pfo) p1;
	pfo b =(pfo) p2;
	return (b->pow)-(a->pow);
}

