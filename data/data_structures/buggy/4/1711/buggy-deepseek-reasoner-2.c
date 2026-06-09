#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct WORD
{
    char word[100];
    int fre;
} WORD;
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
    int n = 0;

    while (fscanf(in, "\n%s", &word[n].word) != EOF) // @@ [Error: &word[n].word should be word[n].word because word[n].word is already an array and decays to a pointer; using & gives a pointer to array, causing type mismatch (char (*)[100] vs char *). This can lead to undefined behavior or compilation error.]
    {

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(word[n].word, word[i].word) == 0)
            {
                word[i].fre++;
                flag = 1;
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