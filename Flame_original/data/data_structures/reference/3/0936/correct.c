#include<stdio.h>
#include<string.h>
char s[107];
int main() {
	scanf("%s", s);
	int l, d, t;
	l = strlen(s);
	for (int i = 0; i <= l; i++) {
		if (s[i] == '.') {
			d = i;
			break;
		}
	}
	if (d == 1 && s[0] != '0') {
		for(int i=0;i<l;i++){
			printf("%c",s[i]);
		}
		printf("e0");
	} else if (d == 1 && s[0] == '0') {
		for (int i = 2; i <= l; i++) {
			if (s[i] != '0') {
				t = i;
				break;
			}
		}
		if (t == l-1) {
			printf("%c", s[t]);
			printf("e-%d", t - d);
		} else {
			printf("%c.", s[t]);
			for (int i = t + 1; i < l; i++) {
				printf("%c", s[i]);
			}
			printf("e-%d", t - d);
		}
	} else {
		printf("%c.", s[0]);
		for (int i = 1; i < d; i++) {
			printf("%c", s[i]);
		}
		for (int i = d + 1; i < l; i++) {
			printf("%c", s[i]);
		}
		printf("e%d", d - 1);
	}
	return 0;
}



