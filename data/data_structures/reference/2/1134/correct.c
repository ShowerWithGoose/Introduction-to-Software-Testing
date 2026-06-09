#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
	char num1[10000],*p;
	int temp=0,size=0,num2[10000],flag=0;
	gets(num1);
	p=num1;
	while(*p!='=')
	{
		if(*p==' ') p+=sizeof(char);
		else if(*p>='0'&&*p<='9')
		{
			temp=10*temp+(*p-'0');
			p+=sizeof(char);
		}
		else if(*p=='+')
		{
			if(!flag)
			{
				num2[size++]=temp;
				temp=0;
			}
			else {
				num2[size++]=-(temp);
				temp=0;
			}
			flag=0;
			p+=sizeof(char);
			
		}
		else if(*p=='-')
		{
			if(!flag)
			{
				num2[size++]=temp;
				temp=0;
			}
			else {
				num2[size++]=-(temp);
				temp=0;
			}
			
			p+=sizeof(char);
			flag=1;
		}
		else if(*p=='*')
		{
			int mid=0;
			while(*p<'0'||*p>'9')
			p+=sizeof(char);
			
			while(*p>='0'&&*p<='9')
			{
			mid=10*mid+(*p-'0');
				p+=sizeof(char);
				
			}
			
			temp*=mid;
			
		}
		else if(*p=='/')
		{
			int mid=0;
			
			while(*p<'0'||*p>'9')
			p+=sizeof(char);
			
			while(*p>='0'&&*p<='9')
			{	
			mid=10*mid+(*p-'0');
				p+=sizeof(char);
			
			}
			temp/=mid;
			
		}
	}
	if(!flag)
	{
		num2[size++]=temp;
		temp=0;
	}
	else {
		num2[size++]=-(temp);
		temp=0;
	}
	
	int sum=0;
	for(int i=0;i<size;i++)
	sum+=num2[i];
	
	printf("%d",sum);
	
	
	
	
	return 0;
}

