
#include<stdio.h>
#include<string.h>
#include<math.h>

void Delete_space(char str[]) {
	char temp[1005];
	int i = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '=')
			temp[j++] = str[i++];
		else
			i++;
	}
	temp[j] = '\0';
	strcpy(str, temp);
}

void invert(char str[]) {
	int i, j, k;
	for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		k = str[i];
		str[i] = str[j];
		str[j] = k;
	}
}

void Calculate(char str[], int x) {
	char temp[1005];
	int i, j, num = 0, s2 = 0, p = 1, ret = 0, k = 0, count;
	for (i = x - 1; i >= 0 && str[i] >= '0' && str[i] <= '9'; i--) {
		num += (str[i] - '0') * p;
		p *= 10;
	}
	p = 1;
	for (count = x + 1; str[count] >= '0' && str[count] <= '9'&&str[count]!='\0'; count++);
	for (j = count - 1; str[j] >= '0' && str[j] <= '9'; j--) {
		s2 += (str[j] - '0') * p;
		p *= 10;
	}
	switch (str[x]) {
	case '*':ret = num * s2;
		break;
	case '/':ret = num / s2;
		break;
	}
	while (ret) {
		temp[k++] = ret % 10 + '0';
		ret /= 10;
	}
	temp[k] = '\0';
	invert(temp);
	strcat(temp, &str[count]);
	str[i + 1] = '\0';
	strcat(str, temp);
}

int main() {
	int count = 0, n = 0, ret = 0;
	char str[1005];
	gets(str);
	Delete_space(str);
	int i = 0;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '+' || str[i] == '-')
			count++;
		else if (str[i] == '*' || str[i] == '/')
			n++;
	}
	while (n > 0) {
		int i = abs(strchr(str, '*') - str), b = abs(strchr(str, '/') - str);
		Calculate(str, i < b ? i : b);
		n--;
	}
	if (!count)
		puts(str);
	else {
		while (count > 0) {
			int c = abs(strchr(str, '+') - str), d = abs(strchr(str, '-') - str);
			int x = c < d ? c : d;
			int i, j, num = 0, s2 = 0, p = 1, k = 0;
			for (i = x - 1; i >= 0 && str[i] >= '0' && str[i] <= '9'; i--) {
				num += (str[i] - '0') * p;
				p *= 10;
			}
			p = 1;
			for (k = x + 1; str[k] != '\0' && str[k] >= '0' && str[k] <= '9'; k++);
			for (j = k-1;str[j] >= '0' && str[j] <= '9'; j--) {
				s2 += (str[j] - '0') * p;
				p *= 10;
			}
			switch (str[x]) {
			case '+':ret += num + s2;
				break;
			case '-':ret += num - s2;
				break;
			}
			char temp[1005] = "0";
			strcat(temp, &str[k]);
			strcpy(str, temp);
			count--;
		}
		printf("%d\n", ret);
	}
	return 0;
}
