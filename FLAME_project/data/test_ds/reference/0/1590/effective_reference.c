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
	char s[100],t[200];
	char l;
	int i,cnt,p;
	scanf("%s",&s);
	p = strlen(s);
	for(i = 0 ;i < p ;i ++)
	{
		if(s[i] == '-'&&cmp(s[i-1],s[i+1])&&(s[i-1]<s[i+1]))
		{
			for(l = s[i-1]+1;l <= s[i+1] ;l++)
				t[cnt++] = l;
			i++;
		}
		else
			t[cnt++] = s[i];
	}
	t[cnt] = '\0';
	printf("%s",t);
}

