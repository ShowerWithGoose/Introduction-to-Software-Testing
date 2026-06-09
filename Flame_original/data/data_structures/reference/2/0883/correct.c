#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long long a[1000]={0},re=0;
	char c,s[1000];
	int i=1,sum=0;
	
	while(scanf("%c",&c)!=EOF)
	{
		if(c==' ')
		continue;
		else if(c>='0'&&c<='9')   //Êý×Ö 
		{
			sum*=10;
			sum+=c-'0';			
		}
		else       //¼Ó¼õ³Ë³ý 
		{
			if(s[i-1]=='*'||s[i-1]=='/')  //³Ë³ý 
			{
				if(s[i-1]=='*')
				a[i-1]*=sum;
				else
				a[i-1]/=sum;
				
				sum=0;
				s[i-1]=c;
			}			
			else  //¼Ó¼õ 
			{
				a[i]=sum;
				sum=0;
				s[i]=c;
				i++;
			}
			if(c=='=')
			break;
		}		
	}
	i--;
	sum=i;
	for(i=1;i<=sum;i++)
	{
		if(i==1) re+=a[1];
		if(s[i-1]=='+') re+=a[i];
		if(s[i-1]=='-') re-=a[i];
	}
	printf("%lld",re);
	return 0;
}

