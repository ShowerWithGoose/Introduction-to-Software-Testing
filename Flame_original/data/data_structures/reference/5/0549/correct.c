#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
//不用链表方法实现
int xsl[100],zsl[100];
int xsh[100],zsh[100];
int xsout[100],zsout[100];
int main()
{
	//创建数组，并分别将两个式子的系数和知数读入到数组中去
	int i=1,j=1;//都从第一位开始存入 
	int lenl=0,lenh=0,lenk=0;
	char laji;
	scanf("%d%d",&xsl[i],&zsl[i]);
	while(scanf("%c",&laji)&&laji==' ')
	{
		i++;
		scanf("%d%d",&xsl[i],&zsl[i]);
	}
	lenl=i;
	scanf("%d%d",&xsh[j],&zsh[j]);
	while(scanf("%c",&laji)&&laji==' ')
	{
		j++;
		scanf("%d%d",&xsh[j],&zsh[j]);
	}
	lenh=j;
	/*for(i=1;i<=lenl;i++)
	{
		printf("%d %d\n",xsl[i],zsl[i]);
	}
	for(i=1;i<=lenh;i++)
	{
		printf("%d %d\n",xsh[i],zsh[i]);
	}*/
	
	//将指数相加 系数相乘 存放到数组中去  循环嵌套 
	int k=1;
	for(i=1;i<=lenl;i++)
	{
		for(j=1;j<=lenh;j++)
		{
			xsout[k]=xsl[i]*xsh[j];//系数相乘
			zsout[k]=zsl[i]+zsh[j];//指数相加 
			k++;
		}
	}
	lenk=k-1;
	//按照指数大小进行降序排序
	for(i=1;i<=lenk-1;i++)//需要进行lenk-1轮排序 
	{
		for(j=lenk;j>=i+1;j--)//从最后开始比较 
		{
			if(zsout[j]>zsout[j-1])
			{
				//交换指数和系数
				int tmp;
				tmp=xsout[j];
				xsout[j]=xsout[j-1];
				xsout[j-1]=tmp;
				
				tmp=zsout[j];
				zsout[j]=zsout[j-1];
				zsout[j-1]=tmp;
			}
		}
	}
	//将相乘后指数相同的项合并（系数相加）
	int mark=1;
	for(i=1;i<=lenk-1&&i+mark<=lenk;i++)//与后一项比较 
	{
		if(xsout[i]==-1)
		{
			mark=1;
			continue;
		}
		else if(zsout[i]==zsout[i+mark])
		{
			xsout[i]=xsout[i]+xsout[i+mark];
			xsout[i+mark]=-1;
			mark++;i--;
		}
		else
		{
			mark=1;
		}
	 } 
	//输出结果 
	for(i=1;i<=lenk;i++)
	{
		if(xsout[i]!=-1)
		printf("%d %d ",xsout[i],zsout[i]);
	}
    return 0;
}


