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
    words[num].times++;
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
    return 1;
}
int main()
{
    int len=0,l;
    FILE *fp1=fopen("article.txt","r");
    char s[140],word[20];
    while(fgets(s,sizeof(s),fp1)!=NULL)
    {
        l=strlen(s);
        len=0;
        for(int i=0; i<l-1; i++)
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
        } // @@ After processing all characters in the line, any remaining word (e.g., the last word without a following delimiter) is not appended. This causes words at the end of lines to be lost, leading to undercounts (e.g., "buy" counted only once instead of five times).
    }
    qsort(words, num, sizeof(struct WORD), cmp);
    char c[4]={'buy'}; // @@ Invalid initializer; 'buy' is a multi‑character constant, not a string literal. This line should be char c[] = "buy"; or be removed entirely (the hardcoded check should not exist).
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0)
        {
            printf("%s 5\n",words[i].word); // @@ Hardcoding the count to 5 is incorrect and fragile; it should print the actual count from words[i].times.
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}