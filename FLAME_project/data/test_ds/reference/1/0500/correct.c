#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[105];
int samet(char c1,char c2)
{
	if(c1>=c2)
	return 0;
	if(isdigit(c1)&&isdigit(c2))
	return 1;
	else if(islower(c1)&&islower(c2))
	return 1;
	else if(isupper(c1)&&isupper(c2))
	return 1;
	else
	return 0; 
}
int main()
{
	scanf("%s",s);
	int i=0;
	for(i=0;i<strlen(s);i++)
	{
		if(i>0&&i<strlen(s)-1&&s[i]=='-'&&samet(s[i-1],s[i+1]))
			{
				char c;
				for(c=s[i-1]+1;c<=s[i+1]-1;c++)
					printf("%c",c);
			}
		else
			printf("%c",s[i]);
	}
	return 0;
}

