#include <stdio.h>
#include <string.h>
int main(){
	char s[1000];
	gets(s);
	int i,j,k,ip=0;
	char p[1000];
	for(i=0,j=0;s[i]!='\0';i++)
	if(s[i]!=' ')
	s[j++]=s[i];
	s[j]='\0';
	int a[1000]={0},n;
	for(i=0;i<j-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			for(k=1;s[i+k]>='0'&&s[i+k]<='9';k++)
			a[i+k]=a[i+k-1]*10+s[i+k]-'0';
			a[i]=a[i+k-1];
			for(n=i+1;n<j-k+1;n++)
			s[n]=s[n+k-1];
			j=j-k+1;
		}
		else
		{
			if(s[i]=='-'||s[i]=='+')
			p[ip++]=s[i];
		}
	}
	int b[1000]={0},ib=0;
	for(i=0;i<j-1;i++)
	{
		if(s[i+1]=='-'||s[i+1]=='+'||s[i+1]=='=')
		{
			b[ib++]=a[i];	
			continue;
		}
		if(s[i]=='*')
		a[i+1]=a[i-1]*a[i+1];
		else if(s[i]=='/')
		a[i+1]=a[i-1]/a[i+1];
		if(s[i+2]=='-'||s[i+2]=='+')
		{
			b[ib++]=a[i+1];
			i++;
		}
	}
	int r;
	if(ip==0)
	r=a[0];
	else
	for(i=0;i<ip;i++)
	{	
		if(p[i]=='-')
		r=b[i+1]=b[i]-b[i+1];
		if(p[i]=='+')
		r=b[i+1]=b[i]+b[i+1];
	}
	printf("%d",r);
	return 0;
}

