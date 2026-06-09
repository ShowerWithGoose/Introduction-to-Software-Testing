#include <stdio.h>
#include <string.h>
struct WORD
{
    int times;
    char word[30];
} words[10000];
int num;//单词种类数
void append(char *str)
{
//把读入的单词插入数组
    for (int i = 0; i < num; i++)
    {
        if (strcmp(words[i].word, str) == 0)
        {
            words[i].times++;
            return;
        }
    }
    words[num].times++; // @@ [words[num].times is uninitialized; it should be set to 1, not incremented]
    strcpy(words[num].word, str);
    num++;
}
int cmp(void const *a, void const *b)
{
    int x;
    x = strcmp((*(struct WORD *) a).word, (*(struct WORD *) b).word);
    if (x < 0)
    {
        return -1;
    }
    return 1; // @@ [incorrect comparison function: when x == 0, it returns 1 instead of 0, breaking qsort contract]
}
int main()
{
    int len=0,l;
    FILE *fp1=fopen("article.txt","r"); // @@ [no check if file opened successfully; may cause segmentation fault if file doesn't exist]
    char s[140],word[20];
    while(fgets(s,sizeof(s),fp1)!=NULL)
    {
        l=strlen(s);
        len=0;
        for(int i=0; i<l-1; i++) // @@ [loop stops at l-2, skipping last character which may be part of a word if line doesn't end with newline]
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                word[len]=s[i]+32;
                len++;
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                word[len]=s[i];
                len++;
            }
            else
            {
                word[len]='\0';
                if(len>=1)
                {
                    append(word);
                }
                len=0;
            }
        }
    }
    qsort(words, num, sizeof(struct WORD), cmp);
    char c[4]={'buy'}; // @@ [incorrect initialization: 'buy' is a multi-character constant and only initializes c[0]; rest are zero, so c becomes "b\0\0\0", not "buy"]
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0) // @@ [due to incorrect c initialization, this condition will never match "buy"]
        {
            printf("%s 5\n",words[i].word);
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}