#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h> 
#define int long long
char s[11111];
int len1, cnt;
signed main() {
	scanf("%s", s + 1); int len1 = strlen(s + 1);
	if(s[1] == '0' && s[2] == '.') {
		int i = 3;
		while(s[i] == '0') i++, cnt++;
		if(i == len1) {
			printf("%ce%d", s[i], -cnt - 1);
		}
		else  {
			printf("%c.", s[i]);
			i++; while(i <= len1) {
				printf("%c", s[i++]);
			} 
			printf("e%d",-cnt - 1);
		}
		return 0;
	}
	if(len1 == 1) {
		printf("%ce0", s[1]); return 0;
	}
	int i = 1;
	while(s[i] != '.') cnt++, i++;
	printf("%c.", s[1]);
	for(i = 2; i <= len1; i++) 
		if(s[i] != '.')printf("%c", s[i]);
	printf("e%d", cnt - 1);
	return 0;
}

