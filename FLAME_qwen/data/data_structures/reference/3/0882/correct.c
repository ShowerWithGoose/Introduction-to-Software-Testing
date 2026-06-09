#include<stdio.h>
char ch[135];
int main()
{
	
	scanf("%s",ch);
	if(ch[0]=='0')
	{
		if(ch[1]=='\0')
		{
			printf("0e0");
		}
		else
		{
			int i=2;
			while(ch[i]=='0') i++;
			printf("%c",ch[i]);
			int n;
			n=1-i;
			if(ch[i+1]!='\0')
			printf(".");
			while('0'<=ch[++i]&&ch[i]<='9') 
			printf("%c",ch[i]);
			printf("e%d",n);
		}
		
	}
	else
	{
		int i=0;
		printf("%c",ch[i]);
		if(ch[i+1]!='\0') printf(".");
		while(ch[++i]!='.'&&ch[i]!='\0') 
		printf("%c",ch[i]);
		int n;
		n=i-1;
		while('0'<=ch[++i]&&ch[i]<='9')
		printf("%c",ch[i]);
		printf("e%d",n);
	}
	return 0;
 } 

