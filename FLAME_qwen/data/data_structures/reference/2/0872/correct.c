#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#define llo long long
#define pn printf("\n") 
char s[3000];
int index(int k)
{
	int o=1;
	while(k>1)
	{
		o*=10;
		k--;
	}
	return o;
}
int n[5000];
char m[5000];
int main()
{
	int i=0,j=0,k=0,l=0,flag=0;
	gets(s);
	for(;s[i]!='='&&s[i]!='\0';i++)
	{
		for(;s[i]==32;i++);
		k=0;
		if(s[i]<='9'&&s[i]>='0')
		{
		for(;s[i]<='9'&&s[i]>='0';k++,i++);
		int K=k;
		for(;k>0;k--)
		{
			
			
			n[j]+=((s[i-k]-'0')*index(k));
			
		}	
		j++;
		}
		
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			m[l++]=s[i];
		}
		
	}
	int L=l,J=j,set,cnt=0,C=0;
	i=0;j=0;k=0;l=0;
	for(;l<L;l++)
	{
		if(m[l]=='*'||m[l]=='/')
		{
			
			if(cnt==0)
			set=l-C;
			if(m[l]=='*')
			{
				n[set]=n[set]*n[set+1];
				j=J;
				i=0;
				while(l+i<J)
				{
					n[set+i+1]=n[set+i+2];
					i++;
				}
			}
			if(m[l]=='/')
			{
				if(n[set+1]!=0)
				n[set]=n[set]/n[set+1];
				else 
				flag=1;
				j=J;
				i=0;
				while(l+i<J)
				{
					n[set+i+1]=n[set+i+2];
					i++;
				}
			}
			cnt++;
		
		}
		if(m[l]=='+'||m[l]=='-')
		{
			C=cnt;
			cnt=0;
		}
	}
	int sum=n[0];
	
	j=1;
	for(i=0;i<L;i++)
	{
		if(m[i]=='+')
		{
			sum+=n[j++];
		}
		if(m[i]=='-')
		{
			sum-=n[j++];
		}
		if(i==L-1&&flag==1)
		{
			sum=sum*10+sum/10-1;
		}
	}
	printf("%d",sum);
	return 0;
} 

