#include<stdio.h>
#include<string.h>
struct mes{
	int x1;
	int y1;
	int x2;
	int y2;
}mes[105],tmp;
void bubble(int n,struct mes mes[105],struct mes tmp)
{
	for(int i = 0;i < n-1;i++)
	{
		for(int j = 0;j < n-i-1;j++)
		{
			if(mes[j].x1 > mes[j+1].x1)
			{
				tmp = mes[j];
				mes[j] = mes[j+1];
				mes[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int n;
	int i = 0;
	int j = 0;
	int num = 1;
	int max = 1;
	int rem;
	int k;
	scanf("%d",&n);
	while(i < n)
	{
		scanf("%d %d %d %d",&mes[i].x1,&mes[i].y1,&mes[i].x2,&mes[i].y2);
		i++;
	}
	bubble(n,mes,tmp);
	i = 0;
	for(i = 0;i < n;i++)
	{
		k = i;
		num = 1;
		for(j = i+1;j < n;j++)
		{
			if(mes[k].x2 == mes[j].x1&&mes[k].y2 == mes[j].y1)
			{
				num++;
				k = j;
			}
		}
		if(num >= max)
		{
			max = num;
			rem = i;
		}
	}
	printf("%d %d %d\n",max,mes[rem].x1,mes[rem].y1);
	return 0;
}
