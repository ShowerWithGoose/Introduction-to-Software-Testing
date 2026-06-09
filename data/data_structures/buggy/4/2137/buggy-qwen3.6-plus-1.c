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
    char word[20]; // @@ Struct member size 20 is too small for words, may cause buffer overflow during strcpy
    int t;
};
int search(char [], int, struct list [], int);
int cmp(const void *a, const void *b);
struct list sta[100]; // @@ Array size 100 is too small, may cause buffer overflow if there are more than 100 unique words

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r"); // @@ Missing NULL check for file pointer, may cause segmentation fault if file does not exist
    char w[20]; // @@ Buffer size 20 is insufficient for words, leading to potential buffer overflow
    int i = 0;
    int m;
    char c; // @@ fgetc returns int, storing EOF in char can cause infinite loop or incorrect comparison
    while ((c = fgetc(fp) ) != EOF) {
        c = tolower(c);
        int n = 0;
        while (isalpha(c)) {
            w[n] = c;
            n++;
            c = fgetc(fp);
        }
        w[n] = '\0';
        m = search(w, n, sta, i); // @@ Does not check if n==0, causing empty strings to be inserted and counted as words
        if (m == 0)
            i++;

    }
    qsort(sta, i, sizeof(struct list), cmp);
    for (int h = 0; h < i; h++) {
        if ((sta[h].word[0] != '\0'))
            printf("%s %d\n", sta[h].word, sta[h].t);
    }
    return 0; // @@ Missing fclose(fp) to properly close the file before program exit
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