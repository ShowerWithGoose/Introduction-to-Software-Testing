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
    words[num].times++; // @@ [words[num].times is uninitialized; it should be set to 1 instead of incrementing an undefined value]
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
    return 1; // @@ [The comparison function does not return 0 when strings are equal, violating the requirement of qsort's comparison function which must return negative, zero, or positive. This leads to undefined behavior in sorting.]
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
        for(int i=0; i<l-1; i++) // @@ [Loop condition skips the last character of each line, which may cause the last word in a line (if not followed by newline) to be missed or truncated]
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
    char c[4]={'buy'}; // @@ [Incorrect initialization of string literal; should be char c[] = "buy"; or similar. This initializes only first element to 'b' and others to 0, but comparison may still work accidentally. However, it's poor practice and may lead to confusion. More critically, hardcoding output like this violates problem requirements.]
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0)
        {
            printf("%s 5\n",words[i].word); // @@ [Hardcoded output for specific word "buy" breaks general functionality and violates problem specification which requires counting from input file]
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}