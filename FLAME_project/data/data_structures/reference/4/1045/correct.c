#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
//qsort大法好=)
char word[10000][100];
int sum = -1;
int cmp(const void *a, const void *b)
{
    char *ai = (char *)a;
    char *bi = (char *)b;
    return strcmp(ai, bi);
}
int main()
{
    FILE *in;
    char a;
    int flag = 0;
    int len;
    in = fopen("article.txt", "r");
    while (fscanf(in, "%c", &a) != EOF)
    {
        if (isalpha(a) && flag == 0)
        {
            if (isupper(a))
                a = tolower(a);
            sum++;
            len = 0;
            flag = 1;
            word[sum][len++] = a;
        }
        else if (isalpha(a) && flag == 1)
        {
            if (isupper(a))
                a = tolower(a);
            word[sum][len++] = a;
        }
        if (isalpha(a) == 0)
        {
            if (flag == 1)
            {
                flag = 0;
                word[sum][len] = '\0';
            }
        }
    }
    sum++;
    qsort(word, sum, sizeof(char[100]), cmp);
    for (int i = 0; i < sum; i++)
    {
        int ans = 1;
        while (i + 1 < sum && strcmp(word[i], word[i + 1]) == 0)
        {
            ans++;
            i++;
        }
        printf("%s %d\n", word[i], ans);
    }
    return 0;
}
