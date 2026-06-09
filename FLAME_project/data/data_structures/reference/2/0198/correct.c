#include<stdio.h>
#include<string.h> 
int main()
{
	char s[1000];int num[1000];char f[1000];
	gets(s);int p;int n=0;int a=0,b=0;
	for(p=0;s[p]!='\0';p++)
	{
		if(s[p]>='0'&&s[p]<='9')
		{
			if(s[p+1]>='0'&&s[p+1]<='9')
			{
				a+=s[p]-'0';
			    a*=10;
			}
			else
			{
				a+=s[p]-'0';
				num[n]=a;n++;a=0;
			}
		}
		else if(s[p]=='+'||s[p]=='-'||s[p]=='*'||s[p]=='/')
		{
			f[b]=s[p];
			b++;
		}
	}
	for(p=0;p<b;p++)
	{
		if(f[p]=='*'||f[p]=='/')
		{
			int q=p;
			while(f[p]=='*'||f[p]=='/')
			{
				if(f[p]=='*')
				{
					num[q]*=num[p+1];
				    p++;
				}
				else if(f[p]=='/')
				{
					num[q]/=num[p+1];
				    p++;
			    }
			}
		}
	}
	for(p=0;p<b;p++)
	{
		if(f[p]=='+'||f[p]=='-')
		{
			if(f[p]=='+')num[0]+=num[p+1];
			else num[0]-=num[p+1];
		}
	}
	printf("%d",num[0]);
	return 0;
}

