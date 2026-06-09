#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ll long long

typedef struct abc
{
    char s1[200];
    int cnt;
} abc;

void sort(abc a[], int n)
{
    int i, j;
    abc temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(a[j].s1, a[j + 1].s1) > 0)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    FILE *in;
    abc a[10000];
    char hc[200], c;
    in = fopen("article.txt", "r");
    int j = 0, n = 0;
    while ((c = fgetc(in)) != EOF)
    {
        c = tolower(c);
        if (c >= 'a' && c <= 'z')
            hc[j++] = c;
        else if (j - 1 >= 0 && hc[j - 1] != '\0')
        {
            hc[j] = '\0';
            j = 0;
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(hc, a[i].s1) == 0)
                {
                    a[i].cnt++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                strcpy(a[n].s1, hc);
                a[n].cnt = 1;
                n++;
            }
        }
    }

    sort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", a[i].s1, a[i].cnt);
    }

    fclose(in);
    return 0;
}
