#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct expression{			//多项式结构体 
	int xishu;				//系数 
	int zhishu;				//指数 
};
typedef struct expression ex;
ex a[2000],b[2000],c[2000];//a是第一个多项式，b是第二个多项式 ,c是最后相乘的多项式 
int cmp(const void*p1,const void*p2);
int main()
{	
	int i,j,k=0;
	int n=0,m=0;//n是第一个多项式的项数 ，m是第二个多项式的项数  
	char ch;
	do   //读入第一个多项式 
	{
		scanf("%d%d%c",&a[n].xishu,&a[n].zhishu,&ch);
		n++;
	}while(ch!='\n');
	do	//读入第二个多项式
	{
		scanf("%d%d%c",&b[m].xishu,&b[m].zhishu,&ch);
		m++;
	}while(ch!='\n');
	
	qsort(a,n,sizeof(ex),cmp); //按指数排序 
	qsort(b,m,sizeof(ex),cmp);	//按指数排序 
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[k].xishu=a[i].xishu*b[j].xishu;//系数相乘 
			c[k].zhishu=a[i].zhishu+b[j].zhishu;//指数相加 
			k++;
		}
	}
	qsort(c,k,sizeof(ex),cmp);//按指数排序 
	for(i=0;i<k;i++)
	{
		if(c[i].zhishu==c[i+1].zhishu&&c[i].zhishu!=0)//若指数相同，进行去重操作 
		{
			c[i+1].xishu+=c[i].xishu;//若指数相同，进行去重操作 
			c[i].xishu=0;//去重项系数设为零 
		}
	}
	qsort(c,k,sizeof(ex),cmp);//按指数排序 
	for(i=0;i<k;i++)
	{
		if(c[i].xishu==0) continue;//不输出重项
		else printf("%d %d ",c[i].xishu,c[i].zhishu);//输出 
	}
	
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct expression *a=(struct expression*)p1;
	struct expression *b=(struct expression*)p2;
	return b->zhishu-a->zhishu;
}                                                

