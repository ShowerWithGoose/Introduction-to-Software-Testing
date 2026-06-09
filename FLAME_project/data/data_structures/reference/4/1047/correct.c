#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct node
{
    char self[20];
    int frequency;
    struct node *next;
} word;
void insert(char *, word *);
int main()
{
    FILE *in = fopen("article.txt", "r");
    word *head = (word *)malloc(sizeof(word));
    head->next = NULL;
    char s[200];
    while (fgets(s, 200, in))
    {
        int i = 0;
        while (1)
        {
            char w[20];
            while (!isalpha(s[i]) && s[i] != '\n')
                i++;
            if (s[i] == '\n')
                break;
            int j = 0;
            for (; isalpha(s[i]); i++, j++)
                w[j] = tolower(s[i]);
            w[j] = '\0';
            insert(w, head);
        }
    }
    fclose(in);
    while (head->next)
    {
        word *tmp = head;
        head = head->next;
        free(tmp);
        printf("%s %d\n", head->self, head->frequency);
    }
    return 0;
}
void insert(char *s, word *head)
{
    word *p, *q;
    for (p = head->next, q = head; p; q = p, p = p->next)
    {
        if (!strcmp(p->self, s))
        {
            p->frequency++;
            break;
        }
        else if (strcmp(p->self, s) > 0)
        {
            word *NewWord = (word *)malloc(sizeof(word));
            strcpy(NewWord->self, s);
            NewWord->frequency = 1;
            q->next = NewWord;
            NewWord->next = p;
            break;
        }
    }
    if (!p)
    {
        word *NewWord = (word *)malloc(sizeof(word));
        strcpy(NewWord->self, s);
        NewWord->frequency = 1;
        NewWord->next = NULL;
        q->next = NewWord;
    }
}


