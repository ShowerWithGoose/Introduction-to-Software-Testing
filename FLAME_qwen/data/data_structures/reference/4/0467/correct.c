#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int num_words = 0;
char c, w[105];

struct words
{
    char s[105];
    int cnt;
    struct words *link_r, *link_l;
} a[10005];

struct words *start;

void addword(char x[])
{
    if (num_words == 0)
    {
        num_words ++;
        strcpy(a[num_words].s, x);
        a[num_words].cnt ++;
        a[num_words].link_r = NULL;
        a[num_words].link_l = NULL;
        start = a + 1;
    }
    else
    {
        struct words *p = start;
        while (strcmp(p->s, x) < 0 && p->link_r != NULL)
            p = p->link_r;
        if (strcmp(p->s, x) == 0)
            p->cnt ++;
        else if (strcmp(p->s, x) > 0)
        {
            num_words ++;
            a[num_words].cnt ++;
            strcpy(a[num_words].s, x);
            if (p->link_l == NULL)
            {
                a[num_words].link_r = p;
                a[num_words].link_l = NULL;
                p->link_l = a + num_words;
                start = a + num_words;
            }
            else
            {
                a[num_words].link_r = p;
                a[num_words].link_l = p->link_l;
                p->link_l->link_r = a + num_words;
                p->link_l = a + num_words;
            }
        }
        else if (p->link_r == NULL)
        {
            num_words ++;
            a[num_words].cnt ++;
            strcpy(a[num_words].s, x);
            a[num_words].link_l = p;
            a[num_words].link_r = NULL;
            p->link_r = a + num_words;
        }
    }
}

int main()
{
    struct words *p;
    int len = 0;
    FILE *in;
    in = fopen("article.txt", "r");
    while ((c = fgetc(in)) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            w[len ++] = tolower(c);
        else if (len > 0)
        {
            w[len] = '\0';
            addword(w);
            memset(w, 0, sizeof w);
            len = 0;
        }
        else len = 0;
    }
    p = start;
    while (p != NULL)
    {
        printf("%s %d\n", p->s, p->cnt);
        p = p->link_r;
    }
    fclose(in);
    return 0;
}


