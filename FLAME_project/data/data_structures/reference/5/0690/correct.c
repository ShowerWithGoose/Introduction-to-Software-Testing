#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
//如何处理换行符，使数据理想化的存储在结构体中 
//先按照正常的计算方法将a与b相乘存储到链表里， 
struct multi{
	 int co;
	 int index;
}lista[1000],listb[1000],listc[1000];
int cmp(const void*p1,const void*p2)
{
	struct multi *a=(struct multi*)p1;
	struct multi *b=(struct multi*)p2;
	return b->index-a->index;
}
int main()
{
	char  s[1000],c;
	int l1=0,l2=0,i,j,l3=0;
	do{
		scanf("%d%d%c",&lista[l1].co,&lista[l1].index,&c);
		l1++;
	}while(c!='\n');
	while(scanf("%d%d",&listb[l2].co,&listb[l2].index)!=EOF)
	l2++;
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			listc[l3].co=(lista[i].co)*(listb[j].co);
			listc[l3].index=(lista[i].index)+(listb[j].index);
			l3++;
		}
	}
	qsort(listc,l3,sizeof(struct multi),cmp);
	for(i=0;i<l3-1;i++)
	{
		if(listc[i].index!=listc[i+1].index&&listc[i].co!=0)
		printf("%d %d ",listc[i].co,listc[i].index);
		else
		listc[i+1].co+=listc[i].co;
	}
	printf("%d %d ",listc[i].co,listc[i].index);
	return 0;
}

