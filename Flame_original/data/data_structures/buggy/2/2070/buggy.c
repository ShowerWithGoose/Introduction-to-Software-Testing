#include <stdio.h>
#include <string.h>
int main()
{
	char s[10000]={}, fig[10000]={};
	int num[10000]={}, j=0, l=0;
	gets(s);
	char first='+';
	if(s[0]=='-')
	{
		first='-';
		for(int p=0;p<strlen(s);p++)
		{
			s[p]=s[p+1];
		}
	}
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				int k=i;
				while(s[k]>='0'&&s[k]<='9')
				{
					num[l]=num[l]*10+(s[k]-'0');
					k++;
				}
				l++;
				i=k;
			}else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
			{
				fig[j]=s[i];
				j++;
			}else
			continue;
		}
	
	
	int num0=num[0], rec0=0, k=0;
	char str='+';
	for(int i=0;i<strlen(s);i++)
	{
		if(fig[i]=='*'||fig[i]=='/')
		{
			num0=num[i];
			k=i;
			while(fig[k]=='*'||fig[k]=='/')
			{
				if(fig[k]=='*')
				{
					num0=num0*num[k+1];
					k++;
				}
				else if(fig[k]=='/')
				{
					num0=num0/num[k+1];
					k++;
				}
			}
			i=k;
		}
		if(fig[i]=='+'||fig[i]=='-')
		{
			if(str=='+')
			{
				rec0+=num0;
				str=fig[i];
			}else if(str=='-')
			{
				rec0-=num0;
				str=fig[i];
			}
		}
		if(fig[i]=='=')
		{
			if(str=='+')
			{
				rec0+=num0;
			}else if(str=='-')
			{
				rec0-=num0;
			}
			
			if(first=='+')
			printf("%d\n", rec0);
			else if(first=='-')
			printf("-%d\n", rec0);
			
			break;
		}
		
	}
	return 0;
}
