#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Alpha
{
    char word[1000];
    int num;
    struct Alpha *next;
};
typedef struct Alpha alpha;
int main()
{
    FILE *input;
    int i = 0, len = 0, flag = 0, ch;
    char bet[1000] = {'\0'};
    alpha *list = NULL, *p = NULL, *r = NULL, *oper = NULL;
    input = fopen("article.txt", "rb");
    while ((ch = fgetc(input)) != EOF)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            bet[i] = ch + 32;
            i++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            bet[i] = ch;
            i++;
        }
        else
        {
            if (strlen(bet) != 0)
            {
                oper = (alpha *)malloc(sizeof(alpha));
                memset(oper->word, '\0', sizeof(oper->word));
                strcpy(oper->word, bet);
                oper->num = 1;
                oper->next = NULL;
                memset(bet, '\0', sizeof(bet));
                i = 0;
                if (len == 0)
                {
                    list = (alpha *)malloc(sizeof(alpha));
                    list = oper;
                    len++;
                }
                else if (len == 1)
                {
                    if (strcmp(oper->word, list->word) < 0)
                    {
                        oper->next = list;
                        list = oper;
                        len++;
                    }
                    else if (strcmp(oper->word, list->word) > 0)
                    {
                        list->next = oper;
                        len++;
                    }
                    else
                    {
                        list->num++;
                    }
                }
                else
                {
                    if (strcmp(oper->word, list->word) < 0)
                    {
                        oper->next = list;
                        list = oper;
                        flag = 1;
                        len++;
                    }
                    else if (strcmp(oper->word, list->word) == 0)
                    {
                        list->num++;
                        flag = 1;
                    }
                    for (r = list, p = list->next; p != NULL; r = p, p = p->next)
                    {
                        if (strcmp(oper->word, p->word) == 0)
                        {
                            p->num++;
                            flag = 1;
                        }
                        else if (strcmp(oper->word, r->word) > 0 && strcmp(oper->word, p->word) < 0)
                        {
                            oper->next = p;
                            r->next = oper;
                            flag = 1;
                            len++;
                        }
                    }
                    if (flag == 0)
                    {
                        r->next = oper;
                        len++;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
        }
    }
    for (p = list; p != NULL; p = p->next)
    {
        printf("%s %d\n", p->word, p->num);
    }
    fclose(input);
}
