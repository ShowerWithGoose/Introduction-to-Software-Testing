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
    while (fgets(txt, 200, fi) != NULL); // @@ dangling semicolon creates an empty loop; only the last line is processed
    {
        char w[25]; // @@ buffer too small (max word length 80 needed), risk of overflow
        int j = 0;
        for (int i = 0; i < strlen(txt); i++) { // @@ missing handling for the final word after the loop ends (no non‑letter triggers else‑if)
            if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')) {
                w[j] = tolower(txt[i]);
                w[j + 1] = '\0';
                j++;
            } else if (i > 0 && j != 0) { // @@ condition only triggers on a non‑letter character, not at end‑of‑line; last word is lost
                int flag = 0;
                for (int t = 0; t < k; t++) {
                    if (strcmp(w, W[t].wd) == 0) {
                        W[t].num++;
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    memcpy(W[k].wd, w, strlen(w) + 1);
                    W[k].num++;
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