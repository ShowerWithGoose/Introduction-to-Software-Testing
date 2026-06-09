#include<stdio.h>
#include<string.h>
char s[100];
int a[100];
int i, j, point = 0, xiaoshu, flag;
int main()
{
	gets(s);
	int len = strlen(s);
	for(i = 0, j = 0; i < len; i++)
	{
		if(s[i] == '.') point = 1;
		if(point == 1) xiaoshu++;
		if(s[i] != '0' && s[i] != '.') flag = 1;
		if(flag == 1 && s[i] != '.')
		{
			a[j++] = s[i] - '0';
		}
	}

	for(i = 0; i < j; i++)
	{
		if(i == 1) printf(".%d", a[i]);
		else printf("%d", a[i]);
	}
	printf("e%d", j - xiaoshu);
	return 0;
}

