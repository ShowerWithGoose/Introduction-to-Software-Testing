#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 30
#define MAXAMOUNT 4000

struct article_new
{
    char word[MAXWORD];
    int num;
} article_index[MAXAMOUNT];
//二分查找
int bin_search(char *input, int tail)
{
    int head = 0, mid;
    while (head <= tail)
    {
        mid = (head + tail) / 2;
        if (!strcmp(input, article_index[mid].word))
        {
            article_index[mid].num++;
            return -1; //频数增加
        }
        else if (strcmp(input, article_index[mid].word) > 0)
            head = mid + 1;
        else
            tail = mid - 1;
    }
    return tail;
}
//插入
int insert_Word(char *input, int tail)
{
    int mid;
    if ((mid = bin_search(input, tail)) >= 0)
    {
        int i = tail;
        for (; i > mid; i--)
        {
            strcpy(article_index[i + 1].word, article_index[i].word);
            article_index[i + 1].num = article_index[i].num;
        }
        i++;
        strcpy(article_index[i].word, input);
        return (article_index[i].num = 1);
    }
    return 0;
}
//输入
int input(FILE *in)
{
    int tail = 0, c, i = 0, flag = 0;
    char input[MAXWORD];
    while ((c = fgetc(in)) != EOF)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            input[i++] = tolower(c);
            flag = 1;
        }
        else if (flag)
        {
            input[i] = 0;
            tail += insert_Word(input, tail);
            memset(input, 0, MAXWORD);
            i = flag = 0;
        }
    }
    tail += insert_Word(input, tail);
    return tail;
}

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");

    int max, i = 1;
    max = input(in);
    for (; i <= max; i++)
        printf("%s %d\n", article_index[i].word, article_index[i].num);
}


