#include <stdio.h>
#include <string.h>

char str[1000000];

void squeez();
void work();

int main() {
	gets(str);
	squeez();
	work();
	return 0;
}

void squeez() {
	int i, j;
	for (i = j = 0; i < strlen(str); i++) {
		if (str[i] != ' ') {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}

void work() {
	int i, j = 0, t = 0;
	int tem = 0;
	int num[100];
	for (int x = 0; x < 100; x++) {
		num[x] = 0;
	}
	char ch[100];
	for (i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
		num[j] = num[j] * 10 + str[i] - '0';
	}
	for (; str[i] != '=';) {
		if (str[i] == '*') {
			tem = 0;
			for (i++; str[i] >= '0' && str[i] <= '9'; i++) {
				tem = tem * 10 + str[i] - '0';
			}
			num[j] = num[j] * tem;
		}
		if (str[i] == '/') {
			tem = 0;
			for (i++; str[i] >= '0' && str[i] <= '9'; i++) {
				tem = tem * 10 + str[i] - '0';
			}
			num[j] = num[j] / tem;
		}
		if (str[i] == '+' || str[i] == '-') {
			ch[t++] = str[i];
			tem = 0;
			for (i++; str[i] >= '0' && str[i] <= '9'; i++) {
				tem = tem * 10 + str[i] - '0';
			}
			num[++j] = tem;
		}
	}
	for (int i = 0; i < t; i++) {
		if (ch[i] == '+') {
			num[0] += num[i + 1];
		}
		if (ch[i] == '-') {
			num[0] -= num[i + 1];
		}
	}
	printf("%d", num[0]);
}
