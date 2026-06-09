#include<stdio.h>
#include<string.h>

char s[1000];
int sum;

int main()
{
	char c;
	int len,i,flag=0,point;
	scanf("%s",s);
	len=strlen(s);
	if(len==1)printf("%ce0",s[0]);
	else if(s[0]=='0')
	{
		for(i=2;s[i]=='0';i++); 
		point=i-1;
		printf("%c",s[i]);
		i++;
		if(s[i]!='\0')
		{
			printf(".");
			for(;i<len;i++)
				printf("%c",s[i]);
		}
		printf("e-%d",point);
	}
	else
	{	
		printf("%c.",s[0]);
		for(i=1;i<len;i++)
		{
			if(s[i]=='.')flag=1;
			if(flag==0)sum++;
			if(s[i]!='.')printf("%c",s[i]);
		}
		printf("e%d",sum);
	}
	return 0;
}

