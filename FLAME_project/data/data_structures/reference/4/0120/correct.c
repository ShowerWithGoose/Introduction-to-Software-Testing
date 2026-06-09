//
//  main.c
//  2
//
//  Created by  on 2021/9/22.
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char str[105][20];
void replace(char str[][20], int n)
{
    char temp[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
            }
        }
    }
}

int main()
{
    FILE *fp1;
    fp1 = fopen("article.txt", "r");

    char ch;
    int i = 0, j = 0, n = 0;
    ch = fgetc(fp1); //输入
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            str[i][j] = ch;
            j++;
        }

        else if (ispunct(ch) || isspace(ch) /*ch == ' ' || ch == '.' || ch == ';' || ch == ',' || ch == ':' */)
        {
            str[i][j] = '\0';
            j = 0;
            i++;
        }

        ch = fgetc(fp1);
    }
    n = i;
    for (int i = 0; i < n; i++) //全变成小写
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        replace(str, n); //排成字典序
    }

    int num[105] = {0}, flag = 0;

    for (int i = 0; i < n; i++) //查重，num为出现次数
    {
        flag = 0;
        num[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (!strcmp(str[i], str[j]))
            {
                num[i]++;
                //strcpy(str[j], '\0');
                str[j][0] = '\0';
                flag = 1;
            }

            if (str[j][0] == '\0')
            {
                continue;
            }

            else
            {
                if (flag == 1)
                {
                    i = j - 1;
                }
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (str[i][0] != '\0')
        {
            printf("%s %d\n", str[i], num[i]);
        }
    }
    fclose(fp1);
    return 0;
}/*
 【问题描述】

 编写程序统计一个英文文本文件中每个单词的出现次数（词频统计），并将统计结果按单词字典序输出到屏幕上。

 注：在此单词为仅由字母组成的字符序列。包含大写字母的单词应将大写字母转换为小写字母后统计。

 【输入形式】

 打开当前目录下文件“article.txt”，从中读取英文单词进行词频统计。


 【输出形式】

 程序将单词统计结果按单词字典序输出到屏幕上，每行输出一个单词及其出现次数，单词和其出现次数间由一个空格分隔，出现次数后无空格，直接为回车。

 【样例输入】

 当前目录下文件article.txt内容如下：


 “Do not take to heart every thing you hear.”

 “Do not spend all that you have.”

 “Do not sleep as long as you want;”


 【样例输出】

 all 1

 as 2

 do 3

 every 1

 have 1

 hear 1

 heart 1

 long 1

 not 3

 sleep 1

 spend 1

 take 1

 that 1

 thing 1

 to 1

 want 1

 you 3*/

