#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct WORD
{
    char word[100];
    int fre;
} WORD;
char lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return c;
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return '\0';
}
int CmpName(const void *a, const void *b)
{
    WORD *pa = (WORD *)a;
    WORD *pb = (WORD *)b;

    return strcmp(pa->word, pb->word);
}
int main()
{
    FILE *in;
    if ((in = fopen("article.txt", "r")) == NULL)
    {
        printf("Can't open file article.txt!\n");
        return 1;
    }
    WORD word[1000];
    int n = 0, k = 0;
    char c;
    while (fscanf(in, "%c", &c) != EOF)
    {
        c = lower(c);
        if (c != '\0')
        {
            word[n].word[k] = c;
            k++;
            continue;
        }
        else
        {
            if (strlen(word[n].word) == 0)
            {
                k = 0;
                continue;
            }
            k = 0;
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(word[n].word, word[i].word) == 0)
            {
                word[i].fre++;
                flag = 1;
                int j = strlen(word[n].word);
                if (j != 0)
                {
                    for (int h = 0; h < j; h++)
                    {
                        word[n].word[h] = '\0';
                    }
                }
            }
        }
        if (flag == 0)
        {
            word[n].fre = 1;
            n++;
        }
    }

    qsort(word, n, sizeof(WORD), CmpName);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", word[i].word, word[i].fre);
    }
    fclose(in);
    return 0;
}


