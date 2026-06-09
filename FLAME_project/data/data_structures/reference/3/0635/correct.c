#include <stdio.h>
#include <string.h>
void Printfdown(char s[]);
void Printfup(char s[]);
char s0[50];
int main()
{
	gets(s0);
	if(s0[0]=='0') Printfdown(s0);
	else Printfup(s0);
	return 0;
 } 
void Printfdown(char s[])
{
	int i,e;
	for(i=2;s[i]=='0';i++);
	e=i-1;
	printf("%c",s[i]);
	if(s[i+1]!='\0')
	{printf(".");
	for(i++;s[i]!='\0';i++)
	printf("%c",s[i]);}
	printf("e-%d",e);
	return;
}
void Printfup(char s[])
{
	int i,e;
	e=strchr(s,'.')-s-1;
	printf("%c.",s[0]);
	for(i=1;s[i]!='\0';i++)
	{if(s[i]!='.')
	printf("%c",s[i]);
	}
	printf("e%d",e);
	return ;
}

