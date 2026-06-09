#include <stdio.h>
#include <string.h>

int f_scanf(FILE *in, char a[]) {
	char c;
	int i = 0, flag = 0;

	while (1) {
		if ((c = fgetc(in)) != EOF) {
			flag = 0;

			if (c >= 'a' && c <= 'z') {
				a[i++] = c;
				flag = 1;
			}

			if (c >= 'A' && c <= 'Z') {
				a[i++] = c + 'a' - 'A';
				flag = 1;
			}
			if (flag == 0 && i == 0)
				return 1;

			if (flag == 0)
				return 0;
		} else {
			return -1;
		}

	}
}

struct word {
	char a[15];
	int n;
};

int main() {
	int f;
	struct word x[2000];

	for (int i = 0; i < 2000; i++)

		x[i].n = 0;
	char y[15];
	int cnt = 0, flag;
	FILE *in;
	in = fopen("article.txt", "r");

	while ((f = f_scanf(in, y) ) != -1) {
		if (f == 1)
			continue;
		flag = 0;

		if (cnt == 0) {
			strcpy(x[0].a, y);
			x[0].n++;
			cnt++;
			continue;
		}

		for (int i = 0; i < cnt; i++) {

			if (strcmp(x[i].a, y) == 0) {
				x[i].n++;
				flag = 1;

				for (int i = 0; i < 15; i++)

					y[i] = '\0';
				break;
			}
		}

		if (flag == 0) {
			for (int i = 0; i < cnt; i++) {

				if (strcmp(y, x[i].a) < 0) {
					for (int j = cnt; j > i; j--) {

						x[j] = x[j - 1];
					}

					strcpy(x[i].a, y);
					x[i].n = 1;
					cnt++;

					for (int k = 0; k < 15; k++)

						y[k] = '\0';
					break;
				}
			}


			strcpy(x[cnt].a, y);
			x[cnt].n = 1;
			cnt++;

			for (int k = 0; k < 15; k++)

				y[k] = '\0';
		}
	}

//zhan
	flag = 0;

	if (cnt == 0) {
		strcpy(x[0].a, y);
		x[0].n++;
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {

		if (strcmp(x[i].a, y) == 0) {
			x[i].n++;
			flag = 1;

			for (int i = 0; i < 15; i++)

				y[i] = '\0';
			break;
		}
	}

	if (flag == 0) {
		for (int i = 0; i < cnt; i++) {

			if (strcmp(y, x[i].a) < 0) {
				for (int j = cnt; j > i; j--) {

					x[j] = x[j - 1];
				}

				strcpy(x[i].a, y);
				x[i].n = 1;
				cnt++;

				for (int k = 0; k < 15; k++)

					y[k] = '\0';
				break;
			}
		}


		strcpy(x[cnt].a, y);
		x[cnt].n = 1;
		cnt++;

		for (int k = 0; k < 15; k++)

			y[k] = '\0';
	}

//zhan
	for (int i = 0; i < cnt ; i++) {

		flag = 0;

		for (int j = 0; j < 15; j++)

			if (x[i].a[j] != '\0') {
				flag = 1;
				break;
			}

		if (flag == 1) {
			printf("%s ", x[i].a);
			printf("%d\n", x[i].n);
		}
	}

	fclose(in);

	return 0;
}


