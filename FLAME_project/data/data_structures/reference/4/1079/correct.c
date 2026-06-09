#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char word[300][20];
int hashtable[300];
char article[2000];
char temp;

void bubblesort(char a[][20], int n) {
	int flag = 0;
	char temp[20];

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1 - i; j++) {

			if (strcmp(a[j], a[j + 1]) > 0) {
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
				flag = 1;
			}
		}

		if (flag == 0) {
			break;
		}
	}

	return;


}

int main() {
	int len = 0, pos = 0, j = 0;
	FILE *fp = fopen("article.txt", "r");

	while ((temp = fgetc(fp)) != EOF) {
		article[len] = tolower(temp);
		len++;
	}

	article[len] = '\0';

	for (int i = 0; i < len; i++) {

		if (article[i] <= 'z' && article[i] >= 'a') {
			word[pos][j] = article[i];
			j++;
		} else if (isspace(article[i] ) || ispunct(article[i])) {
			j = 0;
			pos++;
		}
	}

	pos++;

	bubblesort(word, pos);
	j = 0;

	for (int i = 0; i < pos; i++) {

		j = i + 1;

		while (strcmp(word[i], word[j]) == 0) {
			word[j][0] = '\0';
			j++;
			hashtable[i]++;
		}

		i = j - 1;
	}

	for (int i = 0; i < pos; i++) {

		if (word[i][0] != '\0') {
			printf("%s %d\n", word[i], hashtable[i] + 1);
		}
	}

	fclose(fp);
	return 0;
}

