#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char str[100];
char news[200];

int main()
{
	scanf("%s", str);
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '-') {
			char pre = str[i - 1];
			char last = str[i + 1];
			if (pre >= '0' && pre <= '9' && last >= '0' && last <= '9') {
				char temp = pre + 1;
				while (temp < last) news[j++] = temp++;
			}
			else if (pre >= 'a' && pre <= 'z' && last >= 'a' && last <= 'z') {
				char temp = pre + 1;
				while (temp < last) {
					news[j++] = temp++;
				}
			}
			else if (pre >= 'A' && pre <= 'Z' && last >= 'A' && last <= 'Z') {
				char temp = pre + 1;
				while (temp < last) news[j++] = temp++;
			}
			else {
				news[j++] = str[i];
			}
		}
		else {
			news[j++] = str[i];
		}
	}
	news[j] = '\0';
	printf("%s", news);

	return 0;
}
