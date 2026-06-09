#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

struct list {
    char word[20];
    int t;
};
int search(char [], int, struct list [], int);
int cmp(const void *a, const void *b);
struct list sta[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    char w[20];
    int i = 0;
    int m;
    char c;
    while ((c = fgetc(fp) ) != EOF) {
        c = tolower(c);
        int n = 0; // @@ Declaration after statement; C89 forbids mixed declarations and code.
        while (isalpha(c)) {
            w[n] = c;
            n++;
            c = fgetc(fp);
        }
        w[n] = '\0';
        m = search(w, n, sta, i); // @@ Logical error: search is called even when n==0 (empty word), causing insertion of empty strings.
        if (m == 0)
            i++;

    }
    qsort(sta, i, sizeof(struct list), cmp);
    for (int h = 0; h < i; h++) { // @@ Declaration inside for loop initializer; C89 requires declaration before statements.
        if ((sta[h].word[0] != '\0'))
            printf("%s %d\n", sta[h].word, sta[h].t);
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    struct list *pa = (struct list *)a;
    struct list *pb = (struct list *)b;
    return strcmp( pa->word, pb->word );

}

int search(char wd[], int n, struct list l[], int k) {
    for (int j = 0; j < k; j++) { // @@ Declaration inside for loop initializer; C89 requires declaration before statements.
        if (strcmp(wd, l[j].word) == 0) {
            l[j].t += 1;
            return 1;
        }
    }

    strcpy(l[k].word, wd);
    l[k].t = 1;

    return 0;
}