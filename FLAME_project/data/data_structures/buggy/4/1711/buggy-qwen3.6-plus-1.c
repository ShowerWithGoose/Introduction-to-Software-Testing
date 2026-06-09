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

    while (fscanf(in, "\n%s", &word[n].word) != EOF) // @@ The format string "\n%s" does not strip punctuation attached to words (e.g., "life.", "you;"), and fscanf does not convert uppercase to lowercase. Words should be processed character by character or cleaned after reading to isolate alphabetic sequences and convert case.
    {

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(word[n].word, word[i].word) == 0) // @@ Comparison fails because words are not normalized (lowercase) and may contain trailing punctuation, leading to incorrect frequency counts and duplicate entries for the same word in different cases or with punctuation.
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
        printf("%s %d\n", word[i].word, word[i].fre); // @@ Output is incorrect because the stored words are not lowercased and may include punctuation, violating the problem requirement that words consist only of letters and are case-insensitive.
    }
    fclose(in);
    return 0;
}