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
    while ((c = fgetc(fp) ) != EOF) { // @@ [c is declared as char, but fgetc returns int. This causes incorrect EOF comparison when char is signed, leading to premature loop termination or infinite loop.]
        c = tolower(c); // @@ [tolower should only be applied to alphabetic characters; applying it to non-alphabetic (e.g., digits, punctuation) is unnecessary but not harmful. However, the bigger issue is that non-alphabetic characters are not skipped properly before starting a new word.]
        int n = 0;
        while (isalpha(c)) { // @@ [This inner loop assumes c is already alphabetic, but after reading a non-alphabetic character in the outer loop, c is converted to lowercase and then checked. However, if the first character read is non-alphabetic, this loop never runs, but w becomes empty string and is inserted into the list.]
            w[n] = c;
            n++;
            c = fgetc(fp); // @@ [Again, c is char, so EOF may be misinterpreted. Also, after reading EOF inside this loop, c becomes EOF (as char), and next isalpha(EOF) is undefined behavior.]
        }
        w[n] = '\0';
        m = search(w, n, sta, i); // @@ [Even if w is an empty string (n=0), it's passed to search and stored, leading to output of empty words.]
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