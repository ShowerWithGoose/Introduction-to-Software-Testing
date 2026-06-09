#pragma warning(disable : 4996) 
#include<stdio.h>
#include<string.h>
int theSame(char a, char b) {
	if (a<b&&a >= '0' && a <= '9' && b >= '0' && b <= '9')return 1;
	if (a<b&&a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')return 1;
	if (a<b&&a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')return 1;
	return 0;
}
int main() {
	char ch[10000], s[10000];
	scanf("%s", ch);
	int n = strlen(ch);
	int i,j=0,k;
	for (i = 0;i < n;i++) {
		if (ch[i] == '-' && theSame(ch[i - 1], ch[i + 1])) {
			for (k = 0;k < ch[i + 1] - ch[i - 1];k++) {
				s[j] = s[j-1] + 1;j++;
			}
			i = i + 1;j = j - 1;
		}
		s[j] = ch[i];j++;
	}
	s[j] = '\0';
	printf("%s", s);
return 0;
 }



