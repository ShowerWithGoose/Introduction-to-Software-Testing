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

char ch; // @@ [Global variable 'ch' is of type char, but fgetc returns int. Using char causes EOF comparison to fail because EOF is outside the range of char, leading to infinite loop or incorrect termination.]

char linshi[100];

int main() {
    FILE *fp;
    fp = fopen("article.txt", "r");
    int x;
    int i = 0; //
    int j = 0; //
    while ((ch = fgetc(fp)) != EOF) { // @@ [fgetc returns int, but ch is char. When char is signed, a byte with value 0xFF becomes -1, which equals EOF, causing premature termination. When unsigned, EOF (-1) never matches, causing infinite loop.]
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
    for (int x = 0; x < i - 1; x++) { // @@ [Variable 'x' is redeclared inside for-loop while already declared earlier, which is invalid in C89 and may cause compilation error depending on compiler settings.]
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++; // @@ [Field 'number' is never initialized to 1, so incrementing uninitialized value leads to undefined behavior.]
            list[x + 1].word[0] = '}'; // @@ [Arbitrary character '}' is used to mark duplicates, but this may not sort correctly lexicographically and is an unreliable method for removal.]
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1); // @@ [Since 'number' starts uninitialized and is only incremented when duplicates are found, adding 1 assumes base count of 1, but this fails if word appears only once (then number=0, output=1 — accidentally correct), but logic is flawed and fragile. Also, if a word appears 3 times, it may be counted incorrectly due to repeated sorting and shifting.]
    return 0;
}