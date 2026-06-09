#include <stdio.h>
int main()
{
	char buf[10001],z[1001],x[1001];   //z存储整数部分，x存储小数部分 
	int i  = 0,j = 0,n = 0,m = 0;
	gets(buf);
	sscanf(buf,"%[^.]",z);
	i = strlen(z) + 1;
	while(buf[i] != '\0')
	{
		x[j] = buf[i];
		j++,i++;
	}
	x[j] = '\0';
	if(z[0] == '-')
	{
		m = strlen(z) - 2;
		i = 2;
		printf("-");
		if(z[1] == '0')
		{
			j = 0;
		}
		else
		{
			j = 1;
			printf("%c",z[1]);
		}
	}
	else 
	{
		m = strlen(z) - 1;	
		i = 1;
		if(z[0] == '0')
		j = 0;
		else
		{
			j = 1;
			printf("%c",z[0]);
		}
	}
	if(j == 0)//整数部分为0 
	{
		i = 0;
		while(x[i] != '\0')
		{
			if(x[i] != '0')
			{
				printf("%c",x[i++]);
				if(x[i] != '\0')
				printf(".");
				while(x[i] != '\0')
				{
					printf("%c",x[i]);
					i++;
				}
				break;
			}
			else
			{
				n++;
			}
			i++;
		}
		printf("e-%d",n + 1);
	}
	else
	{
		printf(".");
		while(z[i] != '\0')
		{
			printf("%c",z[i]);
			i++;
		}
		i = 0;
		while(x[i] != '\0')
		{
			printf("%c",x[i]);
			i++;
		}
		printf("e%d",m);
	}
	return 0;
}

