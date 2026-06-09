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

char ch; // @@ [Global variable 'ch' is of type char, but fgetc returns int. Using char causes EOF comparison to fail on platforms where char is unsigned, leading to infinite loops or missed EOF.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. On systems with unsigned char, EOF (typically -1) gets converted to a positive value, so loop never exits when EOF is reached.]
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
    for (int x = 0; x < i - 1; x++) { // @@ [Variable 'x' is redeclared here with 'int', but it was already declared earlier in the same scope (C89/C90 doesn't allow this; even in C99+, mixing styles can cause confusion). More critically, 'number' field is never initialized to 0, so incrementing it leads to undefined behavior.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ ['number' was never initialized; reading and incrementing uninitialized memory causes undefined behavior.]
            list[x + 1].word[0] = '}'; // @@ [Using '}' as a marker assumes it won't appear in real words, but more importantly, this approach is fragile and inefficient. However, the core error is lack of initialization and incorrect merging logic.]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since 'number' starts uninitialized and is only incremented during duplicates, non-duplicate words have garbage values. Adding 1 assumes initial count is 0, but it's actually undefined. Correct approach: initialize all counts to 1 when first storing the word.]
    return 0;
}