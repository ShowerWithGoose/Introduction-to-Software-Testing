#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))

int cal(int a,int b,char c);
int main()
{
	int i=0,a[100],j=0;
	char s[100],c='0';
	while(c!='=')
	{
		scanf(" %d",&a[j]);
		j++;
		for(c='0';c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='=';)
		{
			scanf("%c",&c);
			if(c=='+'||c=='-'||c=='*'||c=='/'||c=='=')
			{
				s[i]=c;
				i++;		
			}
		}

	}
	s[i]='\0';
	int num=i-1;
	for(i=0;i<num;i++)
	{
		if(s[i]=='*'||s[i]=='/')
		{
			a[i+1]=cal(a[i],a[i+1],s[i]);
			a[i]=-1;
		}
	}
	for(i=0;i<=num;i++)
	{
		if(s[i]=='+'||s[i]=='-')
		{
			for(j=i+1;a[j]==-1;j++);
			a[j]=cal(a[i],a[j],s[i]);
		}
	}
	printf("%d",a[num]);
}
int cal(int a,int b,char c)
{
	if(c=='+')
	return a+b;
	else if(c=='-')
	return a-b;
	else if(c=='*')
	return a*b;
	else if(c=='/')
	return a/b;
	else
	return -1;
}



