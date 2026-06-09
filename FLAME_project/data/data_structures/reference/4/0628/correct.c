#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define lower(a) (65 <= a && a <= 90 ? a + 32 : a)
typedef long long LL;

struct word
{
    int t;
    char *s;
    struct word *next;
} list;
char s[100];

int myFread(FILE **fp, char *s)
{
    int len = 0;
    char ch = fgetc(*fp);
    while (!isalpha(ch))
    {
        if (ch == EOF)
            return -1;
        ch = fgetc(*fp);
    }
    while (isalpha(ch))
    {
        if (ch == EOF)
            return -1;
        s[len++] = lower(ch);
        ch = fgetc(*fp);
    }
    s[len] = '\0';
    return 0;
}

int main()
{
    FILE *fp = fopen("article.txt", "r");
    struct word *wordP, *tmp;
    list.s = "A", list.next = NULL;
    while (~myFread(&fp, s))
    {
        for (wordP = &list; wordP != NULL; wordP = wordP->next)
        {
            if (strcmp(wordP->s, s) == 0)
            {
                ++(wordP->t);
                break;
            }
            if (strcmp(wordP->s, s) < 0 && (wordP->next == NULL || strcmp(wordP->next->s, s) > 0))
            {
                tmp = malloc(sizeof(struct word));
                tmp->s = malloc(sizeof(char) * strlen(s));
                strcpy(tmp->s, s), tmp->t = 1;
                tmp->next = wordP->next, wordP->next = tmp;
                break;
            }
        }
    }
    for (wordP = list.next; wordP != NULL; wordP = wordP->next)
        printf("%s %d\n", wordP->s, wordP->t);
    return 0;
}
