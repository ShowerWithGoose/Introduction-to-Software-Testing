#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct word
{
    char s[100];
    int cnt;
} Word;

int cmp(const void *, const void *);

int main()
{
    FILE *f1;
    f1 = fopen("article.txt", "r");
    Word w[1000];
    for (int i = 0; i < 1000; i++)//初始化单词结构体数组
    {
        w[i].s[0] = 0;
        w[i].cnt = 1;
    }
    char ch;
    int i = 0, j = 0;
    ch = fgetc(f1);
    while (ch != EOF)//读取单词
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            w[i].s[j] = tolower(ch);//转换为小写字母
            j++;
        }
        else
        {
            if (w[i].s[0] != 0)
                i++;
            j = 0;
        }
        ch = fgetc(f1);
    }
    qsort(w, i, sizeof(Word), cmp);//按字典序排序
    for (j = 0; j < i; j++)
    {
        if (strcmp(w[j].s, w[j + 1].s) == 0)
        {
            w[j + 1].cnt += w[j].cnt;
            w[j].cnt = 0;
        }
    }
    for (j = 0; j < i; j++)
    {
        if (w[j].cnt)
            printf("%s %d\n", w[j].s, w[j].cnt);
        else
            continue;
    }
    fclose(f1);
    return 0;
}

int cmp(const void *p1, const void *p2)
{
    Word *a = (Word *)p1;
    Word *b = (Word *)p2;
    return strcmp(a->s, b->s);
}

