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
            return 1; // @@ [The function getword reads only one word per call but currently doesn't return after reading a word; it continues reading the entire file in one call, causing incorrect behavior. Also, it never returns 0 to break the loop in main().]
        }
    }
    if(len>0) // @@ [If the file ends without a non-alphabetic character, the last word won't be null-terminated or returned.]
    {
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Need to return 0 when EOF is reached and no more words to read, to break the loop in main().]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    if (fp == NULL) return 1; // @@ [Missing check for file open failure, which may cause undefined behavior.]
    while(getword(fp,wc,num)==1)
    {
        num++;
        int flag=0;
        for(int i=0;i<num;i++) // @@ [This loop compares wc[num].word, but wc[num] was just written by getword and then num was incremented, so wc[num] is uninitialized or beyond current valid data. Should process before incrementing num.]
        {
            if(strcmp(wc[i].word,wc[num].word)==0)
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1;
            num++; // @@ [num is incremented twice per word: once before the loop and once here, leading to skipping entries and accessing uninitialized memory.]
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