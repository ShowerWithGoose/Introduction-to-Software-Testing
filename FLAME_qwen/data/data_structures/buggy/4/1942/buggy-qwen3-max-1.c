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

char ch; // @@ [Global variable 'ch' is of type char, but fgetc returns int. Using char can cause EOF comparison to fail on systems where char is unsigned, leading to infinite loops.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. On systems with unsigned char, EOF (typically -1) becomes 255, so loop never exits.]
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
    for (int x = 0; x < i - 1; x++) { // @@ [Variable 'x' is redeclared here; this may cause compilation error in C89 or with strict compilers. Also, 'number' field is never initialized to 0, so initial counts are garbage.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ ['number' was never initialized, so incrementing garbage value leads to undefined behavior.]
            list[x + 1].word[0] = '}'; // @@ [Arbitrary character '}' used to mark duplicates; this is fragile and may not sort correctly since '}' has high ASCII value.]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since 'number' starts uninitialized and is only incremented for duplicates, the final count is off by one unless corrected. However, because it's uninitialized, even +1 doesn't fix the core issue.]
    return 0;
}