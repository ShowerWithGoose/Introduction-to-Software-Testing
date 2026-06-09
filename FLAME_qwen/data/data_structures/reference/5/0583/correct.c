#include<stdio.h>
#include<string.h>
struct num{
	int coe;
	int ind;
}former[1000],after[1000],ans[1000],tmp;
void bubble(int num3,struct num ans[1000],struct num tmp)
{
	for(int i = 0;i < num3-1;i++)
	{
		for(int j = 0;j < num3-i-1;j++)
		{
			if(ans[j].ind <= ans[j+1].ind)
			{
				tmp = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int num1,num2;
	char str;
	do
	{
		scanf("%d%d%c",&former[i].coe,&former[i].ind,&str);
		i++;
		num1++;
	}while(str!='\n');
	i = 0;
	do
	{
		scanf("%d%d%c",&after[i].coe,&after[i].ind,&str);
		i++;
		num2++;
	}while(str!='\n');
	i = 0;
	while(i < num1)
	{
		while(j < num2)
		{
			ans[k].ind = former[i].ind + after[j].ind;
			ans[k].coe = former[i].coe * after[j].coe;
			k++;
			j++;
		}
		i++;
		j = 0;
	}
	int num3 = k;
	k = 0;
	while(k < num3)
	{
		if(ans[k].coe == 0)
		{
			k++;
			continue;
		}
		m = k+1;
		while(m < num3)
		{
			if(ans[k].ind == ans[m].ind)
			{
				ans[m].coe = ans[m].coe + ans[k].coe;
				ans[k].coe = 0;
				break;
			}
			m++;
		}
		k++;
	}
	bubble(num3,ans,tmp);
	k = 0;
	while(k < num3)
	{
		if(ans[k].coe != 0)
		{
			printf("%d %d ",ans[k].coe,ans[k].ind);
			k++;
		}
		else
		{
			k++;
		}
	}
	return 0;
}
