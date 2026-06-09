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
    words[num].times++; // @@ The initial count for a new word should be 1, not incrementing an uninitialized value (which is likely 0, resulting in 1, but logically it should be assignment. However, the bigger issue is that `words[num].times` is not initialized to 0 before this if it's a new slot. But since it's global, it is 0. So `0++` becomes 1. This line is technically okay for initialization due to global scope, but logically `words[num].times = 1;` is clearer. The real error is elsewhere.)
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
        for(int i=0; i<l-1; i++) // @@ The loop condition `i<l-1` skips the last character of the line. If the last character is a letter, it will be ignored. It should be `i<l`.
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
        // @@ After the loop finishes, if the line ends with a letter (no trailing non-alpha), the last word stored in `word` is not processed because the `else` block (which calls `append`) is not triggered for the end of string. We need to check if `len > 0` after the loop and append the last word.
    }
    qsort(words, num, sizeof(struct WORD), cmp);
    char c[4]={'buy'}; // @@ This initialization is incorrect. `{'buy'}` is a multi-character character constant or invalid initializer for char array. It should be `char c[] = "buy";`. Furthermore, hardcoding the output for "buy" is a logical error based on the specific test case failure, suggesting the student tried to patch the output instead of fixing the parsing logic.
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0)
        {
            printf("%s 5\n",words[i].word); // @@ Hardcoding the count for "buy" is incorrect. The count should be derived from the actual frequency calculated.
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}