#include<stdio.h>
#include<string.h>
char s[1000],b[1000];
int a[1000],c[1000];
int fun(char a[],int b[],int m,int n)
{
	int i=0,ans;
	if(m<0) ans=0;
	else
	ans=b[m];
	for(i=m+1;i<n;i=i+2)
	{
		if(a[i]=='*')
		ans=ans*b[i+1];
		else if(a[i]=='/')
		ans=ans/b[i+1];
	}
	return ans;
}
int main()
{
	gets(s);
	int i,j=0,k=1,m=0;
	int num;
	for(i=0;i<strlen(s);i++)
	{
		num=0;
		if(s[i]==' ')
		continue;
		if(s[i]>='0'&&s[i]<='9')
		{
			while(s[i]>='0'&&s[i]<='9')
			num=num*10+s[i++]-'0';
			a[j]=num;
			j=j+2;
			i--;
		}
		else
		{
			b[k]=s[i];
			k=k+2;
		}
	}
	for(i=1;i<999;i=i+2)
	{
		if(b[i]=='+' || b[i]=='-' ||b[i]=='=')
		{
			m++;
			c[m]=i;
		}
	}
	int ans=fun(b,a,0,c[1]-1);
	for(i=1;i<=m;i++)
	{
		if(b[c[i]]=='+')
		ans=ans+fun(b,a,c[i]+1,c[i+1]-1);
		else
		ans=ans-fun(b,a,c[i]+1,c[i+1]-1);
	}
	printf("%d\n",ans);
	return 0;
}

