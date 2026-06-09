#include <stdio.h>
#include <string.h>
int main()
{
	char s[15626];
	gets(s);
	int j=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		{
			s[j]=s[i];
			j++;
		}
	}
	int num[1000]={0},time=0,place=0;
	char ch[123];
	for(int i=0;i<j;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[time]=num[time]*10+s[i]-48;
		}
		else
		{
			ch[place]=s[i];
			time++;
			place++;
		}
	}
	for(int i=0;i<place;i++)
	{
		if(ch[i]=='*')
		{
			num[i+1]=num[i]*num[i+1];
			num[i]=0;
			if(i==0)
			{
				ch[i]='+';
			}
			else if(ch[i-1]=='+')
			{
				ch[i]='+';
			}
			else if(ch[i-1]=='-')
			{
				ch[i]='-';
			}
		}
		else if(ch[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
			if(i==0)
			{
				ch[i]='+';
			}
			else if(ch[i-1]=='+')
			{
				ch[i]='+';
			}
			else if(ch[i-1]=='-')
			{
				ch[i]='-';
			}
		}
	}
	int end=0;
	for(end=0;end<place;end++)
	{
		if(ch[end]=='+')
		{
			num[end+1]=num[end]+num[end+1];
		}
		else
		{
			num[end+1]=num[end]-num[end+1];
		}
	}
	printf("%d",num[end]);
	return 0;
}

