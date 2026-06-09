
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
	int i, j, s1 = 0, s2 = 0, p = 1, s = 0, k = 0, m;
	for (i = x - 1; i >= 0 && str[i] >= '0' && str[i] <= '9'; i--) {
		s1 += (str[i] - '0') * p;
		p *= 10;
	}
	p = 1;
	for (m = x + 1; str[m] >= '0' && str[m] <= '9'&&str[m]!='\0'; m++);
	for (j = m - 1; str[j] >= '0' && str[j] <= '9'; j--) {
		s2 += (str[j] - '0') * p;
		p *= 10;
	}
	switch (str[x]) {
	case '*':s = s1 * s2;
		break;
	case '/':s = s1 / s2;
		break;
	}
	while (s) {
		temp[k++] = s % 10 + '0';
		s /= 10;
	}
	temp[k] = '\0';
	invert(temp);
	strcat(temp, &str[m]);
	str[i + 1] = '\0';
	strcat(str, temp);
}

int main() {
	int m = 0, n = 0, s = 0;
	char str[1005];
	gets(str);
	Delete_space(str);
	int i = 0;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '+' || str[i] == '-')
			m++;
		else if (str[i] == '*' || str[i] == '/')
			n++;
	}
	while (n > 0) {
		int a = abs(strchr(str, '*') - str), b = abs(strchr(str, '/') - str);
		Calculate(str, a < b ? a : b);
		n--;
	}
	if (!m)
		puts(str);
	else {
		while (m > 0) {
			int c = abs(strchr(str, '+') - str), d = abs(strchr(str, '-') - str);
			int x = c < d ? c : d;
			int i, j, s1 = 0, s2 = 0, p = 1, k = 0;
			for (i = x - 1; i >= 0 && str[i] >= '0' && str[i] <= '9'; i--) {
				s1 += (str[i] - '0') * p;
				p *= 10;
			}
			p = 1;
			for (k = x + 1; str[k] != '\0' && str[k] >= '0' && str[k] <= '9'; k++);
			for (j = k-1;str[j] >= '0' && str[j] <= '9'; j--) {
				s2 += (str[j] - '0') * p;
				p *= 10;
			}
			switch (str[x]) {
			case '+':s += s1 + s2;
				break;
			case '-':s += s1 - s2;
				break;
			}
			char temp[1005] = "0";
			strcat(temp, &str[k]);
			strcpy(str, temp);
			m--;
		}
		printf("%d\n", s);
	}
	return 0;
}
