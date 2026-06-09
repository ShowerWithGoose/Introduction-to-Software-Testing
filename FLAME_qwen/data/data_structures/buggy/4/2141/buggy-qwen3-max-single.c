#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char wd[25];
    int num;
} word;
word W[1000];

int cmp(const void *x, const void *y) {
    word *a = (word *)x, * b = (word *)y;
    return strcmp(a->wd, b->wd);
}

int main() {
    int k = 0;
    char txt[200];
    FILE *fi;
    fi = fopen("article.txt", "r");
    while (fgets(txt, 200, fi) != NULL); // @@ [The semicolon here terminates the while loop immediately, causing the following block to execute only once after the loop ends, not per line. This results in processing only uninitialized or leftover data in `txt`.]
    {
        char w[25];
        int j = 0;
        for (int i = 0; i < strlen(txt); i++) {
            if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')) {
                w[j] = tolower(txt[i]);
                w[j + 1] = '\0';
                j++;
            } else if (i > 0 && j != 0) {
                int flag = 0;
                for (int t = 0; t < k; t++) {
                    if (strcmp(w, W[t].wd) == 0) {
                        W[t].num++;
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    memcpy(W[k].wd, w, strlen(w) + 1);
                    W[k].num++; // @@ [`W[k].num` is incremented from an uninitialized value (garbage), should be set to 1 instead.]
                    k++;
                }
                memset(w, 0, 25);
                j = 0;
            }
        }
    }
    qsort(W, k, sizeof(word), cmp);
    for (int i = 0; i < k; i++) {
        printf("%s %d\n", W[i].wd, W[i].num);
    }
}