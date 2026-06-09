#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int Judge(char *,int );
void Expand(char *,int );
char s[105];
int main()
{
	int i=0;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
	if(s[i+1]=='-'&&Judge(s,i))
	{
	Expand(s,i);
	i=i+1;
	}
	else printf("%c",s[i]);
    }
	return 0;
 } 
int Judge(char str[],int i)
{
	    int ans=0;char a,b;
        a=str[i];
		b=str[i+2];
		if(a<='z'&&a>='a'&&b<='z'&&b>='a'&&b-a>1) ans=1;
		else if(a<='Z'&&a>='A'&&b<='Z'&&b>='A'&&b-a>1) ans=1;
		else if(isdigit(a)&&isdigit(b)&&b-a>1) ans=1;
		else return 0;
	return ans;
}
void Expand(char str[],int i)
{
	char c;
	printf("%c",str[i]);
	c=str[i]+1;
	while(c<str[i+2])
	{
	printf("%c",c);
	c=c+1;
	}
    return;
}

