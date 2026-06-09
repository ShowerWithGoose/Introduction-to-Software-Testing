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
} // @@ [The comparison function for qsort must return negative, zero, or positive based on ordering. This implementation returns only 1 or -1, which breaks strict weak ordering and may cause undefined behavior in qsort.]

char ch; // @@ [Global variable 'ch' is of type char, but fgetc returns int. Using char may cause EOF comparison to fail because EOF is outside the range of char.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. If char is signed, a byte with value 0xFF will be sign-extended and equal to EOF (-1), causing premature loop exit. Also, if file fails to open, fp is NULL and fgetc causes undefined behavior.]
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
    for (int x = 0; x < i - 1; x++) { // @@ ['int x' declaration inside for-loop is C99+, but more critically, 'number' field is never initialized to 0, so incrementing it leads to undefined behavior.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ [Uninitialized 'number' field: starts with garbage value, not 0. Should initialize all counts to 1 or 0 at start.]
            list[x + 1].word[0] = '}'; // @@ [Arbitrary character '}' used to mark deleted words; this is fragile and may not sort correctly. Also modifies data instead of using proper deduplication.]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Because 'number' was never initialized and incremented from garbage, adding 1 does not yield correct count. Correct approach: initialize count to 1 when word is first added.]
    return 0;
}