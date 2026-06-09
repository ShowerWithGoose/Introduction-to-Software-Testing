#include <stdio.h>
#include <string.h>
#define N 5000
#define LEN 15
// char letter[N][LEN];
char str[N];
struct lett
{
    char word[LEN];
    int num;
} letter[N];
void swap(struct lett *a, struct lett *b)
{
    struct lett temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int main()
{
    FILE *fin;
    int i1 = 0; //计数letter行
    int i2 = 0; // 计数letter列
    int j = 0;  //计数str
    fin = fopen("article.txt", "r");
    while ((fgets(str, N, fin)) != NULL)
    {
        while (str[j] != '\0')
        {
            int flag = 0;
            while ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z'))
            {
                flag = 1;
                if (str[j] >= 'A' && str[j] <= 'Z')
                {
                    str[j] = str[j] - 'A' + 'a';
                }
                letter[i1].word[i2++] = str[j];
                j++;
            }
            if (flag == 1)
            {
                letter[i1].word[i2] = '\0';
                letter[i1].num = 1;
                i1++;
                i2 = 0;
            }
            j++;
        }
        j = 0;
    }
    int cnt = 0; //计数最后总共个数
    for (int i = 0; i < i1; i++)
    {
        for (int j = 0; j < i1 - i - 1; j++)
        {
            if (strcmp(letter[j].word, letter[j + 1].word) > 0)
            {
                swap(&letter[j], &letter[j + 1]);
            }
        }
    }
    for (int j = 0; j < i1; j++)
    {
        while (strcmp(letter[j].word, letter[j + 1].word) == 0)
        {
            letter[j+1].num=letter[j+1].num+letter[j].num;
            // cnt++;
            letter[j].word[0] = '\0';
            j++;
        }
    }

    for (int k = 0; k < i1; k++)
    {
        // printf("%d",letter[k].num);
        if (letter[k].word[0] != '\0')
            printf("%s %d\n", letter[k].word, letter[k].num);
    }
}
