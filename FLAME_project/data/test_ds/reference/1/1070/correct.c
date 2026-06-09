#include<stdio.h>
#include<string.h>

int judge(char *str, int i) {
	if(str[i - 1] == '-' || str[i + 1] == '-') return 0;
	if(str[i - 1] > str[i + 1]) return 0;
	if((str[i + 1] <= '9' && str[i - 1] >= '0')||(str[i + 1] <= 'Z' && str[i - 1] >= 'A')||(str[i + 1] <= 'z' && str[i - 1] >= 'a'))
	return 1;
}

int main()
{
	char str[10000];
	gets(str);
	int i ;
	int len = strlen(str);
	for (i = 0; str[i] != '\0'; i++) {
		if(i == 0 || i == (len - 1)) printf("%c", str[i]);
		else if(str[i] == '-' && judge(str, i) == 1) {
			char temp = str[i - 1] + 1;
			for (temp = str[i - 1] + 1; temp < str[i + 1]; temp++) printf("%c", temp);
		}
		else printf("%c", str[i]);
    }
	return 0;
} 



