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
    words[num].times++; // @@ [Logical Error: This line increments the count of the new entry before initializing it. It should be `words[num].times = 1;` to initialize the count for a new word.]
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
        for(int i=0; i<l-1; i++) // @@ [Logical Error: The loop condition `i<l-1` skips the last character of the line. If the last character is part of a word (e.g., a letter before newline or EOF), it will be ignored. It should be `i<l`.]
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
        // @@ [Logical Error: After the loop finishes, if the line ends with a word (not a separator), the last word stored in `word` is not processed because the `append` call is only inside the `else` block for non-alpha characters. Code needs to handle the remaining word after the loop.]
    }
    qsort(words, num, sizeof(struct WORD), cmp);
    char c[4]={'buy'}; // @@ [Syntax/Logic Error: Initializing a string array with single characters like this does not create a valid null-terminated string "buy". It creates an array with 'b', 'u', 'y', '\0' only if explicitly terminated or if size allows, but here `c` is size 4. However, `{'b','u','y'}` would leave the last element uninitialized or zero depending on context, but standard string comparison requires null termination. More importantly, the hardcoding of the answer for "buy" is incorrect logic for a general solution.]
    for(int i=0; i<num; i++)
    {
        if(strcmp(words[i].word,c) == 0)
        {
            printf("%s 5\n",words[i].word); // @@ [Logical Error: Hardcoding the output for "buy" to 5 is incorrect. The program should output the actual calculated frequency `words[i].times`. This masks the underlying bug in counting.]
        }
        else
            printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}