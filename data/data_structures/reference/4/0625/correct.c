#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct w
{
    char *word;
    int num;
    struct w *Next;
} Word;

void Insert(char *a, Word *head);

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    Word *head = (Word *)malloc(sizeof(Word));
    head->Next = NULL;
    char c = 0;
    while ((c = fgetc(in)) != EOF)
    {
        if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        {
            char a[40];
            int i = 0;
            for (; (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'); i++)
            {
                if (c <= 'Z' && c >= 'A')
                {
                    c = c - 'A' + 'a';
                }
                a[i] = c;
                c = fgetc(in);
            }
            a[i] = '\0';
            Insert(a, head);
        }
    }
    fclose(in);
    Word *p = head->Next;
    while (p != NULL)
    {
        printf("%s %d\n", p->word, p->num);
        p = p->Next;
    }
    return 0;
}

void Insert(char *a, Word *head)
{
    if (head->Next == NULL)
    {
        Word *p = (Word *)malloc(sizeof(Word));
        p->num = 1;
        p->Next = NULL;
        p->word = (char *)malloc(sizeof(char));
        for (int i = 0; a[i] != '\0'; i++)
        {
            *(p->word + i) = a[i];
            *(p->word + i + 1) = '\0';
        }
        head->Next = p;
    }
    else
    {
        Word *p = head;
        Word *q = p;
        p = p->Next;
        while (p != NULL)
        {
            int k = strcmp(p->word, a);
            if (k == 0)
            {
                p->num++;
                return;
            }
            else if (k > 0)
            {
                Word *r = (Word *)malloc(sizeof(Word));
                r->num = 1;
                r->Next = NULL;
                r->word = (char *)malloc(sizeof(char));
                for (int i = 0; a[i] != '\0'; i++)
                {
                    *(r->word + i) = a[i];
                    *(r->word + i + 1) = '\0';
                }
                q->Next = r;
                r->Next = p;
                return;
            }
            q = p;
            p = p->Next;
        }
        Word *r = (Word *)malloc(sizeof(Word));
        r->num = 1;
        r->Next = NULL;
        r->word = (char *)malloc(sizeof(char));
        for (int i = 0; a[i] != '\0'; i++)
        {
            *(r->word + i) = a[i];
            *(r->word + i + 1) = '\0';
        }
        q->Next = r;
        return;
    }
}



