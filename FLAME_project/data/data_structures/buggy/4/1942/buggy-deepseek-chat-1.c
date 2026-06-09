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
char ch;
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
    for (int x = 0; x < i - 1; x++) {
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++;
            list[x + 1].word[0] = '}';
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Error: The initial number field is not set to 0, so adding 1 gives incorrect counts. For example, "do" appears 3 times but outputs 2 because number starts uninitialized (0) and only increments once for duplicates, resulting in number=2, then +1 gives 3 incorrectly. Actually, the logic is flawed: number should start at 1 for each unique word, but here it's never initialized, so the count is off by one for words that appear only once (output 1 instead of 1? Wait, for single occurrence, number is 0, +1 gives 1, correct; but for "do" which appears 3 times, the code only increments number once (when merging duplicates), so number becomes 1, +1 gives 2, but expected is 3. The root cause is that number is never set to 1 for the first occurrence, and the merging logic only adds one for each duplicate, missing the initial count. The correct approach is to initialize number to 1 when first adding a word, and increment for each duplicate. Here, number is uninitialized (0), so the count is always one less than expected for words with multiple occurrences.]
    return 0;
}