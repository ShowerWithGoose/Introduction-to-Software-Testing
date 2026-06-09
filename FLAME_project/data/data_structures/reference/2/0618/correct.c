#include<stdio.h>
#include<string.h>
int a[1000],b[10000];
int main()
{
	char ch[10000],s[10000],t[10000];
	int i,j,len,k,ans;
	gets(ch);
	len=strlen(ch);
	j=0;
	for(i=0;i<len;i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')
		{
			a[j]=a[j]*10+ch[i]-'0';
		}
		else if(ch[i]==' ') continue;
		else
		{
			s[j]=ch[i];
			j++;
		}
	}
	k=0;
	for(i=0;i<j;i++)
	{
		if(s[i]=='/')
		{
			if(i&&(s[i-1]=='/'||s[i-1]=='*'))	b[k]=b[k]/a[i+1];
			else b[k]=a[i]/a[i+1];
		}
		else if(s[i]=='*')
		{
			if(i&&(s[i-1]=='/'||s[i-1]=='*'))	b[k]=b[k]*a[i+1];
			else b[k]=a[i]*a[i+1];
			
		}
		else
		{
			if(!(i&&(s[i-1]=='/'||s[i-1]=='*')))
			b[k]=a[i];
			t[k]=s[i];
			k++;
		}
	}
	if(j==1) ans=a[0];
	else ans=b[0];
	for(i=0;i<k-1;i++)
	{
		if(t[i]=='+')
		{
			ans=ans+b[i+1];
		}
		else if(t[i]=='-') ans=ans-b[i+1];
	}
	printf("%d",ans);
	return 0;
}

