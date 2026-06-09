#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int num[10000];
char sign[10000];
int numed[10000];

char *clear(char *str)
{
	char *processed = (char *)malloc(sizeof(char) * 10000);
	int len = strlen(str);
	int i, j = 0;
	for (i = 0; i < len; i++){
		if(str[i] != ' '){
			processed[j++] = str[i];
		}
	}
	processed[j] = '\0';
	return processed;
}

void getnumber(char *str, int i, int numlen) {
	char temp[10000];
	int step = 0;
	while(str[i] <= '9' && str[i] >= '0') {
		temp[step++] = str[i++];
	}
	int sum = 0, bit = 1;
	while(step >= 1) {
		sum += (temp[step - 1] - '0') * bit;
		bit *= 10;
		step --;
	}
	num[numlen] = sum;
	return ;
}

void output(int *num, char * str) {
	int sum = num[0];
	int i, j = 1;
	for (i = 0; str[i] != '='; i++) {
		if(str[i] == '*' || str[i] == '/')continue;
		if(str[i] == '+') sum += num[j ++];
		if(str[i] == '-') sum -= num[j ++];
	}
	printf("%d", sum);
	return ;
}

int main()
{
	char *str = (char *) malloc(sizeof(char) * 10000);
	gets(str);
	char *newstr = clear(str);
	int len = strlen(newstr);
	int numlen = 0;
	int i = 0;
	for (i = 0; i < len; i++) {
		if(newstr[i] <= '9' && newstr[i] >= '0'){
			getnumber(newstr, i, numlen);
			numlen ++;
			while (newstr[i] <= '9' && newstr[i] >='0') i++;
			i--;
		} 
		else {
			sign[numlen - 1] = newstr[i];
		}
	}
	int sum = 0;
	int j = 0;
	for (i = 0; i < numlen; i++) {
		sum = num[i];
		while(sign[i] == '*' || sign[i] == '/'){
			if( sign[i] == '*') sum *= num[i + 1];
			else sum /= num[i + 1];
			i ++;
		}
		numed[j++] = sum;
		sum = 0;
	}
	output(numed, sign);
	free(str); 
	free(newstr); 
	return 0;
}



