#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct
{
    char wd[20];
    int n;
} word;
int cmp_word(const void *_a, const void *_b)
{
    word *a = (word *)_a;
    word *b = (word *)_b;
    return strcmp(a->wd, b->wd);
}
word a[200];
char ch, wd[20];
int cnt;
int main()
{
    freopen("article.txt", "r", stdin);
    while (scanf("%c", &ch) != EOF)
    {
        if (isalpha(ch))
        {
            int i = 0;
            while (isalpha(ch))
            {
                wd[i++] = tolower(ch);
                ch = getchar();
            }
            for (i = 0; i < cnt && strcmp(wd, a[i].wd); i++)
                ;
            a[i].n++;
            if (i == cnt)
            {
                strcpy((a[cnt].wd), wd);
                cnt++;
            }
            memset(wd,0,sizeof(wd));
        }
    }
    qsort(a, cnt, sizeof(a[0]), cmp_word);
    for (int i = 0; i < cnt; i++)
        printf("%s %d\n", a[i].wd, a[i].n);
    return 0;
}

