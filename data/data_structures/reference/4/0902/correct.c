#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct word
{
    int num;
    char wd[100];
} word[500];
char input[1000];
int wordCnt;

void add(int n)
{

    for (int i = 1; i <= wordCnt; i++)
    {
        if (!strcmp(word[i].wd, input + n))
        {
            word[i].num++;
            return;
        }
    }
    strcpy(word[++wordCnt].wd, input + n);
    word[wordCnt].num++;
}

int cmp(const void *p, const void *q)
{
    return strcmp(((struct word *)p)->wd, ((struct word *)q)->wd);
}

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    while (fgets(input, 1000, in) != NULL)
    {
        for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++)
        {
            int j = 0;
            if (isalpha(input[i]))
            {
                while (isalpha(input[i + j]))
                    j++;
                for (int k = i; k < i + j; k++)
                {
                    input[k] = tolower(input[k]);
                }
                input[i + j] = '\0';
                add(i);
                i += j;
            }
        }
    }
    qsort(word + 1, wordCnt, sizeof(struct word), cmp);
    for (int i = 1; i <= wordCnt; i++)
    {
        printf("%s %d\n", word[i].wd, word[i].num);
    }
    fclose(in);
    return 0;
}
