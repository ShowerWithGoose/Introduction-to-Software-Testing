#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct a {
	char name[30];
	int times;
} Struct;
Struct words[1000];

void bubble_sort(Struct arr[], int len) {
	int i, j;
	Struct temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main() {
	FILE *in;
	int i = 0, row = 0, flag = 0;
	char tmp[30] = {0}, a;
	if ((in = fopen("article.txt", "r")) == NULL)
		printf("ERROR!");
	else
		while (feof(in) == 0) {

			for (i = 0; isalpha(a = fgetc(in)); i++)
				tmp[i] = tolower(a);

			tmp[i] = 0;

			for (i = flag = 0; i < row; i++)
				if (strcmp(words[i].name, tmp) == 0) {
					words[i].times++;
					flag = 1;
					break;
				}

			if (!flag && tmp[0]) {
				strcpy(words[row++].name, tmp);
				words[row - 1].times = 1;
			}
		}

	bubble_sort(words, row);

	for (i = 0; i < row; i++)
		printf("%s %d\n", words[i].name, words[i].times);

	fclose(in);
	return 0;
}

