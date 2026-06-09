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
            return 1; // @@ [The function getword does not return after reading a complete word, causing it to continue reading the entire file in one call and never returning control properly to main loop. Also, missing handling of buffer overflow for word length.]
        }
    }
    if(len>0) // @@ [If file ends without non-alpha character, last word won't be null-terminated or returned. Need to handle EOF case with pending word.]
    {
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Should return 0 when no more words to read, but current logic always returns 1 inside loop, breaking main loop condition.]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    if (fp == NULL) return 1; // @@ [Missing check for file open failure which may cause undefined behavior on fgetc.]
    while(getword(fp,wc,num)==1)
    {
        num++;
        int flag=0;
        for(int i=0;i<num;i++) // @@ [Loop includes the newly added word itself (index 'num' before increment), leading to comparing uninitialized or self-data. Should loop only over existing words (i < num - 1).]
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ [wc[num] is out-of-bounds because valid indices are 0 to num-1; after num++ above, wc[num] is beyond current valid data.]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ [Again, wc[num] is out-of-bounds; should assign to wc[num-1] after increment, or better: process before incrementing num.]
            num++; // @@ [Double increment of num: once before loop, once here. This skips entries and causes array misalignment.]
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