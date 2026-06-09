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

    while (fscanf(in, "\n%s", &word[n].word) != EOF) // @@ [fscanf with %s does not properly extract only alphabetic words and fails to convert uppercase to lowercase; it also doesn't handle non-alphabetic delimiters correctly as per problem definition]
    {

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(word[n].word, word[i].word) == 0) // @@ [word[n].word may contain mixed case or non-alphabetic characters because fscanf doesn't sanitize input; also, comparison is case-sensitive which violates the requirement to treat words case-insensitively]
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