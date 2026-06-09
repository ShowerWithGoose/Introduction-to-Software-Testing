#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
struct num{
	int coe;
	int pow;
};
typedef struct num ex;
ex a[3000],b[3000],c[3000];
int cmp(void *p1,void *p2);
int main()
{
	int i,j,k,n;
	for(i=0;;i++)
	{
		scanf("%d%d",&a[i].coe,&a[i].pow);
		if(getchar()=='\n')
		break;
	}
	int len1;
	len1=i+1;
	for(i=0;;i++)
	{
		scanf("%d%d",&b[i].coe,&b[i].pow);
		if(getchar()=='\n')
		break;
	}
	int len2;
	len2=i+1;
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;
			c[k].pow=a[i].pow+b[j].pow;
			k++;
		}
	}
	qsort(c,k,sizeof(ex),cmp);
	for(i=0;i<k;i++)
	{
		if(c[i].pow==c[i+1].pow&&c[i].pow!=0)
		{
			c[i+1].coe+=c[i].coe;
			c[i].coe=0;
		}
	}
	qsort(c,k,sizeof(ex),cmp);
	for(i=0;i<k;i++)
	{
		if(c[i].coe==0)
			continue;
		else printf("%d %d ",c[i].coe,c[i].pow);
	}
	return 0;
}
int cmp(void *p1,void *p2)
{
	struct num *a=(struct expression*)p1;
	struct num *b=(struct expression*)p2;
	return b->pow-a->pow; 
}

