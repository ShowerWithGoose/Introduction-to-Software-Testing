#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct cole 
{
	int cint,kin;
} 
a[100],b[100],c[1000];
int cmp(const void *p, const void *q) 
{
	struct cole *x=(struct cole *)p;
	struct cole *y=(struct cole *)q;
	return y->kin-x->kin;
}
char code=' ';
int main() 
{
	int i=0,j,k=0,count,count1;
	while(code!='\n') 
	{
		scanf("%d%d%c",&a[i].cint,&a[i].kin,&code);
		i++;
		count=i;
	}
	i=0;
	code=' ';
	while(code!='\n') 
	{
		scanf("%d%d%c",&b[i].cint,&b[i].kin,&code);
		i++;
		count1=i;
	}
	for(i=0;i<count;i++) 
	{
		for(j=0;j<count1;j++) 
		{
			c[k].cint=a[i].cint*b[j].cint;
			c[k].kin=a[i].kin+b[j].kin;
			k++;
		}
	}
	qsort(c,k,sizeof(c[0]),cmp);
	for(i=0;i<k-1;i++) 
	{
		for(j=i+1;j<k;j++) 
		{
			if(c[i].kin==c[j].kin) 
			{
				c[i].cint+=c[j].cint;
				c[j].cint=0;
			}
		}
	}
	for(i=0;i<k;i++) 
	{
		if(c[i].cint!=0) 
		{
			printf("%d %d ",c[i].cint,c[i].kin);
		}
	}
	return 0;
}

