#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *in;
int i, j, n;
char w[32];
struct list
{
    char word[32];
    int count;
    struct list *next;
};
struct list *head = NULL;
struct list *p = NULL;
struct list *q = NULL;
struct list *r = NULL;

int getword(FILE *fp, char *w);
int search(char *w);
int insert(char *w);

int main()
{
    in = fopen("article.txt", "r");

    while (getword(in, w) != EOF)
    {
        search(w);
    }
    for (p = head; p != NULL; p = p->next)
    {
        printf("%s %d\n", p->word, p->count);
    }
    fclose(in);
    return 0;
}

int getword(FILE *fp, char *w)
{
    char c;

    while (!isalpha(c = fgetc(fp)))
    {
        if (c == EOF)
        {
            return c;
        }
        else
        {
            continue;
        }
    }
    do
    {
        *w = tolower(c);
        w++;
    } while (isalpha(c = fgetc(fp)));
    *w = '\0';
    return 1;
}

int search(char *w)
{
    for (p = head; p != NULL; p = p->next)
    {
        if (strcmp(w, p->word) == 0)
        {
            p->count++;
            return 1;
        }
    }
    if (p == NULL)
    {
        return insert(w);
    }
}

int insert(char *w)
{
    if (head == NULL)
    {
        p = (struct list *)malloc(sizeof(struct list));
        p->next = NULL;
        p->count = 1;
        strcpy(p->word, w);
        ;
        head = p;

        return 1;
    }
    else
    {

        for (p = head; p != NULL && strcmp(p->word, w) < 0; q = p, p = p->next)
            ;
        if (p == head)
        {
            q = (struct list *)malloc(sizeof(struct list));
            strcpy(q->word, w);
            q->next = head;
            q->count = 1;
            head = q;
            return 1;
        }
        else
        {
            r = (struct list *)malloc(sizeof(struct list));
            strcpy(r->word, w);
            r->next = q->next;
            q->next = r;
            r->count = 1;
            return 1;
        }
    }
}

