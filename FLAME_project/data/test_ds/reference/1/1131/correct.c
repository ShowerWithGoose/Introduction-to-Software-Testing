#include <stdio.h>
#include <string.h>
int main() 
{ 
	char s[100], t[100];int i, j, k = 0, flag[100] = { 0 };
	gets(s);
	for (i = 0,j=0;s[i] != '\0';i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			flag[i] = 1;
		else if (s[i] >= 'a' && s[i] <= 'z')
			flag[i] = 2;
		else if (s[i] >= '0' && s[i] <= '9')
			flag[i] = 3;
	}
	for (i = 0, j = 0;s[i] != '\0';i++) {
		if (s[i] == '-') {
			if (flag[i - 1] == flag[i + 1]) {
				for (k = 1;k < s[i + 1] - s[i - 1];k++) {
					t[j] = s[i - 1] + k;
					j++;
				}
				i++;
			}
			
		}
		t[j++] = s[i];
	}
	t[j] = '\0';
	puts(t);
	return 0;
}



