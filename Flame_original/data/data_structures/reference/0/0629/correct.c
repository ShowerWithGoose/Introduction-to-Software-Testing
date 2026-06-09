#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void insert(char a,char b)
{
char x=a;
if((a>='a'&&b<='z'&&a<b)||(a>='A'&&b<='Z'&&a<b)||(a>='0'&&b<='9'&&a<b))
	for(x=a+1;x<b;x++)
	printf("%c",x);
else printf("-");
}
int main()
{
	int i=0,j=0,str;
	char s[1000],*p,c[1000];
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
	if(s[i]!='-')	
		printf("%c",s[i]);
	if(s[i]=='-')
	insert(s[i-1],s[i+1]);
	
	}
	printf("\n");
return 0;
}

