#include<stdio.h>
#include<string.h>
int cmp(char b,char t)
{
	if(((b >= 'a' && b <= 'z')&&(t >= 'a' && t <= 'z'))||(b >= 'A' && b <= 'Z')&&(t >= 'A' && t <= 'Z')||(b >= '0' && b <= '9')&&(t >= '0' && t <= '9'))
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	char s[100],p[200];
	char ch;
	int i,j,l;
	scanf("%s",&s);
	l = strlen(s);
	for(i = 0 ;i < l ;i ++)
	{
		if(s[i] == '-'&&cmp(s[i-1],s[i+1])&&(s[i-1]<s[i+1]))
		{
			for(ch = s[i-1]+1;ch <= s[i+1] ;ch++)
				p[j++] = ch;
			i++;
		}
		else
			p[j++] = s[i];
	}
	p[j] = '\0';
	printf("%s",p);
}

