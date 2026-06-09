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

char ch; // @@ [Global variable 'ch' is of type char, but fgetc returns int. Using char may cause EOF comparison to fail on platforms where char is unsigned, leading to infinite loops.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but 'ch' is char. If char is unsigned, EOF (-1) becomes 255, so condition never true → infinite loop or incorrect termination.]
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
    for (int x = 0; x < i - 1; x++) { // @@ [Variable 'x' is redeclared here with 'int', but earlier 'x' is already declared at function scope. This may cause compilation error in C89 or inconsistent behavior. Also, the merging logic is flawed: it modifies data and re-sorts repeatedly, which is inefficient and error-prone.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ [list[x].number is never initialized to 0 or 1. It starts as garbage value, so incrementing leads to undefined behavior.]
            list[x + 1].word[0] = '}'; // @@ [Arbitrary character '}' used to push duplicates to end after re-sorting. This is fragile and not guaranteed to work lexicographically (e.g., if real words start with '}').]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since list[x].number was never initialized, adding 1 to garbage gives wrong count. Correct approach: initialize all counts to 1 when word is first stored.]
    return 0;
}