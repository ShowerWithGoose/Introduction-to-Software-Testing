#include <stdio.h>
#include<string.h>
int pd(char i,char j)
{
	if(i>='0'&&i<='9'&&j>='0'&&j<='9'&&i<j)
	{
		for(;i<j;i++)
		{
			printf("%c",i);
		}
		return 1;
	}
	else if(i>='a'&&i<='z'&&j>='a'&&j<='z'&&i<j)
	{
		for(;i<j;i++)
		{
			printf("%c",i);
		}
		return 1;
	}
	else if(i>='A'&&i<='Z'&&j>='A'&&j<='Z'&&i<j)
	{
		for(;i<j;i++)
		{
			printf("%c",i);
		}
		return 1;
	}
	return 0;
} 
int main() 
{
 char ch[1000];
 scanf("%s",ch);
 int i=0,j,m;
 for(;ch[i]!='\0';i++)
 {
 	for(;ch[i+1]!='\0'&&ch[i+1]!='-';i++)
 	{
 		printf("%c",ch[i]);
	}
	if(ch[i+1]=='-')
	{
		j=i+2;
		m=pd(ch[i],ch[j]);
		if(m==0)
		{
			printf("%c-",ch[i]);
			i++;
		}
		else
		{
			i=i+1;
		}
	}
 }
 if(ch[i-1]!='-')
 printf("%c",ch[i-1]);
 return 0;
}

