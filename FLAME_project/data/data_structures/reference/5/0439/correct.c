#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct expression{			 
	int coe;				
	int pow;
	int num;				
}ex;
ex a[2000],b[2000],c[2000];

int cmp(const void*p1,const void*p2)
{
	struct expression *a=(struct expression*)p1;
	struct expression *b=(struct expression*)p2;
	return b->pow-a->pow;
}

int main()
{	
	int i,j,k=0;
	int n=0,m=0;
	char ch;
	do
	{
		scanf("%d%d%c",&a[n].coe,&a[n].pow,&ch);
		n++;
	}while(ch!='\n');
	do
	{
		scanf("%d%d%c",&b[m].coe,&b[m].pow,&ch);
		m++;
	}while(ch!='\n');
	qsort(a,n,sizeof(ex),cmp);
	qsort(b,m,sizeof(ex),cmp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;
			c[k].pow=a[i].pow+b[j].pow; 
			k++;
		}
	}
	qsort(c,k,sizeof(ex),cmp);
	for(i=0;i<k;i++)
	{
		if(c[i].pow == c[i+1].pow && c[i].pow!=0)
		{
			c[i+1].coe+=c[i].coe;
			c[i].coe=0;
		}
	}
	qsort(c,k,sizeof(ex),cmp);
	for(i=0;i<k;i++)
	{
		if(c[i].coe==0)
		{
			continue;
		}
		else
		{
			printf("%d %d ",c[i].coe,c[i].pow);
		}
	}
	return 0;
}



