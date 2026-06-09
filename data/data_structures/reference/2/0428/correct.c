#include<stdio.h>
#include<string.h>
char ori_str[1000],str[1000];
int cal(char *,char *);
int getsnum(char *,char *);
int main()
{
	int i=0,len=0,sum=0,cnt=0,flag=1;
	char *p,*q;
	gets(ori_str);
	while(ori_str[i]!='\0')
	{
		if(ori_str[i]==' ')
		i++;
		else
		{
		str[len]=ori_str[i];
		i++;
		len++;
		}
	}
	while(flag)
	{   if(cnt==0)
	    p=str;
		else
		p=q+2;
		q=p;
		while(*q!='+'&&*q!='-'&&*q!='=')
		q++;
		if(*q=='=')
		flag=0;
		q--;
		if(cnt==0)
		sum+=cal(p,q);
		else
		{
			if(*(p-1)=='+')
			sum+=cal(p,q);
			else
			sum-=cal(p,q);
		}
		cnt++;
	}
	printf("%d",sum);
	return 0;
}
int cal(char *p,char *q)
{
	int ans=1,cnt=0,flag=1,k,num;
	char *m,*n;

	while(flag)
	{
	if(cnt==0)
	{
		m=p;
	}
	else
	{
	m=n+1;

	}
	n=m;
	while(*n!='*'&&*n!='/'&&n!=q+1)
	n++;
	if(n==q+1)
	flag=0;
	num=getsnum(m,n-1);
	if(cnt==0)
	{ans*=num;
	}
	else{
		if(*(m-1)=='*')
	ans*=num;
	else
	ans/=num;
	}

	cnt++;
	}
	return ans;
}
int getsnum(char *m,char *n)
{
	int ans=0,i,cnt;
	cnt=n-m+1;
	for(i=0;i<cnt;i++)
	{   ans*=10;
		ans+=*(m+i)-'0';

	}
	return ans;
}

