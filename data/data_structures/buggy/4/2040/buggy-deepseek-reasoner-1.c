#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct Word
{
    char word[20];
    int cnt;
};

void tolow(char line[]);
void rise(const void *p1, const void *p2); // @@ error: function prototype declares void return, but definition returns int; should be 'int rise(...)'
void delete(char line[]);

int main()
{
    FILE *article = fopen("article.txt", "r");

    char line[1000];
    struct Word word[10000];

    for (int i = 0, j = 0; i < 10000; i++, j++)
    {
        word[i].cnt = 0;
        if (j < 20)
            word[i].word[j] = '\0'; // @@ error: only sets the j-th character, leaving other characters uninitialized; should set word[i].word[0]='\0' for each i
    }

    int num = 0;
    char get[20];
    int q = 0 , p = 0;
    while (fgets(line, 1000, article) != NULL)
    {

        tolow(line);
        delete (line);

        for (int i = 0; i < 20; i++)
        {
            get[i] = '\0'; // 初始化
        }

        // 取单词
        int pos = 0, k = 0, len = strlen(line);
        while (pos < len)
        {
            // 最后一个单词之前
            if (line[pos] != ' ')
            {
                get[k] = line[pos]; // 暂存
                k++;
            }
            else if (get[0] != '\0')
            {
                get[k] = '\0';
                k = 0;

                // 将get加入count
                q = 0;
                for (int i = 0; i <= num; i++) // @@ error: loop should be i < num to avoid comparing with uninitialized slot
                {
                    if (strcmp(word[i].word, get) == 0)
                    {
                        word[i].cnt++;
                        q = 1;
                        break;
                    }
                }
                if (q == 0)
                {
                    strcpy(word[num].word, get);
                    word[num].cnt++;
                    num++;
                }
                tozero(get); // @@ error: function 'tozero' is not defined; will cause compilation error
            }
            pos++;

            // 最后一个单词
            if (pos == len)
            {
                if (get[0] != '\0')
                {
                    get[k] = '\0';
                    k = 0;

                    // 将get加入count
                     p = 0;
                    for (int i = 0; i <= num; i++) // @@ error: loop should be i < num
                    {
                        if (strcmp(word[i].word, get) == 0)
                        {
                            word[i].cnt++;
                            p = 1;
                            break;
                        }
                    }
                    if (p == 0)
                    {
                        strcpy(word[num].word, get);
                        word[num].cnt++;
                        num++;
                    }
                    tozero(get); // @@ error: same missing function
                }
            }
        }
    }

    qsort(word, num, sizeof(struct Word), rise);
    for (int i = 0; i < num; i++)
    {
        printf("%s %d\n", word[i].word, word[i].cnt);
    }

    fclose(article);
    return 0;
}

void tolow(char line[])
{
    int len = strlen(line);
    for (int i = 0; i < len; i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            line[i] = tolower(line[i]);
        }
    }
}

void delete(char line[])
{
    int len = strlen(line);
    for (int i = 0; i < len; i++)
    {
        if ((line[i] < 'a' || line[i] > 'z') && line[i] != ' ')
        {
            line[i] = ' ';
        }
    }
}

int rise(const void *p1, const void *p2)
{
    struct Word *d1 = (struct Word *)p1;
    struct Word *d2 = (struct Word *)p2;
    if (strcmp(d1->word, d2->word) < 0)
        return -1;
    else if (strcmp(d1->word, d2->word) > 0)
        return 1;
    else
        return 0;
}