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

    while (fscanf(in, "\n%s", &word[n].word) != EOF) // @@ [fscanf with %s reads tokens separated by whitespace but does not filter out non-alphabetic characters; punctuation remains attached to words (e.g., "life." instead of "life"), and case is not converted to lowercase]
    {

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(word[n].word, word[i].word) == 0) // @@ [comparison is done before converting the current word to lowercase or removing punctuation, so "Do" and "do" are treated as different words]
            {
                word[i].fre++;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            word[n].fre = 1;
            n++; // @@ [the new word is added without cleaning (lowercasing or stripping punctuation), so words like "pains;" and "you;" remain as-is]
        }
    }
    qsort(word, n, sizeof(WORD), CmpName);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", word[i].word, word[i].fre); // @@ [output uses unprocessed words that may still contain uppercase letters or trailing punctuation, violating the problem's definition of a word]
    }
    fclose(in);
    return 0;
}