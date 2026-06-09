#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define in(n) \
    FILE *in; \
    in = fopen(n, "r")
#define out(n) \
    FILE *out; \
    out = fopen(n, "w")

char a[500], w[100];
struct link
{
    char word[100];
    int n;
    struct link *next;
};

int main(int argc, char const *argv[])
{
    in("article.txt");
    struct link *p, *head;
    p = (struct link *)malloc(sizeof(struct link));
    head = (struct link *)malloc(sizeof(struct link));
    head->word[0] = 0;
    p->word[0] = 123;
    head->next = p;
    while (fgets(a, sizeof(a), in) != NULL)
    {
        for (int i = 0, j = 0; a[i] != 0||w[0]!=0; i++)
        {
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                w[j] = a[i];
                j++;
            }
            else if (a[i] >= 'A' && a[i] <= 'Z')
            {
                w[j] = a[i] - 'A' + 'a';
                j++;
            }
            else if(w[0]!=0)
            {
                for (p = head; strcmp(w, p->next->word) > 0; p = p->next)
                    ;
                if (strcmp(w, p->next->word) == 0)
                {
                    (p->next->n)++;
                }
                else
                {
                    struct link *tmp;
                    tmp = (struct link *)malloc(sizeof(struct link));
                    memset(tmp->word, 0, sizeof(tmp->word));
                    strcat(tmp->word, w);
                    tmp->n = 1;
                    tmp->next = p->next;
                    p->next = tmp;
                }
                j = 0;
                memset(w, 0, sizeof(w));
            }
        }
    }
    for (p = head->next; p->word[0] != 123; p = p->next)
    {
        printf("%s %d\n", p->word, p->n);
    }
    return 0;
}

