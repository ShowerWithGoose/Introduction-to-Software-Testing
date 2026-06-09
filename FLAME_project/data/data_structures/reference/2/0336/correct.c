#include <stdio.h>
int main()
{
	char S[1000]={'\0'};
	char s[1000]={'\0'};
	int num[1000]={0};
	char fuhao[1000]={'\0'};
	gets(S);
	int i,j,k;
	for(i=0,j=0;i<strlen(S);i++)
	{
		if(S[i]!=' ')
		{
			s[j]=S[i];	
			j++;
		}
	}
	i=0,j=0,k=0;
	int flag=0;
	while(flag!=1)
	{
		while(s[k]>='0'&&s[k]<='9')
		{
			num[i]=num[i]*10+s[k]-'0';
			k++;
		}
		i++;
		fuhao[j]=s[k];
		j++;
		k++;
		if(fuhao[j-1]=='=')
		flag=1;
	}
	int ans=0,a=num[0],b=0;
	for(i=1,j=0;fuhao[j]!='='&&fuhao[j]!='+'&&fuhao[j]!='-';i++,j++)
	{
		if(fuhao[j]=='/')
		{
			a/=num[i];
		}
		else if(fuhao[j]=='*')
		{
			a*=num[i];
		}
	}
	ans=a;
	A:
	if(fuhao[j]=='+')
	{
		b=num[i];
		i++,j++;
		while(fuhao[j]!='='&&fuhao[j]!='+'&&fuhao[j]!='-')
		{
			if(fuhao[j]=='/')
			{
				b/=num[i];
			}
			else if(fuhao[j]=='*')
			{
				b*=num[i];
			}
			i++,j++;
		}
		ans+=b;
		goto A;
	}
	else if(fuhao[j]=='-')
	{
		b=num[i];
		i++,j++;
		while(fuhao[j]!='='&&fuhao[j]!='+'&&fuhao[j]!='-')
		{
			if(fuhao[j]=='/')
			{
				b/=num[i];
			}
			else if(fuhao[j]=='*')
			{
				b*=num[i];
			}
			i++,j++;
		}
		ans-=b;
		goto A;
	}
	printf("%d",ans);
	return 0;
}

