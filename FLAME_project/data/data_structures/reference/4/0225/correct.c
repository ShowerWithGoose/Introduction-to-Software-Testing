#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char word[100];
int wLen = 0;
char words[10000][100];
int wLens = 0;
int cnt[10000];
void add()
{
    for (int i = 0; i < wLens; i++)
    {
        if (strcmp(word, words[i]) == 0)
        {
            cnt[i]++;
            return;
        }
    }
    cnt[wLens]++;
    strcpy(words[wLens++], word);
}

int main()
{
    FILE* fp;
    fp = fopen("article.txt", "r");
    char ch;
    int b = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (wLen == 0 && isalpha(ch))
        {
            b = 1;
        }
        if (b)
        {
            if (isalpha(ch))
            {
                word[wLen++] = tolower(ch);
            }
            else
            {
                word[wLen] = '\0';
                add();
                wLen = 0;
                b = 0;
            }
        }
    }
    fclose(fp);
    char t[100];
    int T;
    for (int i = 0; i < wLens - 1; i++)
    {
        for (int j = i + 1; j < wLens; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                strcpy(t, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], t);
                T = cnt[i];
                cnt[i] = cnt[j];
                cnt[j] = T;
            }
        }
    }
    for (int i = 0; i < wLens; i++)
    {
        printf("%s %d\n", words[i], cnt[i]);
    }
    return 0;
}


