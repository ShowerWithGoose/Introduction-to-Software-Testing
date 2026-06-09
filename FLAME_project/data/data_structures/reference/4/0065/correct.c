#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct rrr
{
    char word[50];
    int times;
    struct rrr *next;
} words;
words *insertword(words *begin, words *g); ////插入单词，中间和尾返回空，头返回新的头指针
int getword(FILE *fp, char *k);            ////录入一个单词，成功返回1，失败返回EOF
int search(words *tou, char *k);           ////传入单词指针，在单词表里找,找到返回1，否则返回-1
FILE *in;
int main()
{
    char word[50];
    words *first = NULL, *q = NULL, *p = NULL, *mid = NULL;
    in = fopen("article.txt", "r");
    while (getword(in, word) != EOF)
    {
        if (first == NULL)
        {
            first = (words *)malloc(sizeof(words));
            strcpy(first->word, word);
            first->times = 1;
            first->next = NULL;
        }
        else
        {
            if (search(first, word) == EOF) //没重复
            {
                p = (words *)malloc(sizeof(words));
                strcpy(p->word, word);
                p->times = 1;
                p->next = NULL;
                mid = insertword(first, p);
                if (mid != NULL)
                    first = mid;
            }
        }
        memset(word, '\0', 50);
    }
    for (q = first; q != NULL; q = q->next)
    {
        printf("%s %d\n", q->word, q->times);
    }
    fclose(in);
    return 0;
}

int getword(FILE *fp, char *k)
{
    int c;
    while (!isalpha(c = fgetc(fp)))
    {
        if (-1 == c)
            return c;
        else
            continue;
    }
    do
    {
        *k = tolower(c);
        k++;
    } while (isalpha(c = fgetc(fp)));
    *k = '\0';
    return 1;
}
words *insertword(words *begin, words *g)
{
    words *q = begin, *before = NULL;
    while ((strcmp(g->word, q->word) > 0))
    {
        before = q;
        q = q->next;
        if (q == NULL)
            break;
    }
    if (before != NULL) //尾插
    {
        g->next = q;
        before->next = g;
        return NULL;
    }
    else //头插
    {
        g->next = q;
        return g;
    }
}
int search(words *tou, char *k)
{
    for (; tou != NULL; tou = tou->next)
    {
        if (strcmp(tou->word, k) == 0)
        {
            tou->times++;
            return 1;
        }
    }
    return EOF;
}


