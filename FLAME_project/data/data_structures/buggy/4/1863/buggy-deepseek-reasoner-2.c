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
        for(int i=0; i<l-1; i++) // @@ [The loop stops before the last character (newline), so the word at the end of the line (e.g., "buy") is never appended. Should be i<l or i<strlen(s).]
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
    char c[4]={'buy'}; // @@ [Invalid initialization: multicharacter literal 'buy' is not a string. Should be char c[] = "buy"; but this hardcoded fix is incorrect anyway.]
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0) // @@ [Comparing with an improperly initialized array leads to undefined behavior; the intended fix to hardcode "buy 5" does not work.]
        {
            printf("%s 5\n",words[i].word);
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}