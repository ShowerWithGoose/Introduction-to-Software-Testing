#include<stdio.h>
char s[10005];
int i,flag,sum;
int main()
{
	gets(s);
	if(s[1]=='\0')
	 {
	 	puts(s);
	 	return 0;
	 }
	if(s[0]=='0')
	 {
	 	
		for(i=1;s[i]=='0'||s[i]=='.';i++)
	 	 sum++;
	 	printf("%c",s[i]);
	 	if(s[i+1]!='\0') printf(".");
	 	i=i+1;
	 	for(;s[i]!='\0';i++)
	 	 printf("%c",s[i]);
	 	printf("e-%d",sum);
	 }
	else
	 {
	 	for(i=1;s[i]!='.';i++)
	 	 sum++;
	 	printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++)
		 if(s[i]!='.') printf("%c",s[i]);
		printf("e%d",sum);
	 }
	return 0;
}

