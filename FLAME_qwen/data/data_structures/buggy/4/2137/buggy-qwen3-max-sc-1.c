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
    fp = fopen("article.txt", "r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fp will be NULL, and subsequent fgetc(fp) leads to undefined behavior.]
    char w[20];
    int i = 0;
    int m;
    char c;
    while ((c = fgetc(fp) ) != EOF) { // @@ [c is declared as char, but fgetc returns int. When EOF (typically -1) is assigned to a char, it may become positive due to sign extension or truncation, causing the loop to never terminate or behave incorrectly.]
        c = tolower(c); // @@ [tolower expects an unsigned char cast to int or EOF. Passing a char that is negative (if plain char is signed) leads to undefined behavior.]
        int n = 0;
        while (isalpha(c)) { // @@ [isalpha also expects an unsigned char cast to int or EOF. Same issue as above with negative char values.]
            w[n] = c;
            n++;
            c = fgetc(fp); // @@ [Same type mismatch: assigning int (from fgetc) to char c causes loss of information for EOF detection in inner loop.]
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