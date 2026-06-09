#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	int xishu;
	int zhishu;
	
};
int cmp(const void*a,const void *b)
{
	struct node *aa=(struct node*)a;
	struct node *bb=(struct node* )b;
	return bb->zhishu-aa->zhishu;
}
int main()
{
	struct node a1[100],a2[100],a3[100],a4[100];
	int num1=0,num2=0,num3=0,num4=0,a,b;
	char c;
	while(c!='\n')
	{
		
		scanf("%d%d%c",&a1[num1].xishu,&a1[num1].zhishu,&c);
		num1++;
		
	}
	c=' ';
	while(c!='\n')
	{
		
			scanf("%d%d%c",&a2[num2].xishu,&a2[num2].zhishu,&c);
			num2++;
		
	}
//	printf("%d %d",num1,num2);
	for(int i=0;i<num1;i++)
	{
		for(int j=0;j<num2;j++)
		{
			a3[num3].xishu=a1[i].xishu*a2[j].xishu;
			a3[num3].zhishu=a1[i].zhishu+a2[j].zhishu;
			num3++;
		}
	}
	qsort(a3,num3,sizeof(a3[0]),cmp);
	
		a4[0].xishu=a3[0].xishu;
			a4[0].zhishu=a3[0].zhishu;
			
	for(int k=1;k<num3;k++)
	{
		if(a3[k].zhishu!=a4[num4].zhishu)
		{
			
			a4[num4+1].xishu=a3[k].xishu;
			a4[num4+1].zhishu=a3[k].zhishu;
			num4++;
		}
		else 
		{
			a4[num4].xishu+=a3[k].xishu;
		}
	}
	for(int l=0;l<=num4;l++)
	printf("%d %d ",a4[l].xishu,a4[l].zhishu);
	
}
