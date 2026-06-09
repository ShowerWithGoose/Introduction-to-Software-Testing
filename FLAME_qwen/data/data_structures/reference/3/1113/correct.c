#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char figure[105];
int main()
{
	gets(figure); int j, i;
	for ( i = 0; figure[i] != '\0' && figure[i] != '.'; i++);//Find point
	if (figure[0] == '0') {
		for ( j = 2; figure[j] == '0' && figure[j] != '\0'; j++);//Find first number
		printf("%c", figure[j]); if (figure[j + 1] != '\0') printf(".");
		for (int k = j + 1; figure[k] != '\0'; printf("%c", figure[k]), k++);
		printf("e-%d", j-1);
	}
	else {
		printf("%c", figure[0]); if (figure[1] != '\0') printf(".");
		for (int k = 1; k < i; printf("%c", figure[k]), k++);
		for (int k = i + 1; figure[k] != '\0'; printf("%c", figure[k]), k++);
		printf("e%d", i - 1);
	}
	return 0;
}
