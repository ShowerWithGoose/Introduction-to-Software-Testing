#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct multiple{
	int n;
	int loc;
	int del;
} mul,*pmul;
mul a[100],b[100],c[100];
int Cmp(const void *pa, const void *pb)
{
pmul a =(pmul)pa;
pmul b =(pmul)pb;
if ((a->loc)>(b->loc))
{
return -1;
}
else if ((a->loc)<=(b->loc))
{
return 1;
}
}
int main()
{
	int i,len1,len2,t,m;
	char ch;
	for(i=0; ;i++)
	{
	    scanf("%d ",&a[i].n);
	    scanf("%d",&a[i].loc);
		scanf("%c",&ch);
		if(ch=='\n')
		break; 
	}
	len1=i+1;
	for(i=0; ;i++)
	{
	    scanf("%d ",&b[i].n);
	    scanf("%d",&b[i].loc);
		scanf("%c",&ch);
		if(ch=='\n')
		break; 
	}
	len2=i+1;
	m=0;
	for(i=0;i<len1;i++)
	{
		for(t=0;t<len2;t++)
		{
		    c[m].n=(a[i].n)*(b[t].n);
		    c[m].loc=a[i].loc+b[t].loc;
		    c[m].del=0;
		    m++;
		} 
	}
	qsort(c,m,sizeof(mul),Cmp);
	for(i=0;i<m-1;i++)
	{
		if(c[i].loc==c[i+1].loc)
		{
			c[i+1].n=c[i+1].n+c[i].n;
			c[i].del=1;
		}
	}
	for(i=0;i<m;i++)
	{
		if(c[i].del!=1)
		{
			printf("%d %d ",c[i].n,c[i].loc);
		}
	}
	return 0;
}


