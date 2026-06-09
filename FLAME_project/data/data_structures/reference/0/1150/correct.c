#include<stdio.h>
#include<string.h> 
char s[100002];
int jud(char a) {
	if(a >= 'a' && a <= 'z') return 0;
	if(a >= 'A' && a <= 'Z') return 1;
	if(a >= '0' && a <= '9') return 2;
}
int main() {
	scanf("%s", s);
	int i, l = strlen(s);
	char j;
	for(i = 0; i < l; ++ i) {
		if(s[i] == '-' && jud(s[i - 1]) == jud(s[i + 1])) {
			for(j = s[i - 1] + 1; j < s[i + 1]; ++ j)
				printf("%c", j);
		}
		else printf("%c", s[i]);
	}
	return 0;
}



