#include<stdio.h>
#include<string.h>
#include<math.h>
int number[1000];
int integer[20];
char symbol[1000];
int sum;

int main()
{
	char s1[1000],s[1000];
	gets(s1);
	int i=0,j=0;
	for(i=0;i<strlen(s1)-1;i++)
	{
			if(s1[i]!=' ')
		{
			s[j]=s1[i];
			j++;
		}
		else
			continue;
	}
//	puts(s);
    int t,p,k=0,q=0;
    int num=0;
    j=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			integer[j]=s[i]-48;
			j++;
		}
		else
		{
			
			symbol[q]=s[i];
			q++;
			p=j;
			for(t=0;t<j;t++)
			{
				num+=integer[t]*pow(10,p-1);
				p--;
			}
			number[k]=num;
			k++;
			
				num=0;
				j=0;
				p=0;
		}	
	}
			p=j;
			for(t=0;t<j;t++)
			{
				num+=integer[t]*pow(10,p-1);
				p--;
			}
			number[k]=num;
			k++;
			
				num=0;
				j=0;
				p=0;
				
	int add=0;
	char c;
	i=0;
	sum=number[0];
	for(;i<strlen(symbol)&&strlen(symbol)>0;i++)
	{
		if(symbol[i]=='+'||symbol[i]=='-')
		{
			if(symbol[i+1]!='*'&&symbol[i+1]!='/')
			{
				if(symbol[i]=='+')
				sum+=number[i+1];
				else if(symbol[i]=='-')
				sum-=number[i+1];
			}
			else if(symbol[i+1]=='*'||symbol[i+1]=='/')
			{
				add=number[i+1];
				c=symbol[i];
				i=i+1;
				for(;symbol[i]=='*'||symbol[i]=='/';i++) 
				{
					if(symbol[i]=='*')
					add*=number[i+1];
					else
					add/=number[i+1];
				}
				if(c=='+')
				sum+=add;
				else if(c=='-')
				sum-=add;
				add=0;
				i=i-1;
			}
		}
		else if(symbol[i]=='*'||symbol[i]=='/')
		{
			add=number[i]; 
			for(;symbol[i]=='*'||symbol[i]=='/';i++) 
				{
					if(symbol[i]=='*')
					add*=number[i+1];
					else
					add/=number[i+1];
				}
			sum=add;
			i=i-1;
		}
	}	
	printf("%d",sum);			
		
	return 0;			
}

