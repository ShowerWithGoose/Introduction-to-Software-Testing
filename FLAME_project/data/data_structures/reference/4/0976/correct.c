#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	char s[10005];
	int num;

} p[10005];

int cmp(const void *a, const void *b) {
	struct node *c = (struct node *)a;
	struct node *d = (struct node *)b;
	return strcmp(c->s, d->s);
}
char str[10005];

int main() {
	FILE *fp = fopen("article.txt", "r");
	char c;
	int cnt = 0;
	while ((c = fgetc(fp)) != EOF) {
		str[cnt++] = c;
	}

	cnt = 0;
	int k = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (!isalpha(str[i])) {
			cnt++;
			k = 0;
		} else
			p[cnt].s[k++] = tolower(str[i]);
	}


	qsort(p, cnt, sizeof(p[0]), cmp);

	for (int i = 0; i < cnt; i++)
		if (strlen(p[i].s))
			p[i].num = 1;
	for (int i = 0; i < cnt; i++)
		if (strcmp(p[i].s, p[i + 1].s) == 0) {
			p[i + 1].num += p[i].num;
			p[i].num = 0;
		}
	for (int i = 0; i < cnt; i++)
		if (p[i].num != 0)
			printf("%s %d\n", p[i].s, p[i].num);
	return 0;
}



