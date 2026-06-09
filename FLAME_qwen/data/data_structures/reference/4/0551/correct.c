#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
char temp[200], sentence[200];
int begin, end, i, len, j, sum = 0, flag; 
struct word
{
    char a[200];
    int time;
} words[1000];
int comp(const void *p1, const void *p2);
void getword();
void putword();
int main()
{
    freopen("article.txt", "r", stdin);
    while (gets(sentence) != NULL)
    {
        begin = -1;
        end = -1;
        len = strlen(sentence);
        for (i = 0; i <= len; i++)
        {
            if (isalpha(sentence[i]) && begin == -1)
            {
                begin = i;
            }
            if ((!isalpha(sentence[i]) || i == len) && begin != -1)
            {
                end = i - 1;
                getword();
                begin = -1;
                putword();
            }
        }
    }
    qsort(words, sum, sizeof(words[0]), comp);
    for (i = 0; i < sum; i++)
    {
        printf("%s %d\n", words[i].a, words[i].time);
    }
    return 0;
}
int comp(const void *p1, const void *p2)
{
    return strcmp(((struct word *)p1)->a, ((struct word *)p2)->a);
}
void getword()
{
    int i, j = 0;
    for (i = begin; i <= end; i++)
    {
        temp[j++] = tolower(sentence[i]);
    }
    temp[j] = '\0';
    return;
}
void putword()
{
    flag = 0;
    for (j = 0; j < sum; j++)
    {
        if (strcmp(words[j].a, temp) == 0)
        {
            flag = 1;
            words[j].time++;
            break;
        }
    }
    if (!flag)
    {
        strcpy(words[sum].a, temp);
        words[sum].time++;
        sum++;
    }
    return;
}

