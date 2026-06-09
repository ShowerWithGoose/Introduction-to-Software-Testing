#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct list
{
    char a[20];
    int count;
    struct list *link;
} * first, *p, *q, *r;
char temp[1024];
int main()
{
    int len, i, j;
    FILE *in;
    first = p = q = r = NULL;
    in = fopen("article.txt", "r");
    while (fgets(temp, 1024, in) != NULL)
    {
        len = strlen(temp);
        for (i = 0, j = 0; i < len; i++, j = 0)
        {
            q = (struct list *)malloc(sizeof(struct list));
            q->count = 0;
            q->link = NULL;
            while (1)
            {
                if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z'))
                {
                    q->a[j++] = tolower(temp[i]);
                    i++;
                    continue;
                }
                else
                {
                    if (j < 1)
                    {
                        free(q);
                        break;
                    }
                    q->count++;
                    q->a[j] = '\0';
                    if (first == NULL)
                    {
                        first = p = r = q;
                    }
                    else
                    {
                        for (p = first; p != NULL; r = p, p = p->link)
                        {
                            if (strcmp(q->a, p->a) < 0)
                            {
                                if (p == first)
                                {
                                    q->link = first;
                                    first = q;
                                    break;
                                }
                                else
                                {
                                    q->link = p;
                                    r->link = q;
                                    break;
                                }
                            }
                            else if (strcmp(q->a, p->a) == 0)
                            {
                                p->count++;
                                free(q);
                                break;
                            }
                        }
                        if (p == NULL)
                            r->link = q;
                    }
                }
                break;
            }
        }
    }
    for (p = first; p != NULL; p = p->link)
    {
        printf("%s %d\n", p->a, p->count);
    }
    return 0;
}
