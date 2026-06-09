#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct word {
    char w[30];
    int cnt;
};
typedef struct word Word;
typedef struct word *Wordptr;
Word a[100];
char s[1000];

int cmp(const void *p1, const void *p2);

int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    FILE *fp = fopen("article.txt", "r");
    char c;
    int i, j, cur = 0, begin, end, word_cnt = 0;
    //文件内容存入s数组
    for (i = 0; (c = fgetc(fp)) != EOF; i++) {
        if (isalpha(c)) {
            c = tolower(c);
        }
//        printf("%c", c);
        s[i] = c;
    }
    i = 0;
    while (cur < strlen(s)) {
        if (isalpha(s[cur])) {
            begin = cur;
            for (end = cur; end < strlen(s); end++) {
                if (!isalpha(s[end])) break;
            }
            cur += end - begin;
            strncpy(a[i].w, &s[begin], end - begin);
//            printf("%s\n", a[i].w);
            i++;
            word_cnt++;
        } else cur++;
    }
    for (i = 0; i < word_cnt; i++) {
        a[i].cnt = 1;
    }
    qsort(a, word_cnt, sizeof(Word), cmp);
    for (i = 0; i < word_cnt; i++) {
        for (j = i + 1; j < word_cnt; j++) {
            if ((strcmp(a[j].w, a[i].w) == 0) && a[j].cnt != 0) {
                a[j].cnt = 0;
                a[i].cnt++;
            }
        }
    }

    for (i = 0; i < word_cnt; i++) {
        if (a[i].cnt == 0) continue;
        printf("%s %d\n", a[i].w, a[i].cnt);
    }
    return 0;
}

int cmp(const void *p1, const void *p2) {
    Wordptr a = (Wordptr) p1;
    Wordptr b = (Wordptr) p2;
    return strcmp(a, b);
}

