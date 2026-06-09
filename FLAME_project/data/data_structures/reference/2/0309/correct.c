#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void clear(char *str); 
int main()
{
	char s[1000], c[1000], t[1000];
	int in[1000];
	gets(s);
	clear(s);
	int L, p=0,k=0,l,sum=0;
	L=strlen(s);
	for(int i=0;i<L;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		{
			int j;
			for(j=p;j<i;j++)
				t[j-p]=s[j];
			c[k]=s[i];
			in[k]=atoi(t);
			k++;
			for(int m=0;m<i-p;m++)
				t[m]='\0';
			p=i+1;
		}
		else
			continue;
	}
	for(int i=0;i<k;i++)
	{
		if(c[i]=='*'||c[i]=='/')
		{
			if(c[i]=='*')
				in[i+1]=in[i]*in[i+1];
			if(c[i]=='/')
				in[i+1]=in[i]/in[i+1];
			in[i]=0;
		}
	}
	l=strlen(c);
	/*for(int i=0;i<l;i++)
		printf("%d ",in[i]);
	printf("\n");*/
	for(int i=0;i<l;i++)
		sum+=in[i];
	for(int i=0;i<l;i++)
	{
		if(c[i]=='-')
		{
			if(in[i+1]==0&&(c[i+1]=='*'||c[i+1]=='/'))
			{
				for(int j=i+2;j<l;j++)
				{
					if(in[j]!=0)
					{
						sum=sum-2*in[j];
						break;
					}
				}
			}
			else
				sum=sum-2*in[i+1];
		}
	}
	in[l]=sum;
	if(c[0]=='=')
	printf("%d\n",in[0]);
	else
	printf("%d\n",sum);
	return 0;
}
void clear(char *str)
{
	char *p=str;
	int i=0;
	while(*p)
	{
		if(*p!=' ')
			str[i++]=*p;
		p++;
	}
	str[i]='\0';
}



