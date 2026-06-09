#include<stdio.h>
#include<string.h>
int main()
{
	char str[200];
	int num[200] = {0};
	int E = 1;
	int i = 0;
	int j = 0;
	int k = 0;
	gets(str);
	int len = strlen(str);
	if(str[i] == '0')
	{
		i = i + 2;
		while(str[i] == '0')
		{
			E++;
			i++;
		}
		while(i < len)
		{
			num[j] = str[i] - '0';
			j++;
			i++;
		}
		k = j;
		j = 0;
		if(k == 1)
		{
			printf("%de-%d\n",num[j],E);
		}
		if(k > 1)
		{
			printf("%d.",num[j]);
			j++;
			while(j < k)
			{
				printf("%d",num[j]);
				j++;
			}
			printf("e-%d\n",E);
		}
		return 0;
	}
	if(str[i] != '0')
	{
		E = 0;
		while(str[i+1] != '.')
		{
			E++;
			num[j] = str[i] - '0';
			i++;
			j++;
		}
		num[j] = str[i] - '0';
		j++;
		i = i + 2;
		while(i < len)
		{
			num[j] = str[i] - '0';
			i++;
			j++;
		}
		k = j;
		j = 0;
		printf("%d.",num[j]);
		j++;
		while(j < k)
		{
			printf("%d",num[j]);
			j++;
		}
		printf("e%d\n",E);
	}
	return 0;
}
