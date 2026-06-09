#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[120];
void f(int);
int truee(int);
int main()
{
	int i=0;
	gets(s);
	while(s[i]!='\0')
	{	
		if((truee(i)==1)&&(s[i]=='-')&&(s[i-1]<s[i+1]))
		{
			f(i);
		}
		else
		printf("%c",s[i]);
		i++;
	}
	return 0;
}

int truee(int i)
{
	if(s[i-1]>='A'&&s[i+1]<='Z')
	return 1;
	if(s[i-1]>='a'&&s[i+1]<='z')
	return 1;
	if(s[i-1]>='0'&&s[i+1]<='9')
	return 1;
	return 0;
}

void f(int i)
{
	char k=s[i-1]+1;
	while(k!=s[i+1])
	{
		printf("%c",k);
		k++;
	}
}

