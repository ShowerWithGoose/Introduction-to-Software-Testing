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
} // @@ [The comparison function for qsort must return negative, zero, or positive based on ordering. This implementation returns only 1 or -1, which breaks strict weak ordering when strings are equal (should return 0). This leads to undefined behavior in qsort.]

char ch; // @@ [Global variable 'ch' is of type char, but fgetc returns int. Using char causes EOF (which is typically -1) to be misinterpreted as a valid character when char is unsigned, leading to infinite loops or missed EOF detection.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. If char is unsigned, EOF (-1) becomes 255 and never equals EOF, causing infinite loop or incorrect termination.]
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
    for (int x = 0; x < i - 1; x++) { // @@ [Variable 'x' is redeclared here with 'int', but 'x' was already declared earlier in main(). In C89/C90, this is invalid (redeclaration). Even in C99+, it's confusing and may mask bugs. Also, the loop logic for merging duplicates is flawed: it modifies array during iteration and uses unstable marker ('}') which may not sort correctly.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ [list[x].number is never initialized to 0 or 1. It starts as garbage value. Should be initialized when word is first stored.]
            list[x + 1].word[0] = '}'; // @@ [Using '}' as a marker assumes it's lexicographically after all letters, but this is fragile and non-portable. Also, original words are corrupted.]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since list[x].number was never initialized, adding 1 to garbage yields wrong counts. Correct approach: initialize number to 1 when word is first added.]
    return 0;
}