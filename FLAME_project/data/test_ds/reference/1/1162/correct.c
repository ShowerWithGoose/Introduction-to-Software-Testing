#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h> 
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
char s[111111], n;
int check(char p) {
	if(p >= '0' && p <= '9') return 1;
	if(p >= 'a' && p <= 'z') return 2;
	if(p >= 'A' && p <= 'Z') return 3;
}
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	int i, j;
	for(i = 1; i <= n;i++) {
		if(s[i] != '-') printf("%c", s[i]);
		if(s[i] == '-') {
			//printf("%d %d\n", check(s[i - 1]), check(s[j + 1]));
			if(s[i - 1] >= s[i + 1]) {
				printf("-"); continue;
			}
			if(check(s[i - 1]) == check(s[i + 1])) {
				for(j = s[i - 1] + 1; j <= s[i + 1] - 1; j++) {
					char w = j; printf("%c", w);
				}
			}
			else printf("-");
		}
	}
	return 0;
}

