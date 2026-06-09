#include <stdio.h>
struct num3{
	int xishu;
	int zhishu;
};
struct num3 d[10000];
int main()
{
	char c;
	int i,j,k;
	struct num1{
		int zhishu;
		int xishu;
	};
	struct num1 a[100];
	struct num2{
		int zhishu;
		int xishu;
	};
	struct num2 b[100];
	i=0;
	scanf("%d%d%c",&a[i].xishu,&a[i].zhishu,&c);
	while(c!='\n')
	{
		i++;
		scanf("%d%d%c",&a[i].xishu,&a[i].zhishu,&c);
	}
	int len1=i;
	i=0;
	scanf("%d%d%c",&b[i].xishu,&b[i].zhishu,&c);
	while(c!='\n')
	{
		i++;
		scanf("%d%d%c",&b[i].xishu,&b[i].zhishu,&c);
	}
	int len2=i;
	i=0;
	for(j=0;j<=len1;j++)
	{
		for(k=0;k<=len2;k++)
		{
			d[i].xishu=a[j].xishu*b[k].xishu;
			d[i].zhishu=a[j].zhishu+b[k].zhishu;
			i++;
		}
	}
	int i0=i-1;
	for(i=0;i<=i0-1;i++)
	{
		for(j=0;j<=i0-1-i;j++)
		{
			if(d[j].zhishu<d[j+1].zhishu)
			{
				int temp;
				temp=d[j].zhishu;
				d[j].zhishu=d[j+1].zhishu;
				d[j+1].zhishu=temp;
				temp=d[j].xishu;
				d[j].xishu=d[j+1].xishu;
				d[j+1].xishu=temp;
			}
		}
	}
	for(i=0;i<=i0-1;i++)
	{
		if(d[i].zhishu==d[i+1].zhishu)
		{
			d[i].xishu=d[i].xishu+d[i+1].xishu;
			for(j=i+1;j<=i0-1;j++)
			{
				d[j].xishu=d[j+1].xishu;
				d[j].zhishu=d[j+1].zhishu;
			}
			i--;
			i0--;
		}
	}
	for(i=0;i<=i0;i++)
	{
		printf("%d %d ",d[i].xishu,d[i].zhishu);
	}
	return 0;
}

