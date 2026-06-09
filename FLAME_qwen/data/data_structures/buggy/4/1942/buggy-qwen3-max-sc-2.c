#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct danci {
    char word[100];
    int number;
} list[100];

int cmp(const void *a, const void *b) {
    struct danci aa = *((struct danci *)a);
    struct danci bb = *((struct danci *)b);
    if (strcmp(aa.word, bb.word) >= 0)
        return 1;
    else
        return -1;
} // @@ [The comparison function for qsort must return negative, zero, or positive based on ordering. This implementation returns only -1 or 1, which breaks strict weak ordering and may cause undefined behavior in qsort.]

char ch; // @@ [Declaring 'ch' as a global char variable is problematic because fgetc returns an int to properly handle EOF. Using char may cause EOF comparison to fail on systems where char is unsigned.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. This can cause incorrect EOF detection, especially if char is unsigned, leading to infinite loops or missed termination.]
        if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
            if ('A' <= ch && ch <= 'Z')
                ch = ch - ('A' - 'a');
            linshi[j] = ch;
            j++;
        } else {
            if (j == 0)
                continue;
            else {
                for (x = 0; x < j; x++)
                    list[i].word[x] = linshi[x];
                j = 0;
                list[i].word[x] = '\0';
                i++;
            }
        }
    }
    if (j != 0) {
        for ( x = 0; x < j; x++) {
            list[i].word[x] = linshi[x];
        }
        list[i].word[x] = '\0';
        i++;
    }
    qsort(list, i, sizeof(struct danci), cmp);
    for (int x = 0; x < i - 1; x++) { // @@ [Variable 'x' is redeclared here with 'int', but it was already declared earlier in the same scope (C89 incompatibility). While C99 allows it, some compilers may not support mixed declarations and code without proper flags, potentially causing compilation errors.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ [list[x].number is used uninitialized. All entries in 'list' start with garbage values for 'number', so incrementing leads to undefined behavior. Should initialize to 1 when first storing the word.]
            list[x + 1].word[0] = '}'; // @@ [Using '}' as a marker assumes it's lexicographically after all valid words, but this is fragile and unnecessary. Also, modifying the word corrupts data and relies on sort stability, which is error-prone.]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since 'number' was never initialized to 0 or 1, adding 1 here does not correctly reflect frequency. If initialized properly to 1 on first occurrence, this '+1' would overcount.]
    return 0;
}