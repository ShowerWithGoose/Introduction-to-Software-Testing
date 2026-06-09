#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct Node
{
    char word[50];
    int count;
    struct Node *link;
}Node;
typedef struct Node *linkptr;

linkptr insert(linkptr L, char ss[50])
{
    linkptr p = L, q = NULL, r;
    if (p == NULL)
    {
        r = (linkptr)malloc(sizeof(Node));
        strcpy(r->word, ss);
        r->count = 1;
        r->link = NULL;
        L = r;
        return L;
    }
    while (strcmp(p->word, ss) < 0)
    {
        q = p;
        p = p->link;
        if (p == NULL)
            break;
    }
    if (p == NULL)
    {
        r = (linkptr)malloc(sizeof(Node));
        strcpy(r->word, ss);
        r->count = 1;
        r->link = NULL;
        q->link = r;
        return L;
    }
    else
    {
        if (strcmp(p->word, ss) == 0)
        {
            p->count++;
            return L;
        }
        if (strcmp(p->word, ss) > 0 && q != NULL)
        {
            r = (linkptr)malloc(sizeof(Node));
            strcpy(r->word, ss);
            r->count = 1;
            r->link = p;
            q->link = r;
            return L;
        }
        if (p == L && q == NULL)
        {
            r = (linkptr)malloc(sizeof(Node));
            strcpy(r->word, ss);
            r->count = 1;
            r->link = p;
            L = r;
            return L;
        }
    }
}

int main()
{
    char getword[50] = {'\0'}, ch;
    linkptr L = NULL;
    int i = 0;
    FILE *in;
    in = fopen("article.txt", "r");
    ch = fgetc(in);
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            if (ch >= 65 && ch <= 90)
                ch = ch + 32;
            getword[i++] = ch;
        }
        else
        {
            getword[i] = '\0';
            if (strlen(getword) > 0)
            {
                L = insert(L, getword);
                getword[0] = '\0';
                i = 0;
            }
        }
        ch = fgetc(in);
    }
    fclose(in);
    linkptr p;
    for (p = L; p != NULL; p = p->link)
    {
        printf("%s ", p->word);
        printf("%d\n", p->count);
    }
    return 0;
}

