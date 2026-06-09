#include <stdio.h>
#include <stdlib.h>

int cmp(char *a1, char *a2) {//±È½Ï×ÖÄ¸Ë³Ðò
	int i = 0;
	while (a1[i] != '\0' || a2[i] != '\0') {
		if (a1[i] > a2[i])
			return 1;
		else if (a1[i] < a2[i])
			return -1;
		i++;
	}
	return 0;
}

void swap(char a1[], char a2[]) {
	char t;
	for (int i = 0; i < 40; i++) {
		t = a1[i];
		a1[i] = a2[i];
		a2[i] = t;
	}
}

struct link {
	char *word;
	int t;
	struct link *llink;
	struct link *rlink;
};

int main() {
	char a[1000][50], b;
	FILE *in = fopen("article.txt", "r");
	int i = 0;
	while ((b = fgetc(in)) != EOF) {
		int j = 0, k = 0;
		if ((b >= 65 && b <= 90) || (b >= 97 && b <= 122))
			i++;
		while ((b >= 65 && b <= 90) || (b >= 97 && b <= 122)) {
			if (b >= 65 && b <= 90) {
				a[i - 1][k] = b + 32;
				k++;
			} else if (b >= 97 && b <= 122) {
				a[i - 1][k] = b;
				k++;
			}
			b = fgetc(in);
		}
	}
	int n = i;
//	for (i = 0; i < n; i++) {
//		puts(a[i]);
//	}
	struct link *l = NULL, *r = NULL, *p;
	for (i = 0; i < n; i++) {
//		printf("%d ", i);
		r = l;
		p = (struct link *)malloc(sizeof(struct link));
		p->word = a[i];
		p->t = 1;
		p->llink = NULL;
		p->rlink = NULL;
		while (1) {
			if (l == NULL) {
				l = p;
				r = p;
				break;
			} else if (cmp(p->word, l->word) < 0) {
				p->rlink = l;
				l->llink = p;
				l = l->llink;
				break;
			} else if (cmp(p->word, r->word) < 0) {
				p->rlink = r;
				p->llink = r->llink;
				r->llink->rlink = p;
				r->llink = p;
				break;
			} else if (cmp(p->word, r->word) == 0) {
				r->t++;
				break;
			} else if (r->rlink == NULL) {
				r->rlink = p;
				p->llink = r;
				break;
			} else if (cmp(p->word, r->word) > 0) {
				r = r->rlink;

			}
		}
	}
	p = l;
	while (p != NULL) {
		printf("%s %d\n", p->word, p->t);
		p = p->rlink;
	}
	return 0;
}

