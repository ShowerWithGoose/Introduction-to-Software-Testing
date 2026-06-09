#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
char words[1000][30];
char times[1000];
int index[1000];
int Cmp(const void *pa, const void *pb)
{
    return (strcmp(words[*((int *)pa)], words[*((int *)pb)]));
}

int main(void)
{
    FILE *fin = fopen("article.txt", "r");
    char str[1000];
    char wordtemp[30];
    int i, j, k, count;
    while (fgets(str, 1000, fin) != NULL)
    {
        int len = strlen(str);
        for (i = 0; i < len; i++)
            str[i] = tolower(str[i]);
        for (i = 0; i < len;)
        {
            if (isalpha(str[i]))
            {
                j = 0;
                while (isalpha(str[i]))
                {
                    wordtemp[j] = str[i];
                    i++;
                    j++;
                }
                wordtemp[j] = '\0';
                // printf("%s\n", wordtemp);
                for (k = 0; k < count; k++)
                {
                    if (strcmp(words[k], wordtemp) == 0)
                    {
                        times[k]++;
                        break;
                    }
                }
                if (k == count)
                {
                    strcpy(words[count], wordtemp);
                    index[count] = count;
                    times[count]++;
                    count++;
                }
            }
            else
                i++;
        }
    }
    qsort(index, count, sizeof(int), Cmp);
    for (i = 0; i < count; i++)
    {
        printf("%s %d\n", words[index[i]], times[index[i]]);
    }
    return 0;
}


