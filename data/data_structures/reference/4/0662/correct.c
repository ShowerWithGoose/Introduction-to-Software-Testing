#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node {
	char c[50];
	int cnt;
}q[10000];
int N = 1000, n;
char s[1000];
void init() {
	char ch[50];
	int i, j, flag;
	for (i = 0; i < strlen(s); i++) {
		j = 0;
		while (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
			ch[j++] = (s[i] >= 'a' && s[i] <= 'z') ? s[i] : s[i]+32;
			i++;
		}
		if (j) {
			ch[j] = '\0';
			flag = 0;
			for (j = 1; j <= n; j++) {
				if (strcmp(ch, q[j].c) == 0) {q[j].cnt++; flag = 1; break;}
			}
			if (!flag) strcpy(q[++n].c, ch), q[n].cnt = 1;
		} 
	}
}
int cmp(const void *a, const void *b){
	struct node *c = (struct node *)a;
	struct node *d = (struct node *)b;
	return strcmp(c->c, d->c);
}
int main()
{
	int i;
	FILE *in;
	in = fopen("article.txt", "r");
	while (fgets(s, N, in) != NULL) {
		init();
	}
	qsort(q+1, n, sizeof(q[0]), cmp);
	for (i = 1; i <= n; i++) {
		printf("%s %d\n", q[i].c, q[i].cnt);
	} 
	fclose(in);
	return 0;
}

