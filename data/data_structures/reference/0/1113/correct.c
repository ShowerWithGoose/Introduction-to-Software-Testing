#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int check(char a, char b)
{
	if (a >= '0' && a <= '9' && b >= '0' && b <= '9')return 1;
	else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')return 1;
	else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')return 1;
	else return 0;
}
int main()
{
	char str[1000];
	gets(str);
	int i = 0;
	while (str[i] != '\0') {
		for (; str[i] != '-'&&str[i]!='\0'; printf("%c", str[i]), i++);
		if (check(str[i-1],str[i+1]) && str[i] != '\0') {
			for (int j = 1; str[i - 1] + j < str[i + 1]; printf("%c", str[i - 1] + j), j++);
			i++;
		}
		else if (str[i] != '\0') printf("%c", str[i]), i++;
		else printf("%c", str[i]);
	}
	return 0;
}
