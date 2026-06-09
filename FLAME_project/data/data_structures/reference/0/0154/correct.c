#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void expand(char a, char b)
{
	a++;
	for (; a < b; a++)
		printf("%c", a);
}
int main()
{
	char s[100000];
	scanf("%s", s);
	int len = strlen(s),i=0;
	if (s[0] == '-') {
		printf("-"); i++;
	}
	for (; i < len; i++)
	{
		if (s[i] == '-')
		{
			if ((s[i-1]>='0'&&s[i-1]<=s[i+1]&&s[i+1]<='9')|| (s[i - 1] >= 'a' && s[i - 1] <= s[i + 1] && s[i + 1] <= 'z')|| (s[i - 1] >= 'A' && s[i - 1] <= s[i + 1] && s[i + 1] <= 'Z'))
				expand(s[i - 1], s[i + 1]);
			else printf("-");
		}
		else printf("%c", s[i]);
	}


	return 0;
}
