#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int isOperator(int n, char* s)
{
	return (*(s + n) >= 42 && *(s + n) <= 47);
}
int power(int n)
{
	int ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= 10;
	}
	return ans;
}
int number(int digit, int location, char* s)
{
	int ans = 0;
	for (int i = digit - 1; i >= 0; i--) {
		ans += power(i) * (*(s + location + digit - 1 - i) - '0');
	}
	return ans;
}
int operator(int n, char* s)
{
	if (*(s + n) == '+')
		return 1;
	else if (*(s + n) == '-')
		return 2;
	else if (*(s + n) == '*')
		return 3;
	else
		return 4;
}
int main()
{
	char s[100] = { 0 };
	int t[100] = { 0 };//to store the numbers in the string
	int p[100] = { 0 }, a = 1;//to store the location and the number of the operators
	p[0] = -1;
	int r[100] = { 0 };//to store the final numbers
	memset(r, 100, 1);
	gets(s);
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';//delete the spaces in the string
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (isOperator(i, s)) {
			p[a] = i;
			a++;
		}
	}
	p[a] = l - 1;
	for (int i = 0; i < a; i++) {
		t[i] = number(p[i + 1] - p[i] - 1, p[i] + 1, s);
	}
	int b = 0;
	r[0] = t[0];
	for (int i = 1; i < a; i++) {
		switch (operator(p[i], s))
		{
		case 1:b++; r[b] = t[i]; break;
		case 2:b++; r[b] = -t[i]; break;
		case 3:r[b] *= t[i]; break;
		case 4:r[b] /= t[i]; break;
		}
	}
	int ans = 0;
	for (int i = 0; i <= b; i++) {
		ans += r[i];
	}
	printf("%d", ans);
	return 0;
}

