#include<stdio.h>//回去解决qsort用法
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct expression{			//多项式结构体 
	int coe;				//系数 
	int pow;				//指数 
};
struct expression a[1000],b[1000],c[1000];
void rank(struct expression a[],int n)//n是长度
{
	int i,j;
	int tmp,tmp1;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].pow<a[j].pow)
			{
				tmp=a[i].pow;
				a[i].pow=a[j].pow;
				a[j].pow=tmp;
				tmp1=a[i].coe;
				a[i].coe=a[j].coe;
				a[j].coe=tmp1;

			}
		}
	}


}
int main()
{	
	int i,j,k=0;
	int n=0,p=0;//n是第一个多项式的项数 ，nn是第二个多项式的项数  
	char ch;
	do   //读入第一个多项式 
	{
		scanf("%d%d%c",&a[n].coe,&a[n].pow,&ch);
		n++;
	}while(ch!='\n');//这道题首先要解决读入问题由于它并不是以EOF结尾反而是以\n结尾所以用do来读入do的用法是while满足时就一直进行下去
	do
	{
		scanf("%d%d%ch",&b[p].coe,&b[p].pow,&ch);
		p++;
	} while (ch!='\n');
	for(i=0;i<n;i++)//用a去遍历b并存在c中
	{
		for(j=0;j<p;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;
			c[k].pow=a[i].pow+b[j].pow;
			k++;
		}

	}//去重和排序
	int cnt;
	cnt=k;
	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(c[i].pow==c[j].pow)
			{
				c[i].coe=c[i].coe+c[j].coe;
				c[j].coe=0;
			}
		}
	}
	rank(c,cnt);
	for(i=0;i<cnt;i++)
	{
		if(c[i].coe!=0)
		{
			printf("%d %d ",c[i].coe,c[i].pow);
		}
	}
	return 0;
}


