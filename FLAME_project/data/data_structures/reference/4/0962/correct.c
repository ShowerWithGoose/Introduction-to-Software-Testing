#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	char buf[45], word[200][45], s;
	fp = fopen("article.txt", "r");
	int n, i = 0, j, cnt = 0, ret = 0, flag = 0, num[30] = {0}, k, temp;
	while ((s = fgetc(fp)) != EOF) {
		if (ret == 0) {
			if (s >= 'a' && s <= 'z') {
				ret = 1;
				buf[cnt] = s;
				cnt++;
			} else if (s >= 'A' && s <= 'Z') {
				ret = 1;
				buf[cnt] = s - ('A' - 'a');
				cnt++;
			} else {
				continue;
			}
		} else {
			if (s >= 'a' && s <= 'z') {
				ret = 1;
				buf[cnt] = s;
				cnt++;
			} else if (s >= 'A' && s <= 'Z') {
				ret = 1;
				buf[cnt] = s - ('A' - 'a');
				cnt++;
			} else {
				buf[cnt] = '\0';
				for (j = 0; j < i; j++) {
					if (strcmp(word[j], buf) == 0) {
						num[j]++;
						flag = 1;
					}
				}
				if (flag == 0) {
					strcpy(word[i], buf);
					num[i]++;
					i++;

				}
				flag = 0;
				cnt = 0;
				ret = 0;
			}
		}
	}
	for (j = 0; j < i; j++) {
		for (k = j; k < i; k++) {
			if (strcmp(word[j], word[k]) > 0) {
				strcpy(buf, word[j]);
				strcpy(word[j], word[k]);
				strcpy(word[k], buf);
				temp = num[j];
				num[j] = num[k];
				num[k] = temp;
			}
		}
	}
	for (j = 0; j < i; j++) {
		printf("%s %d\n", word[j], num[j]);
	}
	fclose(fp);

	return 0;
}

