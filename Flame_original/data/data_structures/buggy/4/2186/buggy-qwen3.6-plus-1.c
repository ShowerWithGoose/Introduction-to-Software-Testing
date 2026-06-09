#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define max 32

struct node {
    char word[max];
    int count;
    struct node *link;
};
struct node *list = NULL;
int getword(FILE *bfp, char *w);
int search(char *w);
int insert(struct node *p, char *w);

int main() {
    char a[20], word[max];
    FILE *fp1 = fopen("article.txt", "r");
    struct node *p;
    scanf("%s", a); // @@ Unnecessary input reading from stdin not required by problem; may cause program to hang or fail in automated tests.
    while ((getword(fp1, word)) != EOF) {
        if (search(word) == -1) {
            return -1;
        }
    }
    for (p = list; p != NULL; p = p->link) {
        printf("%s %d\n", p->word, p->count);
    }
    return 0;
}



int insert(struct node *p, char *w) {
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL)
        return -1;
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if (list == NULL) {
        list = q;
    } else if (p == NULL) {
        q->link = list;
        list = q;
    } else {
        q->link = p->link;
        p->link = q;
    }

    return 0;
}

int search(char *w) {
    struct node *p, *q = NULL;
    for (p = list; p != NULL; q = p, p = p->link) {
        if (strcmp(w, p->word) != 0) { // @@ Logical error: breaks traversal on first mismatch instead of continuing. Should continue until a match is found or the correct insertion position (w < p->word) is reached.
            break;
        } else if (strcmp(w, p->word) == 0) {
            p->count++;
            return 0;
        }
    }
    return insert(q, w);
}


int getword(FILE *fp, char *w) {
    int c, i = 0;

    while (!isalpha(c = fgetc(fp)))
        if (c == EOF)
            return c;
        else
            continue;
    do  {
        w[i++] = tolower(c);
    } while (isalpha(c = fgetc(fp)));
    w[i] = '\0';
    return 1;
}