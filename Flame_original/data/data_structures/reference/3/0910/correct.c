#include<stdio.h>
#include<string.h>
int main()
{
	char s[10000];
	gets(s);
	if(s[0]=='0')
	{
		int a=1;
		while(s[a+1]=='0')
	{a++;
	}
		if(s[a+2]=='\0')
		{
			printf("%c",s[a+1]);
			printf("e-%d",a);
		}
		else
		{
			printf("%c.",s[a+1]);
			for(int b=a+2;s[b]!='\0';b++)
			printf("%c",s[b]);
			printf("e-%d",a);
		}
	 }
	 else
	 {
	 	printf("%c",s[0]);
	 	int a=0;
	 	while(s[a+1]!='.'&&s[a+1]!='\0')
	 	{
	 		a++;
		}
		 if(s[a+1]=='.')
		 {
		 	printf(".");
		 	for(int b=1;s[b]!='.';b++)
		 	printf("%c",s[b]);
		 	for(int b=a+2;s[b]!='\0';b++)
		 	printf("%c",s[b]);

		 }
		 else
		 {
		 	int c=strlen(s)-1;
		 	while(s[c]=='0')
		 	{
		 		c--;
			 }

		 	printf(".");
		 	for(int b=1;b<=c;b++)
		 	{
		 		printf("%c",s[b]);
			}


		 }	printf("e%d",a);
	 }
	 return 0;


}

