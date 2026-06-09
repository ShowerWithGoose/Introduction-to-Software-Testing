#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct node/*定义多项式中单个项的结构体*/
{
	int coef;/*系数*/
	int exp;/*指数*/
}NODE;
NODE a[1000],b[1000],c[1000],d[1000];/*a为第一个多项式,b为第二个多项式,c为做乘法之后的多项式,d为最终的多项式*/ 
cmp(const void *p1,const void *p2)/*按指数从大到小排序*/
{
	NODE *q1=(NODE *)p1;
	NODE *q2=(NODE *)p2;
	return q2->exp-q1->exp;
}
int main()
{
	int i,j,m=0,n=0,k=0,len=0;
	char ch=' ';
	while(ch!='\n')/*输入第一个多项式,一共m项*/
	{
		scanf("%d%d%c",&a[m].coef,&a[m].exp,&ch);
		m++;
	}
	ch=' ';
	while(ch!='\n')/*输入第二个多项式,一共n项*/
	{
		scanf("%d%d%c",&b[n].coef,&b[n].exp,&ch);
		n++;
	}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			c[k].coef=a[i].coef*b[j].coef;
			c[k].exp=a[i].exp+b[j].exp;	
			k++;
		} 
	qsort(c,k,sizeof(NODE),cmp);
	for(i=0;i<k;)/*合并指数相同的项*/
	{
		d[len].coef=c[i].coef;d[len].exp=c[i].exp;
		for(j=i+1;(j<k)&&(c[j].exp==c[i].exp);j++)
			d[len].coef+=c[j].coef;
		len++;
		i=j;
	}
	for(i=0;i<len;i++)
		printf("%d %d ",d[i].coef,d[i].exp);
	return 0 ;
}

