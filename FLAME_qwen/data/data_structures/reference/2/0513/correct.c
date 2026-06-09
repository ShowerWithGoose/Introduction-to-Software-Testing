#include<stdio.h>
#include<ctype.h>
#include<string.h>
long long bin(long long x, char op, long long y)
{
	if(op=='+')
	{
		return x+y;
	}
	else if(op=='-')
	{
		return x-y;
	}
	else if(op=='*')
	{
		return x*y;
	}
	else
	{
		return x/y;
	}
}
int main()
{
	char a[500],s[500];
	memset(s,' ',sizeof(s));
	gets(a);
	int i=0,j=0,k=0;;
	while(a[i]!='=')
	{
		if(a[i]!=' ')
		{
			s[j]=a[i];
			j++;
		}
		//printf("%c\n",s[j-1]);
		i++;
	}
	s[j]='\0';
	long long num[500]={0};
	char op[500];
	memset(op,' ',sizeof(op));
	i=0,j=0,k=0;
	while(s[i]!='\0')
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			long long n=0,mul=10;
			while(s[i]>='0'&&s[i]<='9')
			{
				n=n*mul+s[i]-'0';
				i++;
			}
			num[j]=n;
			j++;
			//printf("%lld\n",num[j-1]);
		}
		else
		{
            if(((s[i]=='*'||s[i]=='/')&&(op[k-1]=='+'||op[k-1]=='-'))||(k==0))
            {
            	op[k]=s[i];
            	k++,i++;
			}
			else
			{
				long long ans=bin(num[j-2],op[k-1],num[j-1]);
				num[j-2]=ans;
				j--,k--;
				op[k]=s[i];
				i++,k++;
			}
		}
		//printf("%d\n",num[j-1]);
	}
	if(j==1)
	{
		printf("%d",num[0]);
	}
	else{
	while(k!=0&&j>1)
	{
		long long ans=bin(num[j-2],op[k-1],num[j-1]);
		num[j-2]=ans;
		j--,k--;
		//printf("%lld\n",num[j-1]);
	}
	printf("%lld",num[j-1]);
	}
	return 0;
}


