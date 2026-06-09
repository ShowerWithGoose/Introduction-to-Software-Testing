#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct no_de
{
	int xi;//系数 
	int zhi;//指数 
}*Node,node;
struct no_de a[1000],b[1000],c[1000];//分别是相乘之前的两个多项式 和最后结果多项式 

int comp(const void *p1,const void *p2)
{
	Node c=(Node)p1;
	Node d=(Node)p2;
	return d->zhi-c->zhi;//按照指数降序排序 
}

int main()
{
	int i=0,j=0,k=0,l=0;
	int n1,n2;
	n1=0,n2=0;//分别代表两个多项式的项数 
	char ch=' ';
	char s1[1000],s2[1000];
    while(ch!='\n')
    {
    	scanf("%d%d%c",&a[n1].xi,&a[n1].zhi,&ch);
    	n1++;
	}
	ch=' ';
	while(ch!='\n')
	{
		scanf("%d%d%c",&b[n2].xi,&b[n2].zhi,&ch);
		n2++;
	}
//	gets(s1);
//	do
//	{
//		sscanf(s1,"%d%d%c",&a[n1].xi,&a[n1].zhi,&ch);
//		n1++;
//	}while(ch!='\0');
//	gets(s2);
//	do
//	{
//		sscanf(s2,"%d%d%c",&b[n2].xi,&b[n2].zhi,&ch);
//	}while(ch!='\0');


//	do//读入第一个多项式 
//	{
//		scanf("%d%d%c",&a[n1].xi,&a[n2].zhi,ch);//上面的结构数组本身就是c了 那这里的字符变量就不可以再命名为c 因为这样会冲突 
//		n1++;
//	}while(ch!='\n');
//	do//读入第二个多项式 
//	{
//		scanf("%d%d%c",&b[n2].xi,&b[n2].zhi,ch);
//		n2++;
//	}while(ch!='\n');


	//qsort(a,n1,sizeof(a[0]),comp);//按照指数排序 
	//qsort(b,n2,sizeof(b[0]),comp);
	
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;//系数相乘 
			c[k].zhi=a[i].zhi+b[j].zhi;//指数相加 
			k++;
		}
	}
	qsort(c,k,sizeof(c[0]),comp);//乘好之后按照指数排序 
	for(l=0;l<k;l++)//去除重复操作 
	{
		if(c[l].zhi==c[l+1].zhi && c[l].zhi!=0)//指数相同就去重 
		{
			c[l+1].xi+=c[l].xi;//后一项的系数加上去 
			c[l].xi=0;//前一项系数置为零 
		}
	}
	qsort(c,k,sizeof(c[0]),comp);
	for(l=0;l<k;l++)
	{
		if(c[l].xi!=0)
		{
			printf("%d %d ",c[l].xi,c[l].zhi);
		}
	}
	return 0;
}

