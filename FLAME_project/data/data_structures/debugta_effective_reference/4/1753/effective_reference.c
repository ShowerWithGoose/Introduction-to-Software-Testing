#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct list {
	char word[50];
	int h;
	struct list* next;
};
struct list* head = NULL, *p = NULL, *r = NULL, *tail = NULL;

int main() {
	FILE *in = fopen("article.txt", "r");
	int o = 0;
	int num = 2;
	char s, y = 0;
	r = (struct list*)malloc(sizeof(struct list));
	head = p = r;
	r = (struct list*)malloc(sizeof(struct list));
	head->next = r;
	p = r;

	while ((s = fgetc(in)) != EOF) {
		
		if (s >= 'A' && s <= 'Z') {
			s = s + 32;
			p->word[o] = s;
			o++;
		} else if (s >= 'a' && s <= 'z') {
			p->word[o] = s;
			o++;
		} else {
			p->word[o]=' ' ;
			p->word[o+1] = '\0';
			r = (struct list*)malloc(sizeof(struct list));
			p->next = r;
			p = p->next;
			o = 0;
			num++;
		}

		y = s;
	}

	struct list  *x = head->next;
	for (int i = 0; x != NULL; i++) {
		int g = 1;
		x->h = g;
		x = x->next;
	}

	struct list *pre, *q, *z;
	while (head->next != tail) {
		pre = head;
		q = head->next;
		z = q->next;
		while (q->next != tail) {
			int flag = 0;
			for (int i = 0; q->word[i] != '\0' && z->word[i] != '\0'; i++) {
				if (q->word[i] > z->word[i]) {
					flag = 1;
					break;
				} else if (q->word[i] < z->word[i]) {
					break;
				}
			}
			if (flag == 1) {
				pre->next = z;
				q->next = z->next;
				z->next = q;
			} else {
				q = q->next;
			}
			z = q->next;
			pre = pre->next;

		}
		tail = q;
	}

	r = p = head->next;
	for (int i = 0; p->next != NULL; i++) {
		int s1, s2;
		s1 = strlen(p->word);
		s2 = strlen(p->next->word);
		if (s1 == s2) {
			for (int j = 0; p->word[j] != '\0' && p->next->word[j] != '\0'; j++) {
				if (p->word[j] != p->next->word[j]) {
					p = p->next;
					break;

				}
				if (j == s1 - 1) {
					p->h++;
					r = p->next;
					p->next = p->next->next;
					free(r);
				}
			}

		} else p = p->next;

	}

	struct list*w = head->next->next;
	for (int i = 0; w->next != NULL; i++) {
		printf("%s%d\n", w->word, w->h);

		w = w->next;
	}

	fclose(in);
	return 0;
}

