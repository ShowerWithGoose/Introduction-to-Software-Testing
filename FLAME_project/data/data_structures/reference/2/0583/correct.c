#include<stdio.h>
#include<string.h>

int main()
{
	int a[100];
	char ch[100];
	char str[1000];
	int sign;
	int ans;
	int tem;
	gets(str);
	int len = strlen(str);
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < len)
	{
		if(str[i] == ' ')
		{
			i++;
			continue;
		}
		if(str[i] >= '0'&&str[i] <= '9')
		{
			a[j] = str[i] - '0';
			while(str[i+1]>='0'&&str[i+1]<='9')
			{
				 a[j] = a[j]*10 + str[i+1] - '0';
				 i++;
			}
			j++;
			i++;
			continue;
		}
		if(str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/')
		{
			ch[k] = str[i];
			i++;
			k++;
			continue;
		}
		if(str[i] == '=')
		{
			ch[k] = str[i];
			break;
		}
    }
	sign = k;
	j = 0;
	k = 0;
	ans = a[0];
	while(k < sign)
	{
		if((ch[k]=='+'||ch[k]=='-')&&ch[k+1]=='=')
		{
			if(ch[k] == '+')
			{
				ans = ans + a[k+1];
			}
			if(ch[k] == '-')
			{
				ans = ans - a[k+1];
			}
			break;
		}
		if((ch[k]=='+'||ch[k]=='-')&&(ch[k+1]=='+'||ch[k+1]=='-'))
		{
			if(ch[k] == '+')
			{
				ans = ans + a[k+1];
			}
			if(ch[k] == '-')
			{
				ans = ans - a[k+1];
			}
			k++;
			continue;
		}
		if(ch[k]=='/'||ch[k]=='*')
		{
			if(ch[k] == '*')
			{
				ans = ans * a[k+1];
			}
			if(ch[k] == '/')
			{
				ans = ans / a[k+1];
			}
			k++;
			continue;
		}
		if((ch[k]=='+'||ch[k]=='-')&&(ch[k+1]=='*'||ch[k+1]=='/'))
		{
			j = k;
			tem = a[k+1];
			while(ch[k+1]=='*'||ch[k+1]=='/')
			{
				if(ch[k+1]=='*')
				{
					tem = tem * a[k+2];
				}
				if(ch[k+1]=='/')
				{
					tem = tem / a[k+2];
				}
				k++;
			}
			if(ch[j]=='+')
			{
				ans = ans + tem;
			}
			if(ch[j]=='-')
			{
				ans = ans - tem;
			}
			k++;
			continue;
		}
	}
	printf("%d\n",ans);
	return 0;
}


