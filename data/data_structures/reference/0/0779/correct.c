#include<stdio.h>
#include<string.h>

void expand(char str[]);

int isa(char a) {
	if (a >= 'a' && a <= 'z')
		return 1;
	else if (a >= 'A' && a <= 'Z')
		return 2;
	else if (a >= '0' && a <= '9')
		return 3;
	else
		return 0;
}

void create(char a, char b,char flag[]) {
	int i;
	for (i = 0; i < b - a-1; i++)
		flag[i] = a + i + 1;
	flag[i] = '\0';
}

int main() {
	char str[1005];
	gets(str);
	expand(str);
	puts(str);
	return 0;
}

void expand(char str[]) {
	char start, end;
	for (int i = 1; str[i] != '\0'; i++)
		if (str[i] == '-' && str[i - 1] < str[i + 1]&&isa(str[i-1])!=0)
			if (isa(str[i-1])==isa(str[i+1])) {
				start = str[i - 1], end = str[i + 1];
				char flag[1005];
				create(start, end, flag);
				strcat(flag,&str[i + 1]);
				str[i] = '\0';
				strcat(str, flag);
			}
}




