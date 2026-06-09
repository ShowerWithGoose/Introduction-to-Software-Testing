#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define  pr printf
#define ll long long
#define int long long 

char s[100000],op[500000];
int len,num[500000],ord,delta=0;
int atoi(char *p)
{
	int i,n;
	ord=0;
	for(n=i=0;*(p+i)>='0'&&*(p+i)<='9';i++)
	{
		n=10*n+*(p+i)-'0';
	}
	ord=i;
	return n;
} 
int mul(int a,int p);
int main()
{
	int i,j,k,ans,temp,mark;
	gets(s);
	for(j=i=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')s[j++]=s[i]; 
	}
	s[j]='\0';
	//puts(s);
	len=strlen(s);
	for(k=j=i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[j++]=atoi(&s[i]);
			i=i+ord-1;
			continue;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
		{
			op[k++]=s[i];
			continue;
		}
		else if(s[i]=='*'||s[i]=='/')
		{
			delta=0;
			temp=mul(num[j-1],i);
			if(j>=1)num[j-1]=temp;
			else num[j]=temp;
			i=i+delta-1;
			continue;
		}
	}
	ans=num[0];
	for(i=0;op[i]!='=';i++)
	{
		mark=(op[i]=='+')?1:-1;
		ans=ans+mark*num[i+1];
	}
	printf("%lld",ans);
	return 0;
}
int mul(int a,int p)
{
	int b,c,list=0;

	b=atoi(&s[p+1]);
	list=ord;
	delta=delta+list+1;
	c=(s[p]=='*')?a*b:a/b;
	if(s[p+list+1]=='*'||s[p+list+1]=='/')
	{
		return mul(c,p+list+1);
	}
	return c;
}


