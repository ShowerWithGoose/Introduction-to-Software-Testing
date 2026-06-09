#include<stdio.h>
#include<string.h>
char s[200];
int i, j, ls, bj, cnt;
int main()
{
	scanf("%s", s+1); ls = strlen(s+1);
	for (i = 1; i <= ls; i++) 
		if (s[i] == '.') bj = i;
	int flag = 0;
	for (i = bj+1; i <= ls; i++) 
		if (s[i] != '0') flag = 1;
	if (s[1] == '0' && bj == 2) {
		i = 3; cnt = 1;
		while (s[i] == '0' && i <= ls) {
			i++; cnt++;
		}
		if (i == ls) printf("%ce-%d\n", s[i], cnt);
		else {
			printf("%c.", s[i]);
			for (j = i+1; j <= ls; j++) printf("%c", s[j]);
			printf("e-%d\n", cnt);
		}
	}
	else {
		if (!flag&&bj == 2) {printf("%ce0\n", s[1]); return 0;}
		printf("%c.", s[1]);
		cnt = bj-2;
		for (i = 2; i <= ls; i++) {
			if (s[i] != '.') printf("%c", s[i]);
		}
		printf("e%d\n", cnt);
	}
	return 0;
}

