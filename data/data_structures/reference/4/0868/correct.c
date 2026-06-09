#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct List
{
    char word[50];
    int time;
} LIST;

LIST words[200]; //单词本

char s[1000];  //存储article
char temp[50]; //暂时存储单个单词

/* 读取所有的文字 并全部变成小写 */
void GetAll(FILE *in);

/* 对单词进行计数 返回有多少个单词*/
int WordOperate();

/* 输出 */
void Output(int n);

/* qsort的cmp函数 */
int cmp(const void *a, const void *b);

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    GetAll(in);
    int len;
    len = WordOperate();
    qsort(words, len, sizeof(LIST), cmp);
    Output(len);
    return 0;
}

void GetAll(FILE *in)
{
    int ch;
    int count = 0;
    while ((ch = fgetc(in)) != EOF)
    {
        if (isalpha(ch))
            ch = tolower(ch);
        s[count] = ch;
        count++;
    }
}

int WordOperate()
{
    int length = strlen(s);
    int front = 0, tail = 0; //记录每个单词的头尾
    int count = 0, i, j;
    for (i = 0; i < length; i++)
    {
        if (isalpha(s[i]))
        {
            {
                ;
                for (j = i + 1; j < length; j++) /* 确定单词的尾部位置 */
                {
                    if (!isalpha(s[j]))
                    {
                        j--;
                        break;
                    }
                }
            }
            int flag = 0;
            memcpy(temp, s + i, sizeof(char) * (j - i + 1)); //将单词提取到temp中
            for (int k = 0; k < count; k++)                  //将单词加入到单词表中
            {
                if (strcmp(words[k].word, temp) == 0) //如果单词出现过 计数器+1
                {
                    words[k].time++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                memcpy(words[count].word, temp, sizeof(char) * (j - i + 1)); //如果单词没有出现过 则加到单词表结尾
                words[count].time = 1;
                count++;
            }
            i = j; //更新i的位置
            memset(temp,'\0', sizeof(temp));
        }
        else
            continue;
    }
    return count;
}

int cmp(const void *a, const void *b)
{
    LIST *p = (LIST *)a, *q = (LIST *)b;
    return strcmp(p->word, q->word);
}

void Output(int n)
{
    for (int i; i < n; i++)
    {
        if (words[i].time == 0)
            continue;
        else
            printf("%s %d\n", words[i].word, words[i].time);
    }
}


