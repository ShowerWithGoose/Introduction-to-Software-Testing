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

char ch; // @@ [Global variable 'ch' is of type char, but fgetc() returns int to properly handle EOF. Using char may cause EOF to be misinterpreted as a valid character on systems where char is unsigned.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. This can cause incorrect EOF detection, especially on platforms where char is unsigned, leading to infinite loops or missed termination.]
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
    for (int x = 0; x < i - 1; x++) { // @@ [Variable-length array or loop index declared inside for-loop may not be supported in older C standards (e.g., C89), but more critically, the logic for counting duplicates is flawed: it modifies data during sorting and uses a hack (setting word[0] = '}') which is unreliable and inefficient.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ [list[x].number is never initialized to 0 or 1 before incrementing, leading to undefined behavior due to reading uninitialized memory.]
            list[x + 1].word[0] = '}';
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since list[x].number was never initialized, adding 1 to an uninitialized value produces garbage output. Correct approach: initialize all counts to 1 when word is first stored.]
    return 0;
}