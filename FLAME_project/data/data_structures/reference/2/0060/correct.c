#include<stdio.h>
#include<string.h>
int time(int m,int n)
{
	return n*m;
}
int divide(int m,int n)
{
	return m/n;
}
int main()
{
	char num[10010],num1[10010];
	char f[1010];
	int shu[10010];
	int ans=0;
	gets(num);
	
	int s,j,h=1;
	j=0;
	s=strlen(num);
	for(int i=0;i<=s;i++)//空格 
	{
		if(num[i]!=' ')
		{
			num1[j]=num[i];
			j++;
		}
	}
	
	for(int i=0;i<=s;i++)//数组初始化 
	{
		shu[i]=0;
		f[i]='0';
	}
	
	int s1,k;
	k=1;
	s1=strlen(num1);
	for(int i=0;i<=s1;i++)//数组赋值 
	{
		if(num1[i]>='0' && num1[i]<='9')
		{
			if(num1[i+1]>='0' && num1[i+1]<='9')
			{
				shu[k]=(shu[k]+num1[i]-'0')*10;
			}
			else
			{
				shu[k]=shu[k]+num1[i]-'0';
				k++;
			}
		}
	}
		
	for(int i=0;i<=s1;i++)//符号赋值 
	{
		if(num1[i]=='+' || num1[i]=='-' || num1[i]=='*' || num1[i]=='/')
		{
			char hold;
			hold=num1[i];
			f[h]=hold;
			h++;
		}
	}
	
	for(int i=1;i<=h+1;i++)//乘除 
	{
		if(f[i]=='*')
		{
			shu[i+1]=time(shu[i],shu[i+1]);
			shu[i]=0;
		}
		else if(f[i]=='/')
		{
			shu[i+1]=divide(shu[i],shu[i+1]);
			shu[i]=0;
		}
	}
	
	for(int i=1;i<=h;i++)//减 
	{ 
		if(f[i]=='-')
		{
			int j;
			for(j=i+1;1;j++)
			{
				if(shu[j]!=0)
				{
					break;
				}
			}
			ans=ans-shu[j];
			shu[j]=0;
		}
	}

	for(int i=0;i<=h+1;i++)//加 
	{
		ans=ans+shu[i];
	}
	
	printf("%d",ans);
	return 0;
} 

