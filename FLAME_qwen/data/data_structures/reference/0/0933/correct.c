#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char s[10000], temp;
int main()
{
	scanf("%s",s);
	int i, len = strlen(s);
	for (i = 0; i < len; ++i) {
		if (s[i] != '-') {
			printf("%c", s[i]);
		} else {
			if (s[i - 1] >= '0' && s[i + 1] <= '9' && s[i + 1] > s[i - 1]) {
				for (temp = s[i - 1] + 1; temp < s[i + 1]; ++temp)
				{
					printf("%c", temp);
				}
			}
			else if (s[i - 1] >= 'a' && s[i + 1] <= 'z' && s[i + 1] > s[i - 1]) {
				for (temp = s[i - 1] + 1; temp < s[i + 1]; ++temp)
				{
					printf("%c", temp);
				}
			}
			else if (s[i - 1] >= 'A' && s[i + 1] <= 'Z' && s[i + 1] > s[i - 1]) {
				for (temp = s[i - 1] + 1; temp < s[i + 1]; ++temp)
				{
					printf("%c", temp);
				}
			}
			else printf("%c", s[i]);
		}
	}
	return 0;
}



