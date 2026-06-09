#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    char word[50];
    int count;
} Word;
Word voca[1000];
void GetAndChange(FILE *file, char *str);
void SearchWord(char *str, Word *voca);
int cmp(const void *p1, const void *p2);
char str[10000];
char linshi[100];
int cnt;
int main()
{
    FILE *fp1 = fopen("article.txt", "r");
    GetAndChange(fp1, str);
    SearchWord(str, voca);
    qsort(voca, cnt, sizeof(Word), cmp);
    int i, j;
    int flag = 0;
    for (i = 0; i < cnt; i++)
    {
        voca[i].count = 1;
    }
    /*for (i = 0; i < cnt; i++)
    {
        if (strcmp(voca[i].word, voca[i+1].word) == 0)
        {
            voca[i+1].count +=voca[i].count;
            voca[i].count = 0;
        }
    }
    qsort(voca, cnt, sizeof(Word), cmp);
    for (i = 0; i < cnt; i++)
    {
        if (voca[i].count == 0)
            continue;
        else
            printf("%s %d\n", voca[i].word, voca[i].count);
    }*/
    for (i = 0; i < cnt; i++)
    {
        for (j = i + 1; j < cnt; j++)
        {
            if (strcmp(voca[i].word, voca[j].word) == 0)
            {
                voca[j].count += voca[i].count;
                voca[i].word[0] = '0';
                flag++;            }
        }
    }
    qsort(voca, cnt, sizeof(Word), cmp);
    for(i=flag;i<cnt;i++)
    {
        printf("%s %d\n",voca[i].word, voca[i].count);
    }
    return 0;
}
void GetAndChange(FILE *file, char *str)
{
    char ch;
    int i = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
            str[i] = ch;
        }
        else
        {
            str[i] = ch;
        }
        i++;
    }
    str[i] = '\0';
}
void SearchWord(char *str, Word *voca)
{
    int len = strlen(str);
    int i, j, k;
    for (i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            for (j = i; j < len; j++)
            {
                if (str[j] < 'a' || str[j] > 'z')
                    break;
            }
            for (k = 0; k < j - i; k++)
            {
                voca[cnt].word[k] = str[k + i];
            }
            cnt++;
            i = j;
        }
        else
            continue;
    }
}
int cmp(const void *p1, const void *p2) //根据字典序排序
{
    Word *a = (Word *)p1;
    Word *b = (Word *)p2;
    return strcmp(a->word, b->word);
}

