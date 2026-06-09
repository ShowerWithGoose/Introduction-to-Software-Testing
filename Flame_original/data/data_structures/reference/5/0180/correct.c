#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct MATH{
	int xi;
	int zhi;
};
struct MATH a[10000],b[10000],c[10000];
int cmp(const void *a , const void *b)
{	
struct MATH* c1=(struct MATH*)a;struct MATH* c2=(struct MATH*)b;
return c2->zhi-c1->zhi;
}
int main(){
	int i,j,k=0;
	int n=0,m=0;
	char ch;
	do
	{
		scanf("%d%d%c",&a[n].xi,&a[n].zhi,&ch);
		n++;
	}while(ch!='\n');
	do
	{
		scanf("%d%d%c",&b[m].xi,&b[m].zhi,&ch);
		m++;
	}while(ch!='\n');
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zhi=a[i].zhi+b[j].zhi;
			k++;
		}
	}
	qsort(c,k,sizeof(struct MATH),cmp);
    for(i=0;i<k-1;i++)
	{
		if(c[i].zhi==c[i+1].zhi)
		{
			c[i+1].xi+=c[i].xi;
			c[i].xi=0;
		}
	 }
	for(i=0;i<k;i++){	if(c[i].xi)	printf("%d %d ",c[i].xi,c[i].zhi);}
	return 0;
}

