#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000];
int a[1000];
int main()
{
	int i,j,y=0,sum=0,flag=0,count=0;
	char k;
	gets(s);
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
			s[j++]=s[i];
	}
	s[j]='\0';
	for(i=0;s[i]!='\0';i++)
	{
		if(isdigit(s[i]))
		{
			sum=sum*10+(s[i]-'0');
		}
		else
		{	
			if(flag==0)
			{
				a[y]=sum;
				flag=1;y++;
			}
			else
			{
				if(k=='*')
				{
					a[y-1]*=sum;
				}
				if(k=='/')
				{
					a[y-1]/=sum;
				}
				if(k=='+')
				{
					a[y]=sum;
					y++;
				}
				if(k=='-')
				{
					a[y]=-sum;
					y++;
				}
			}
			k=s[i];
			sum=0;
		}
	}
	for(i=0;i<y;i++)
	{
		count+=a[i];
	}
	printf("%d",count);
	return 0;
}





