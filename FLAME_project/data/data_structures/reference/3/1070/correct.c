#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000];
	scanf("%s", str);
	int len = strlen(str);
	int i = 0;
	if(str[i] == '0'){
		char *p = str + 2;
		while(*(p + i) == '0') i++;
		if( strlen(p + i) == 1){
			printf("%s", (p + i));
			printf("e%d", -(i + 1));
		}
		else {
			printf("%c.", *(p + i));
			printf("%s", (p + i + 1));
			printf("e%d", -(i + 1));
		}
		return 0;
	}
	while(*(str + i) != '.') i++;
	if(i == 1) printf("%se0", str);
	else {
		i = 0;
		int sum = 0;
		int flag = 0;
		for (i = 0; i < len; i++) {
			if(i == 1) printf(".");
			
			if(str[i] == '.') {
				flag = 1;
				continue;
			}
			if(flag == 0) {
				printf("%c", str[i]);
				sum++;
			}
			if(flag == 1) printf("%c", str[i]);
		}
		printf("e%d", (sum - 1));
	}
	return 0;
}

