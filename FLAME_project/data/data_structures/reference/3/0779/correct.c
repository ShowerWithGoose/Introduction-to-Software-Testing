#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>

void Deletepoint(char str[]) {
	char temp[110];
	int index = strchr(str, '.') - str;
	strcpy(temp, &str[index+1]);
	str[index] = '\0';
	strcat(str, temp);
}

int main() {
	char str[110], temp[110];
	gets(str);
	int len = strlen(str), index = strchr(str, '.') - str, p, s = 0;
	Deletepoint(str);
	for (int i = 0; str[i] == '0'; i++)
		s++;
	p = index - s;
	strcpy(temp, &str[s]);
	strcpy(str, &temp[1]);
	if (strlen(temp) > 1)
		temp[1] = '.';
	temp[2] = '\0';
	strcat(temp, str);
	printf("%se%d", temp, p - 1);
	return 0;
}
