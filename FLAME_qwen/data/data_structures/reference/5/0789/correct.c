#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct book{
	int num1;
	int num2;
};
int cmp(const void *p1,const void *p2);
int main()
{
	struct book a[500],b[500],c[1000];
	char ch=' ';
	int m=0,n=0,p=0,i,j;
	while(ch!='\n')
	{
		scanf("%d %d%c",&a[m].num1,&a[m].num2,&ch);
		m++;
	}
	ch=' ';
	while(ch!='\n')
	{
		scanf("%d %d%c",&b[n].num1,&b[n].num2,&ch);
		n++;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[p].num1=a[i].num1*b[j].num1;
			c[p].num2=a[i].num2+b[j].num2;
			p++;
		}
	}
	qsort(c,p,sizeof(struct book),cmp);
	for(i=0;i<p-1;i++)
	{
		while(c[i].num2==c[i+1].num2)
		{
			c[i].num1+=c[i+1].num1;
			for(j=i+1;j<p-1;j++)
			{
				c[j].num1=c[j+1].num1;
				c[j].num2=c[j+1].num2;
			}
			p--;
		}
	}
	for(i=0;i<p;i++)
	{
		printf("%d %d ",c[i].num1,c[i].num2);
	}
	return 0;
}
int cmp(const void *p1,const void *p2)
{
	struct book *a=(struct book *)p1;
	struct book *b=(struct book *)p2;
	return -(a->num2-b->num2);
}

