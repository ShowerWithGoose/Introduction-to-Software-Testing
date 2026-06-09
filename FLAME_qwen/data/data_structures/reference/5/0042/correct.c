#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct multi{
	int xishu;
	int zhishu;
	struct multi *next;
};
int cmp(const void*num,const void *numm)
{
	struct multi *a=(struct multi *)num;
	struct multi *b=(struct multi *)numm;
	return b->zhishu-a->zhishu;//指数从大到小排序 
 } 
int main()
{
	struct multi *head, *p, *q, *p0;
	struct multi number1[10001];
	struct multi number2[10001];
	struct multi mix[10001];
	head=p=NULL;
	int num=0,numm=0;
	int i,j,k=0,l; 
	char c=' ';//
	//读入两个多项式 
	for(num=0;c!='\n';num++)
	{
		scanf("%d%d%c",&number1[num].xishu,&number1[num].zhishu,&c);//存入结构体中指数系数，并记其顺序
		 
	}
	c=' ';
	for(numm=0;c!='\n';numm++)
	{
		scanf("%d%d%c",&number2[numm].xishu,&number2[numm].zhishu,&c);
	}
	//多项式相乘
	for(i=0;i<num;i++)
	{
		for(j=0;j<numm;j++)
		{
			mix[k].xishu=number1[i].xishu*number2[j].xishu;//系数相乘
			mix[k].zhishu=number1[i].zhishu+number2[j].zhishu;//指数相加
			k++; 
		}
	}
	//排列结果
	qsort(mix,k,sizeof(mix[0]),cmp);
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(mix[i].zhishu==mix[j].zhishu)//指数相等系数相加
			{
				mix[i].xishu=mix[i].xishu+mix[j].xishu;
				mix[j].xishu=0;
				mix[j].zhishu=-1;
			 } 
		
		 } 
	 } 
	for(i=0;i<k;i++)
	{
		if(mix[i].xishu!=0&&mix[i].zhishu!=-1)
		{
			printf("%d %d ",mix[i].xishu,mix[i].zhishu);
		}
	 } 
	return 0;
 } 

