#include <stdio.h>
#include <string.h>

int main()
{
	char ch[1000],ch2[1000],chs[1000];
	int ch1[1000];
	int i=0,neg=0,j=0,k=0,m=0;
	gets(chs);
	for(j=0;i<strlen(chs);i++)
	{
		if(chs[i]!=' ')
			ch[j++]=chs[i];
	}
	if(ch[0]=='-')
	{
		neg=1;
		for(i=0;i<strlen(ch);i++)
		{
			ch[i]=ch[i+1];
		}
	} 
	for(i=0,j=0;i<strlen(ch);i++)
	{
	
		j=j*10+ch[i]-'0';
		if(ch[i+1]<'0'||ch[i+1]>'9')
		{
			ch1[k++]=j;
			ch2[m++]=ch[i+1];
			j=0;
			i++;
		}
	}
	if(neg==1)
	{
		ch1[0]=-ch1[0];
	}
	j=ch1[0];
	for(i=0;i<strlen(ch2);)
	{
		if(ch2[i]=='+')
		{
			if(ch2[i+1]=='+'||ch2[i+1]=='-'||ch2[i+1]=='=')
			{
				j+=ch1[i+1];
				i++;	
			} 
			else if(ch2[i+1]=='*'||ch2[i+1]=='/')
			{
				k=ch1[i+1];
				i++;
				while(ch2[i]=='*'||ch2[i]=='/')
				{
					if(ch2[i]=='*')
					{
						k*=ch1[i+1];
					}
					else 
					{
						k/=ch1[i+1];
					}
					i++;
				}
				j+=k;
			}
		}
		else if(ch2[i]=='-')
		{
			if(ch2[i+1]=='+'||ch2[i+1]=='-'||ch2[i+1]=='=')
			{
				j-=ch1[i+1];
				i++;	
			} 
			else if(ch2[i+1]=='*'||ch2[i+1]=='/')
			{
				k=ch1[i+1];
				i++;
				while(ch2[i]=='*'||ch2[i]=='/')
				{
					if(ch2[i]=='*')
					{
						k*=ch1[i+1];
					}
					else 
					{
						k/=ch1[i+1];
					}
					i++;
				}
				j-=k;
			}
		}
		else if(ch2[i]=='*')
		{
			j*=ch1[i+1];
			i++;
		}
		else if(ch2[i]=='/')
		{
			j/=ch1[i+1];
			i++;
		}
		else
		{
			printf("%d",j);
			return 0;
		}
	}
} 

