#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct find_words_link
{
    char word[2000];
    int count;
    struct find_words_link *next;
};
typedef struct find_words_link link;
int get_word(FILE *fp, char *w)
{
    int c;
    while (!isalpha(c = fgetc(fp)))
        if (c == EOF)
            return c;
        else
            continue;
    do
    {
        *w++ = tolower(c);
    } while (isalpha(c = fgetc(fp)));
    *w = '\0';
    return 1;
}

link *search_word(link *head, char ch[])
{
    link  *p;
    p = head;
    for (; p != NULL && (strcmp(ch, p->word) != 0); p = p->next)
        ;
    if (p == NULL)
        return NULL;
    else
        return p;
}
link *insert_point(link *head, link *q)
{
    link *m, *n, *new_point;
    m = n = head; // m指向之前的，n指向之后的
    for (; n != NULL && (strcmp(q->word, n->word) > 0); m = n, n = n->next)
        ;
    if (n == head)
    {
        q->next = head;
        head = q;
        return head;
    }
    else
    {
        m->next = q;
        q->next = n;
        return head;
    }
    return head;
}
char string[200];
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    link *head = NULL, *tail, *q;
    q = (link *)malloc(sizeof(link));
    while (get_word(in, q->word) != EOF)
    {
        q->count = 1;
        q->next = NULL;
        if (head == NULL)
        {
            head = tail = q;
        }
        else
        {
            if (search_word(head, q->word) != NULL)
            {
                (search_word(head, q->word)->count)++;
            }
            else
            {
                head = insert_point(head, q);
            }
        }
        q = (link *)malloc(sizeof(link));
    }
    q = head;
    link *temp;
    while (q != NULL)
    {
        temp = q;
        printf("%s %d\n", q->word, q->count);
        q = q->next;
        free(temp);
    }
    return 0;
}
