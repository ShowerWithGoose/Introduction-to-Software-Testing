#include<stdio.h>
#include<string.h>
#include<math.h>
int math(char);
int select(char);
char c;
long b[100];
int main()
{
	char str[100];
	char s[50];
	gets(str);
	long i,a,d;
	a=0;
	d=0;
	long sum,sum1=0,sum2=0;
	b[a]=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			b[a]=b[a]*10+math(str[i]);
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='=')
		{
		s[d]=str[i];
		d++;
		a++;
		b[a]=0;
	}
	}
	sum=0;
	int j,n;
	for(j=0;s[j]!='=';j++)
	{
		if(s[j]=='*'||s[j]=='/')
		{
			n=j;
			sum1=b[j];
			while(s[j]=='*'||s[j]=='/')
			{
				if(s[j]=='*')
				sum1=sum1*b[j+1];
				if(s[j]=='/')
				sum1=sum1/b[j+1];
				j++;
			}
			j--;
			if(s[n-1]=='-')
			sum1=sum1*(-1);
		}
		else
		{
			while(s[j+1]=='+'||s[j+1]=='-')
			{
				if(j==0)
				sum2=b[j]+b[j+1];
				else
				{
					if(s[j]=='+')
					sum2+=b[j+1];
					else
					sum2-=b[j+1];
				}
				j++;
			}
			if(j==0)
			sum2=b[j];
			if(s[j+1]=='=')
			{
				if(s[j]=='+')
				sum2+=b[j+1];
				else
				sum2-=b[j+1];
			}
		}
	sum+=sum1+sum2;
	sum1=0;
	sum2=0;
	}
	if(s[0]=='=')
	sum=b[0];
	printf("%ld",sum);
	return 0;
}
int math(char m)
{
	return m-'0';
}




