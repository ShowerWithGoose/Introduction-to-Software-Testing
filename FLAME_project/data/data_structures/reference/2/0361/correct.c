#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
char s[100000];
char stack[100000];
char s1[100000]; 
struct info{
	int num;
	char c;
}calcu[100000];

int main (void)
{
	gets(s);
	int n=strlen(s)-1;
	int i,j,k;
	for(i=0,j=0;s[i]!='=';i++)
	{
		if(s[i]!=' ')
			s[j++]=s[i];
	}
	s[j]='\0';
	n=j;
	for(i=0,j=0,k=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			s1[j]=s[i];
			j++;
		}
		else if(s[i]=='*'||s[i]=='/')
		{
			s1[j]='.';
			j++;
			int cnt;
			for(cnt=k-1;cnt>=0;cnt--)
			{
				if(stack[cnt]=='+'||stack[cnt]=='-')
					break;
				else
				{
					s1[j]=stack[cnt];
					j++;
				}
			}
			k=++cnt;
			stack[k]=s[i];
			k++;
		}
		else if(s[i]=='+'||s[i]=='-')
		{
			s1[j]='.';
			j++;
			int cnt;
			for(cnt=k-1;cnt>=0;cnt--)
			{
				s1[j]=stack[cnt];
				j++;
			}
			k=++cnt;
			stack[k]=s[i];
			k++;
		}		
	}
	k--;
	for(k;k>=0;k--)
	{
		s1[j]=stack[k];
		j++;
	}
	n=j+1;
	s1[n]='\0' ;
	for(j;!(s1[j]>='0'&&s1[j]<='9');j--)
		s1[j]=s1[j-1];
	s1[j+1]='.';	
//	printf("%s\n",s1);
	int temp=0;
	int result=0;
	i=0;j=0;
	do{
		calcu[j].c=s1[i];
		if(calcu[j].c>='0'&&calcu[j].c<='9')
		{
			temp=temp*10+(calcu[j].c-'0');
			calcu[j].num=temp;
		}
		else if(calcu[j].c!='.'&&calcu[j].c!='\0')
		{
			if(calcu[j].c=='+')
				result=calcu[j-2].num+calcu[j-1].num;
			else if(calcu[j].c=='-')
				result=calcu[j-2].num-calcu[j-1].num;	
			else if(calcu[j].c=='*')
				result=calcu[j-2].num*calcu[j-1].num;	
			else if(calcu[j].c=='/')
				result=calcu[j-2].num/calcu[j-1].num;
															//	printf("%d\n",result); 
			j-=2;
			calcu[j].num=result;
			j++;		
		}
		else if(calcu[j].c=='.')
		{
			j++;
			temp=0;
		}
		i++;
	}while(s1[i]!='\0');
	
	printf("%d",calcu[--j].num);
	return 0;
}


