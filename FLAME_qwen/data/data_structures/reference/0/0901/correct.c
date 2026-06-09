#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int pd(int a,int b)
{
	if(a>=97&&a<=122&&b>=97&&b<=122&&b>=a) return 1;
	else if(a>=65&&a<=90&&b>=65&&b<=90&&b>=a) return 1;
	else if(a>=48&&a<=57&&b>=48&&b<=57&&b>=a) return 1;
	else return 0;
}
int main()
{
	char str1[100],str2[100];
	int temp1,temp2,p[100]={0},t[50]={0};
	int sign=0,k=0,m,min;
	int begin=0,n=0;
	gets(str1);
	int p1=strlen(str1);
	for(int i=1;i<p1;i++)
	{
		if(str1[i]=='-')
		{
			k++;
			temp1=str1[i-1]-'0'+48;
			temp2=str1[i+1]-'0'+48;
			if(pd(temp1,temp2)==1)
			{
			    p[i]=1;
				m=0;
				min=temp2-temp1;
				for(int ii=sign;ii<sign+min-1;ii++)
				{
					str2[ii]=str1[i-1]+1+m;
					m++;//每个有效-所代表的字母数 
				}		
				t[k-1]=m;//第几个-所代表的字母数 
				sign+=m;//使得str2里没有间隙	
			}
		}
	}
	for(int i=0;i<p1;i++)
	{
		if(p[i]==0)
		{
			printf("%c",str1[i]);
		}
		else
		{
			for(int ii=begin;ii<begin+t[n];ii++)
			{
				printf("%c",str2[ii]);
		    }
		    begin+=t[n];
			n++; 
		}
	}
    return 0;
}


