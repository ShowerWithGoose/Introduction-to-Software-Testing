#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char num[200];

int main()
{
	scanf("%s", num);
	int n = strlen(num);
	int zheng = 0, xiao = 1;
	int temp = 0, flag = 0;
	if (num[0] != '0') {
		for (int i = 0; num[i] != '.'; i++) {
			zheng++;
		}
		printf("%c.", num[0]);
		for (int i = 1; i < n; i++) {
			if(num[i]!='.')
				printf("%c", num[i]);
		}
		printf("e%d", zheng - 1);
	}
	else {
		for (int i = 2; num[i] == '0'; i++) {
			xiao++;
			temp = i;
		}
		for (int i = temp + 1; i < n; i++) {
			if (i == temp + 1 && i != n - 1) {
				printf("%c.", num[i]);
			}
			else {
				printf("%c", num[i]);
			}
		}
		printf("e%d", -xiao);
	}
	printf("\n");

	return 0;
}
