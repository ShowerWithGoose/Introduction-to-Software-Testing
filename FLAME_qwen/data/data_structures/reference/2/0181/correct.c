#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char symbol[100];
int number[100];
char line[1024];
char temp[10];
char op;
int place = 0;
int i = 0;
int a = 0;
int b = 1;
int x, y;

int ati(char a[]) {
	int i = 0, l, b = 0;
	l = strlen(a) - 1;
	for (i = 0; i <= l; i++) {
		b *= 10;
		b += (a[i] - '0');
	}
	return b;
}
void PRUGE(char line[]) {
	int i, k = -1;

	for (i = 0; i < (int)strlen(line); i++)
		if (line[i] == ' ')
			k++;
		else
			line[i - k - 1] = line[i];
	line[strlen(line) - k - 1] = '\0';
}
int cal(int x, int node2, int y) {
	int b = 0;
	if (symbol[node2 - 1] == '+')
		b = x + y;
	else if (symbol[node2 - 1] == '-')
		b = x - y;
	else if (symbol[node2 - 1] == '*')
		b = x * y;
	else if (symbol[node2 - 1] == '/')
		b = x / y;
	return b;
}
int symbolcompare(int node2) {
	if ((op == '*' || op == '/') && (symbol[node2 - 1] == '+' || symbol[node2 - 1] == '-' || symbol[node2 - 1] == '='))
		return 1;
	else if ((op == '+' || op == '-') && (symbol[node2 - 1] == '='))
		return 1;
	else if ((op == '=') && (symbol[node2 - 1] == '='))
		return 1;
	return 0;
}

int main() {
	symbol[0] = '=';
	gets(line);
	PRUGE(line);

	while (line[place] != '\0') {
		i = 0;
		memset(temp, 0, sizeof(temp));
		if (line[place] >= '0' && line[place] <= '9') {
			while (line[place] >= '0' && line[place] <= '9') {
				temp[i++] = line[place++];
			}
			number[a++] = ati(temp);

		} else {
			op = line[place++];

			while (1) {
				if (symbolcompare(b) == 1) {
					symbol[b++] = op;
					break;
				}

				a -= 2;
				x = number[a];
				y = number[a + 1];


				number[a] = number[a + 1] = 0;
				number[a++] = cal(x, b, y);

				b--;

			}
		}
	}

	printf("%d", number[0]);
	return 0;
}



