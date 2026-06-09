#include<stdio.h>
#include<string.h>
int main()
{
	char s[110];
	char a[110];
	char c[110];
	gets(s);
	int i, j ;
	int x = 0;
	int y;
	int flag = 0;
	for(y = 0;y <= strlen(s);y ++)
	{
		if(s[y] == '.')
		{
			flag ++;
		}
	}
	if(s[0] != '-' && flag != 0)
	{if(s[1] == '.' && s[0] == '0')
	{
		for(i = 3; s[i] != '\0';i ++)
		{
			if(s[i] != '0')
			{
				break;	
			}	
		}
		if(i == strlen(s) - 1)
		{
			for(j = i;s[j] != '\0';j ++)
			{
				a[x++] = s[j];
			}
			a[x] = '\0';
		}
		if(i != strlen(s) - 1 && i != strlen(s))
		{
			for(j = i;s[j] != '\0';j ++)
			{
				a[x++] = s[j];
			}
			a[x] = '\0';
		}
		if(i == strlen(s))
		{
			a[0] = s[i-1];
			a[1] = '\0';
			x ++;
		}
		if(strlen(a) == 1)
		{
			for(i = 0;i < x;i ++)
			{
				printf("%c",a[i]);
			}	
			printf("e-%d",strlen(s)-2);
		}
		if(strlen(a) > 1)
		{
			printf("%c.",a[0]);
			for(i = 1;i < x;i ++)
			{
				printf("%c",a[i]);	
			}	
			printf("e-%d",strlen(s)-i - 1);
		}	
	}
	if(s[0] != '0' && s[1] == '.')
	{
		for(i = 0;s[i] != '\0';i ++)
		{
			printf("%c",s[i]);
		}
		printf("e0");
	}
	if(s[1] >= '0' && s[1] <= '9' && s[1] != '.')
	{
		for(i = 0;s[i] != '.';i ++)
		{
			a[x++] = s[i];
		}
		y = x;
		for(j = i+1;s[j] != '\0';j ++)
		{
			a[x++] = s[j];
		}
		a[x] = '\0';
		printf("%c.",a[0]);
		for(i = 1;a[i] != '\0';i ++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",y - 1);
	}
	}
	if(s[0] != '-' && flag == 0)
	{
		for(j = strlen(s) - 1;j > 0;j --)
		{
			if(s[j] != '0')
			{
				break;
			}
		}
		if(j == 0)
		{
		printf("%c",s[0]);
		printf("e%d",strlen(s) - 1);	
		}
		if(j != 0 )
		{
			printf("%c.",s[0]);
	
		for(i = 1;i <=  j ;i ++)
		{
			printf("%c",s[i]);
		}
		printf("e%d",strlen(s) - 1);
		}
	}
	if(s[0] == '-' && flag != 0)
	
	{
		for(i = 1;i <= strlen(s);i ++)
		{
			c[x++] = s[i];
		}
	c[x] = '\0';
	if(c[1] == '.' && c[0] == '0')
		{for(i = 3; c[i] != '\0';i ++)
		{
			if(c[i] != '0')
			{
				break;	
			}	
		}
		if(i == strlen(c) - 1)
		{
			x = 0;
			for(j = i;c[j] != '\0';j ++)
			{
				a[x++] = c[j];
			}
			a[x] = '\0';
		}
		if(i != strlen(c) - 1&& i!=strlen(c))
		{
			x = 0;
			for(j = i ;c[j] != '\0';j ++)
			{
				a[x++] = c[j];
			}
			a[x] = '\0';
		}
		if(i == strlen(c))
		{
			a[0] = c[i-1];
			a[1] = '\0';
			x = 1;
		}
		if(strlen(a) == 1)
		{
			for(i = 0;i < x;i ++)
			{
				printf("-%c",a[i]);
			}	
			printf("e-%d",strlen(c)-2);
		}
		if(strlen(a) > 1)
		{
			printf("-%c.",a[0]);
			for(i = 1;i < x;i ++)
			{
				printf("%c",a[i]);	
			}	
			printf("e-%d",strlen(c)-3);
		}	
	}
	if(c[0] != '0' && c[1] == '.')
	{
		printf("-");
		for(i = 0;c[i] != '\0';i ++)
		{
			printf("%c",c[i]);
		}
		printf("e0");
	}
	if(c[1] >= '0' && c[1] <= '9' && c[1] != '.')
	{
		x = 0;
		for(i = 0;c[i] != '.';i ++)
		{
			a[x++] = c[i];
		}
		y = x;
		for(j = i+1;c[j] != '\0';j ++)
		{
			a[x++] = c[j];
		}
		a[x] = '\0';
		printf("-%c.",a[0]);
		for(i = 1;a[i] != '\0';i ++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",y);
	}
	}
	if(s[0] == '-' && flag == 0)
	{
		for(i = 1;i <= strlen(s);i ++)
		{
			c[x++] = s[i];
		}
	c[x] = '\0';
		for(j = strlen(c) - 1;j > 0;j --)
		{
			if(c[j] != '0')
			{
				break;
			}
		}
		if(j == 0)
		{
		printf("-%c",c[0]);
		printf("e%d",strlen(c) - 1);	
		}
		if(j != 0 )
		{
			printf("-%c.",c[0]);
	
		for(i = 1;i <=  j ;i ++)
		{
			printf("%c",c[i]);
		}
		printf("e%d",strlen(c) - 1);
		}
	}
	
	return 0;
} 



