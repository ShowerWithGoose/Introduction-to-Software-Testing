#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],s1[1000],flag=0,flag1=0,zhi=0,j=2,dian=0;
	int len,i=0;
	gets(s);
	len=strlen(s);
	while(i<len)
	{
		if(s[i]=='.')
		{
			flag++; dian=i;
			if(i==1) flag1++;
		}
		i++;
	}
	i=2;
	if(flag==0)
	{
		s1[0]=s[0]; 
		if(s[1]=='\0') printf("%ce0",s[0]);
		else
		{
			s1[1]='.';
			while(i<=len)
			{
				s1[i]=s[i-1];
				i++;
			}
			printf("%se%d",s1,len-1);
		}
	}
	i=2;
	if(flag==1)
	{
		if(flag1==1)
		{
			while(s[i]=='0')
			{
				i++;
			}
			zhi=i-1;
			s1[0]=s[i];
			if(i==len-1) printf("%ce-%d",s1[0],zhi);
			else if(s[0]!='0')
			{
				printf("%se0",s);
			}
			else
			{
				s1[1]='.';
				while(i<len-1)
				{
					s1[j]=s[i+1];
					i++; j++;
				}
				printf("%se-%d",s1,zhi);
			}
		}
		if(flag1==0)
		{
		
			s1[0]=s[0]; s1[1]='.';
			while(i<dian+1)
			{
				s1[i]=s[i-1];
				i++;
			}
			while(i<len)
			{
				s1[i]=s[i];
				i++;
			}
			printf("%se%d",s1,dian-1);
		}
	}
	return 0;
} 

