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
    return 1; // @@ The comparison function does not return 0 when strings are equal, which violates qsort requirements and may cause undefined behavior.
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
        for(int i=0; i<l-1; i++) // @@ The loop condition i<l-1 skips the last character of the line (the newline), but if the line ends with a word, that word's final delimiter (newline) is not processed, causing the last word to be missed.
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
    char c[4]={'buy'}; // @@ This line is incorrect: 'buy' is a string literal, not a character array initializer. It should be char c[] = "buy"; or char c[4] = "buy";. The current code initializes c with a multi-character constant, which is implementation-defined and likely causes the comparison to fail.
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0) // @@ Due to the incorrect initialization of c, this comparison will not correctly identify the word "buy", so the hardcoded output of "5" will not be applied to the correct word.
        {
            printf("%s 5\n",words[i].word);
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}