#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word {
	char name[50];
	int num ;
} words;
words info[1000];

int cmp(const void *p, const void *q) {
	words *m = (words *)p;
	words *n = (words *)q;
	if (strcmp(m->name, n->name) > 0)
		return 1;
	if (strcmp(m->name, n->name) < 0)
		return -1;

}

int main() {
	FILE *in;
	char c, line[100];
	int cnt = 0, i = 0, k = 0, flag = 0;
	in = fopen("article.txt", "r");
	for (k = 0; k < 1000; k++) {
		info[k].num = 0;
		strcpy(info[k].name, " ");
	}
	while ((c = fgetc(in)) != EOF) {
		if (c >= 'a' && c <= 'z' || c <= 'Z' && c >= 'A') {
			if (c >= 'A' && c <= 'Z')
				c = c + ('a' - 'A');
			line[i++] = c;
			continue;
		}
		if (!(c >= 'a' && c <= 'z' || c <= 'Z' && c >= 'A') && i > 0) {
			line[i] = '\0';
			for (k = 0; k < cnt; k++) {
				if (strcmp(info[k].name, line) == 0) {
					info[k].num++;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				strcpy(info[cnt].name, line);
				info[cnt].num++;
				cnt++;
			}
			flag = 0;
			i = 0;
			memset(line, '\0', sizeof(line));
		}
	}
	qsort(info, cnt, sizeof(words), cmp);
	for (i = 0; i < cnt; i++) {
		printf("%s ", info[i].name);
		printf("%d\n", info[i].num);
	}
	fclose(in);
}
