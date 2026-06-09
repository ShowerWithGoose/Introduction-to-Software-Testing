#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct wordci {
    char word[32];
    int ci;
};

int compare(const void *a, const void *b)
{
    struct wordci *wc1=(struct wordci *)a;
    struct wordci *wc2=(struct wordci *)b;
    return strcmp(wc1->word, wc2->word);
}
int getword(FILE *fp, struct wordci wc[],int num)
{
    char ch;
    int len=0;
    while((ch=fgetc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            wc[num].word[len]=tolower(ch);
            len++;
        }
        else if(!isalpha(ch)&&len>0)
        {
            wc[num].word[len]='\0';
            return 1; // @@ [The function getword never returns inside the loop for non-alphabetic characters after a word, causing infinite loop or undefined behavior. Also, it doesn't handle EOF properly when ending with a word.]
        }
    }
    if(len>0) { // @@ [Missing handling of last word in file if file doesn't end with non-alphabetic character.]
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Function should return 0 when no more words to read, but original always returns 1 leading to infinite loop in main.]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    if (fp == NULL) return 1; // @@ [Missing check for file open failure which may cause crash, though not directly causing compilation error.]
    while(getword(fp,wc,num)==1)
    {
        num++;
        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ [Accessing wc[num] before it's fully initialized; also logic flaw: comparing new word against itself after incrementing num.]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1;
            num++; // @@ [num is incremented twice per word: once before the loop and once here, causing skipped slots and out-of-sync indexing.]
        }
    }
    fclose(fp);
    qsort(wc,num,sizeof(struct wordci),compare);
    for(int i=0;i<num;i++)
    {
        printf("%s %d\n", wc[i].word, wc[i].ci);
    }
    return 0;
}