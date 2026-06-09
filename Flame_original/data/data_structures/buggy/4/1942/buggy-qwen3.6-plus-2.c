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
}
char ch; // @@ `ch` should be declared as `int` to correctly store the return value of `fgetc()` and properly detect `EOF`. Using `char` may cause infinite loops or incorrect behavior if `char` is unsigned.
char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) {
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
    for (int x = 0; x < i - 1; x++) { // @@ Declaring `x` inside the loop shadows the outer `x` and may cause compilation errors in strict C89 environments. Additionally, modifying `x` inside the loop combined with resorting leads to logical errors.
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++;
            list[x + 1].word[0] = '}'; // @@ Modifying the word string corrupts the data. This approach to handle duplicates is fundamentally flawed and will produce incorrect output.
            qsort(list, i, sizeof(struct danci), cmp); // @@ Resorting the array inside the counting loop invalidates the loop index and causes logical errors/inefficiency. Duplicates should be counted in a single pass after the initial sort without modifying the array.
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1);
    return 0;
}