#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    char word[30];
    int count;
} wordfre[1024];
int getWord(FILE *fp, char *w)
{
    int c;
    while (!isalpha(c = fgetc(fp)))
        if (c == EOF)
            return -1;
        else
            continue;
    do
    {
        *w++ = tolower(c);
    } while (isalpha(c = fgetc(fp)));
    *w = '\0';
    return 1;
}
int cmp(const void *p1, const void *p2)
{
    struct node *a = (struct node *)p1;
    struct node *b = (struct node *)p2;
    return strcmp(a->word, b->word);
}
int main()
{
    FILE *fp = fopen("article.txt", "r");
    char word[30];
    int i = 0;
    while (getWord(fp, word) != EOF)
    {
        strcpy(wordfre[i].word, word);
        wordfre[i].count = 1;
        i++;
    }
    int n = i;
    qsort(wordfre, n, sizeof(wordfre[0]), cmp);
    for (i = 0; i < n; i++)
    {
        if (!strcmp(wordfre[i].word, wordfre[i + 1].word))
        {
            wordfre[i + 1].count = wordfre[i].count + 1;
            wordfre[i].count = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (!wordfre[i].count)
            continue;
        else
            printf("%s %d\n", wordfre[i].word, wordfre[i].count);
    }
    return 0;
}
