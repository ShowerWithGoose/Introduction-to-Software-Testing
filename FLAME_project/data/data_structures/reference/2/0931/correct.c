#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
char s[100000]; 
int pd1(char *a)
{
	while (*a!='\0')
	{
	if (*a=='/'||*a=='*')	return 1;
	a++;
	}
	return -1;
}
void cl1(char *a)
{
	long long i=0,j;
	char p[1000];
	while (s[i]!='*'&&s[i]!='/')
	i++;
	int l=0,r=0;
	l=i-1;
	r=i+1;
	while (s[l]>='0'&&s[l]<='9') l--;
	int n1=0,n2=0;
	for (j=l+1;j<i;j++)
	 n1=n1*10+s[j]-'0';
	while (s[r]>='0'&&s[r]<='9') r++;
	for (j=i+1;j<r;j++)
	n2=n2*10+s[j]-'0';
	long long sum;
	if (s[i]=='*') sum=n1*n2;
	else sum=n1/n2;
      //12-5*6/3/4+7*2*3=
	int w=0;
	while (sum>0) 
	{
	  p[w++]=sum%10+'0';
	  sum/=10;
	}

	int g=w-1;
	for (j=l+1;g>=0;j++,g--)
	 s[j]=p[g];
	 while (s[j+r-(l+w+1)]!='\0')
	 {
	 	s[j]=s[j+r-(l+w+1)];
	 	j++;
	 }
	 s[j]='\0';
}

int main()
{
	long long i,j,k;
	int pd=0;
	char c;
	i=0;
	while ((c=getchar())!=EOF)
	{
	 s[i++]=c;	
	}
	i=0;
	j=0;
	for (i=j=0;s[i]!='\0';i++)  //去除空格 
	{
		if (s[i]!=' ')
		{
			s[j++]=s[i];
		}
	}
	s[j]='\0';

	while (pd1(s)==1)  //处理乘号和除号 
	{
		cl1(s);
	}
  i=0;k=0;
  while (s[i]>='0'&&s[i]<='9') 
  {
  	k=k*10+s[i]-'0';
  	i++;
  }
  long long sum=0;
  sum=k;
  pd=2;
  while (s[i]!='\0')
  {
  	if (s[i]=='+'||s[i]=='-'||s[i]=='=')
  	{
  		if (pd==1||pd==0) {
  			if (pd==1)
  			{
  				sum=sum+k;
			  }
			  else sum=sum-k;
		  }
  		if (s[i]=='+')	pd=1;	
		if (s[i]=='-') pd=0;
		  k=0;
	  }
	 else k=k*10+s[i]-'0';
	 i++;
	   } 	
	   printf("%lld",sum);
	return 0;
}


