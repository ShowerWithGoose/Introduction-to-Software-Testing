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

    while (fscanf(in, "\n%s", &word[n].word) != EOF) // @@ [fscanf with %s does not skip non-alphabetic characters and does not convert uppercase to lowercase; it reads tokens separated by whitespace, not words as defined (only letters). Also, &word[n].word should be word[n].word since it's already an array.]
    {

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(word[n].word, word[i].word) == 0) // @@ [word[n].word has not been properly normalized to lowercase, so case-sensitive comparison may treat same word differently. Also, at this point, word[n] is uninitialized in structure except possibly from fscanf, but logic flaw: we are comparing before storing or normalizing.]
            {
                word[i].fre++;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            word[n].fre = 1;
            n++; // @@ [Incrementing n after using word[n] in fscanf leads to reading into word[n] then immediately incrementing, but the next iteration uses word[n] (now new index) without initializing fre for existing entries correctly. More critically, the word read is never converted to lowercase.]
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