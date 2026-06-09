#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct expression{			//多项式结构体
	int coe;				//系数
	int pow;				//指数
};
typedef struct expression ex;
ex a[2000],b[2000],c[2000];//a是第一个多项式，b是第二个多项式 ,c是最后相乘的多项式
int cmp(const void*p1,const void*p2);
int main()
{
	int i,j,k=0;
	int n=0,nn=0;//n是第一个多项式的项数 ，nn是第二个多项式的项数
	char ch;
	do   //读入第一个多项式
	{
		scanf("%d%d%c",&a[n].coe,&a[n].pow,&ch);
		n++;
	}while(ch!='\n');
	do	//读入第二个多项式
	{
		scanf("%d%d%c",&b[nn].coe,&b[nn].pow,&ch);
		nn++;
	}while(ch!='\n');
	qsort(a,n,sizeof(ex),cmp); //按指数排序
	qsort(b,nn,sizeof(ex),cmp);	//按指数排序
	for(i=0;i<n;i++)
	{
		for(j=0;j<nn;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;//系数相乘
			c[k].pow=a[i].pow+b[j].pow;//指数相加
			k++;
		}
	}
	qsort(c,k,sizeof(ex),cmp);//根据指数排序
	for(i=0;i<k;i++)
	{
		if(c[i].pow == c[i+1].pow && c[i].pow!=0)//指数一样的进行去重操作
		{
			c[i+1].coe+=c[i].coe;//指数一样的进行去重操作
			c[i].coe=0;//去重项系数设为零
		}
	}
	qsort(c,k,sizeof(ex),cmp);//根据指数排序
	for(i=0;i<k;i++)
	{
		if(c[i].coe==0)//去重项不输出
		{
			continue;
		}
		else
		{
			printf("%d %d ",c[i].coe,c[i].pow);//输出
		}
	}
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct expression *a=(struct expression*)p1;
	struct expression *b=(struct expression*)p2;
	return b->pow-a->pow;
}

