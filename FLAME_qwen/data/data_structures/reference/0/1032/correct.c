#include<stdio.h>
#include<string.h>
void expand(char c,char d);
int judge(char a,char b);

int main()
{
	int a=0,i;
	char s[100];
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		a=judge(s[i-1],s[i+1]);
		else
		printf("%c",s[i]);
		if(a==0&&s[i]=='-')
		printf("-");
		if(a==1)
		{
			expand(s[i-1],s[i+1]);
			a=0;
		}
		
	}
	
	return 0;
	
}
int judge(char a,char b)
{
	if((a>='a'&&a<='z'&&b-a<=26&&b-a>0)||(a>='A'&&a<='Z'&&b-a<=26&&b-a>0)||(a>='0'&&a<='9'&&b-a<=9&&b-a>0))

	return 1;
	return 0;
}
void expand(char c,char d)
{
	int x=d-c;
	int k=1;
	for(k;k<x;k++)
	printf("%c",c+k);
	
}

