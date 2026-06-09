#define _CRT_SECURE_NO_WARNINGS 1;
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int s[100];

int main()
{
	int op = 0; int t = 0;
	while (~scanf("%d", &op)) {
		if (op == 1) {
			if (t < 100)
				scanf("%d", &s[t++]);
			else
				printf("error ");
			
		}
		else if (op == 0) {
			t--;
			if (t == -1)
			{
				printf("error ");
				t++;
			}
			else
			{
				printf("%d ", s[t]);
				s[t] = 0;
			}
			
		}
		else if (op == -1) {
			break;
		}
	}
	return 0;
}
