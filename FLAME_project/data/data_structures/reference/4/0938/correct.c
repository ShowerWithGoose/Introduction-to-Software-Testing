#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read();

int isD(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
char tr(char c) { return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c; }

char rs[102];
int len;

struct P {
    char s[102];
    int len;
} p[10004];
int n;

int cmp(const void *a, const void *b) {
    struct P *_a = (struct P *)a;
    struct P *_b = (struct P *)b;
    return strcmp(_a->s, _b->s);
}

int main() {
    freopen("article.txt", "r", stdin);
    read();
    while (len) n++, p[n].len = len, strcpy(p[n].s, rs), read();

    qsort(p + 1, n, sizeof(p[0]), cmp);
    int i, j;
    for (i = 1; i <= n; i = j + 1) {
        j = i;
        while (strcmp(p[i].s, p[j + 1].s) == 0) ++j;
        printf("%s %d\n", p[i].s, j - i + 1);
    }
    return 0;
}

void read() {
    char c = getchar();
    len = 0;
    while (!isD(c) && c != EOF) c = getchar();
    if (c == EOF) return;
    while (isD(c)) rs[len++] = tr(c), c = getchar();
    rs[len] = 0;
}
