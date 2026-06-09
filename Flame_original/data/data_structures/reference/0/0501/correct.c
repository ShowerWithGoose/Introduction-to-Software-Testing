#include <stdio.h>	
#include <string.h>
char input[100000];
int i;
int flag(char ch1,char ch2)
{
	if(ch1>='a'&&ch2>='a'&&ch1<='z'&&ch2<='z') return 1;
	else if(ch1>='A'&&ch2>='A'&&ch1<='Z'&&ch2<='Z') return 1;
	else if(ch1>='0'&&ch2>='0'&&ch1<='9'&&ch2<='9') return 1;
	return 0;
}
void overput(char ch3,char ch4)
{
	int j;
	for(j=1;ch3+j!=ch4;j++)
	{
		printf("%c",ch3+j);
	}
	return;
}
int main()
{
    int len;
	gets(input);
    len=strlen(input);
    printf("%c",input[0]);
	for(i=1;i<len;i++)
	{
		if(input[i]=='-'&&flag(input[i-1],input[i+1])) overput(input[i-1],input[i+1]);
		else printf("%c",input[i]);
	}
 } 

