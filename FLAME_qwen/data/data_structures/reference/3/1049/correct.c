#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s1[600];
	//char s2[600];
	int i=0,j=0;
	int count=0;//计数器 
	scanf("%s",s1);
	if(s1[0]=='-')//如果数字为负，则先把负号拿出来 
	{
		printf("-");
		j=0;
		i=1;
		do
		{
			s1[j]=s1[i];
			j++;
			i++;
		}while(s1[i]!='\0');
		s1[j]='\0';
	}
	
	if(s1[0]=='0')
	{
		count=1;
		for(i=2;s1[i]=='0';i++)
		{
			count++;
		}
		printf("%c",s1[i]);
		if(s1[i+1]!='\0') printf(".");
		while(s1[++i]!='\0')
		{
			printf("%c",s1[i]);
		}
		printf("e-%d\n",count);
	}
	else
	{
		for(i=0;(s1[i+1]!='.')&&(s1[i+1]!='\0');i++)//计数 
		{
			count++;
		}
		printf("%c.",s1[0]);
		for(i=1;s1[i]!='\0';i++)
		{
			if(s1[i]=='.') continue;
			printf("%c",s1[i]);
		}
		printf("e%d\n",count);
	}
	
	
	

return 0;
}


