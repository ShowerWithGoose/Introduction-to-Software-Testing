#include <stdio.h>
#include <string.h>
struct wordList {
    char word[1001];
    int count;
    struct wordList *next;
} *first = NULL, *p, *q, *r, *s;

void getList() {
    FILE *in = fopen("article.txt", "r");
    char ch, word[1001];
    int j = 0, flag = 0, sign = 0;
    memset(word, 0, sizeof(word));
    while ((ch = fgetc(in)) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            word[j++] = ch;
        else if (ch >= 'A' && ch <= 'Z')
            word[j++] = ch + 'a' - 'A';
        else if (strlen(word) > 0) {
            if (flag == 1) {
                r = first;
                while (r != NULL) {
                    if (strcmp(r->word, word) == 0) {
                        r->count++;
                        sign = 1;
                        j = 0;
                        break;
                    }
                    r = r->next;
                }
                if (sign == 0) flag = 0;
                sign = 0;
            }
            if (flag == 0) {
                q = (struct wordList *)malloc(sizeof(struct wordList));
                strcpy(q->word, word);
                q->count = 1;
                q->next = NULL;
                if (first == NULL)
                    first = p = q;
                else {
                    p->next = q;
                    p = p->next;
                }
                flag = 1;
                j = 0;
            }
            memset(word, 0, sizeof(word));
        }
    }
    return;
}

void compare() {
    int change = 0;
    while (1) {
        p = first;
        while (p->next != NULL) {
            if (strcmp(p->word, p->next->word) > 0) {
                r = p->next->next;
                p->next->next = p;
                if (p == first)
                    first = p->next;
                else {
                    s = first;
                    while (s->next != p) s = s->next;
                    s->next = p->next;
                }
                p->next = r;
                change++;
            } else {
                p = p->next;
            }
        }
        if (change == 0) break;
        change = 0;
    }
    return;
}

void print() {
    p = first;
    while (p != NULL) {
        printf("%s %d\n", p->word, p->count);
        p = p->next;
    }
    return;
}

int main() {
    getList();
    compare();
    print();
    return 0;
}
