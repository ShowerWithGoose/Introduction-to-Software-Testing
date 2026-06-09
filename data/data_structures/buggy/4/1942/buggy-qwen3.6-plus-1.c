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
    if (strcmp(aa.word, bb.word) >= 0) // @@ The comparison function for qsort must return 0 when elements are equal. Returning 1 for equal elements violates the strict weak ordering requirement and may cause undefined behavior or infinite loops in qsort.
        return 1;
    else
        return -1;
}
char ch; // @@ ch should be declared as int to correctly store and compare with EOF, as fgetc returns an int. Using char may cause premature loop termination or infinite loops if a character matches EOF's byte value.
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
    for (int x = 0; x < i - 1; x++) { // @@ Redeclaration of variable 'x' inside the for loop may cause a compilation error in C89/ANSI C standards or strict compiler settings. It also shadows the outer 'x'.
        if (strcmp(list[x].word, list[x + 1].word) == 0) {
            list[x].number++;
            list[x + 1].word[0] = '}'; // @@ Modifying the string content to mark duplicates is error-prone. It changes the lexicographical order and may cause incorrect sorting or output. A better approach is to use a flag or shift elements.
            qsort(list, i, sizeof(struct danci), cmp);
            i--;
            x--;
        }
    }
    for (x = 0; x < i; x++)
        printf("%s %d\n", list[x].word, (list[x].number) + 1);
    return 0;
}