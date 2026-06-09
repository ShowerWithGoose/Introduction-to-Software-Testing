#include <stdio.h>
#include <string.h>
typedef struct word
{
    char ch[100];
    int count;
} word;
int main()
{
    int i = 0, j = 0, a = 0;
    word word[1005];      // 单词清单，用于记录单词
    char list[100000], c; // list用于记录文件中的所有字符，c用于依次读入文件中的字符
    FILE *doc = fopen("article.txt", "r");
    while ((c = fgetc(doc)) != EOF)
    {
        list[i] = c;
        i++;
    }
    int lenth = i, b = 0; // 所有字符的个数
    for (int i = 0; i < lenth;)
    {
        if ((list[i] < 'a' || list[i] > 'z') && (list[i] < 'A' || list[i] > 'Z'))
        {
            i++; // 读入的不是字母，继续读入下一个字符
        }
        else
        {
            b = 0;
            while ((list[i] >= 'a' && list[i] <= 'z') || (list[i] >= 'A' && list[i] <= 'Z'))
            {
                if (list[i] >= 'A' && list[i] <= 'Z') // 读入的字母是大写
                {
                    list[i] = list[i] + 'a' - 'A'; // 变大写为小写
                }
                word[a].ch[b] = list[i];
                b++;
                i++;
            }
            word[a].ch[b] = '\0'; // 字符串结尾置'\0'
            word[a].count = 1;    // 对于第一遍查找的单词个数置1
            for (j = 0; j < a; j++)
            {
                if (strcmp(word[j].ch, word[a].ch) == 0) // 在单词清单中查找到该单词，将其个数加1
                {
                    word[j].count++;
                    break;
                }
            }
            if (j == a)
            {
                a++; // 在单词清单中未发现该单词，将a++
            }
        }
    }
    struct word temp;
    int flag;
    for (int i = 0; i < a; i++)
    {
        flag = 0;
        for (int j = i; j < a; j++)
        {
            if (strcmp(word[i].ch, word[j].ch) > 0)
            {
                temp = word[i];
                word[i] = word[j];
                word[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    } // 冒泡排序法
    for (i = 0; i < a; i++)
    {
        printf("%s %d\n", word[i].ch, word[i].count);
    }
    fclose(doc);
    return 0;
}
