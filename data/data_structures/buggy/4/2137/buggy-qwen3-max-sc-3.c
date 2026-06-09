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
    fp = fopen("article.txt", "r"); // @@ [If the file does not exist or cannot be opened, fp will be NULL, and subsequent fgetc(fp) leads to undefined behavior.]
    char w[20];
    int i = 0;
    int m;
    char c;
    while ((c = fgetc(fp) ) != EOF) { // @@ [c is declared as char, but fgetc returns int. Comparing a char (which may be signed) with EOF (typically -1) can cause infinite loops if char is signed and byte 0xFF is read.]
        c = tolower(c); // @@ [tolower expects an unsigned char cast to int or EOF; passing a char that's negative (if plain char is signed) invokes undefined behavior.]
        int n = 0;
        while (isalpha(c)) { // @@ [isalpha also requires input to be representable as unsigned char or EOF; same issue as above.]
            w[n] = c;
            n++;
            c = fgetc(fp); // @@ [Same type issue: c is char, but fgetc returns int. Also, if n exceeds 19, buffer overflow occurs.]
        }
        w[n] = '\0';
        m = search(w, n, sta, i);
        if (m == 0)
            i++;

    }
    qsort(sta, i, sizeof(struct list), cmp);
    for (int h = 0; h < i; h++) {
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
    for (int j = 0; j < k; j++) {
        if (strcmp(wd, l[j].word) == 0) {
            l[j].t += 1;
            return 1;
        }
    }

    strcpy(l[k].word, wd);
    l[k].t = 1;

    return 0;
}