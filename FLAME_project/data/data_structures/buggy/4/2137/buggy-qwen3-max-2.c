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
        int n = 0;
        while (isalpha(c)) {
            w[n] = c;
            n++;
            c = fgetc(fp);
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
// @@ [The program reads one character at a time and converts it to lowercase before checking if it's alphabetic. However, after reading a non-alphabetic character following a word, the loop continues and processes that non-alphabetic character again in the next iteration because `c` is not re-fetched after exiting the inner `while (isalpha(c))` loop. This causes the first non-alphabetic character after a word to be converted to lowercase and then skipped without being processed as a separator properly. More critically, when a word ends due to EOF or non-alpha, the next character (which broke the alpha sequence) is consumed but then the outer loop immediately reads the next character, potentially skipping characters or mishandling transitions between words and non-words. Additionally, the variable `c` is declared as `char`, but `fgetc()` returns an `int` to properly handle EOF; using `char` may cause EOF comparison to fail on systems where `char` is unsigned. This can lead to infinite loops or missed characters. Also, empty strings (when `n == 0`) are passed to `search`, which inserts empty words into the list, though they are later filtered out in output—but this still affects indexing and count logic. The core issue causing wrong counts is that non-alphabetic characters are not properly skipped before starting the next word, leading to incorrect word segmentation.]