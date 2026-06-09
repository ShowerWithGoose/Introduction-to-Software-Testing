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
    while((ch=fgetc(fp))!=EOF) @@ //  Reads entire file in one call; should read one word per call.
    {
        if(isalpha(ch))
        {
            wc[num].word[len]=tolower(ch);
            len++;
        }
        else if(!isalpha(ch)&&len>0)
        {
            wc[num].word[len]='\0'; @@ //  Sets null terminator but does not return; continues reading, overwriting the word.
        }
    }
    return 1; @@ //  Always returns 1, causing infinite loop in main.
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    while(getword(fp,wc,num)==1) @@ //  Infinite loop because getword never returns 0.
    {
        num++; @@ //  Increments num before using wc[num] in duplicate check — accesses uninitialized element.
        int flag=0;
        for(int i=0;i<num;i++) @@ //  Compares against uninitialized wc[num] (since num was incremented).
        {
            if(strcmp(wc[i].word,wc[num].word)==0) @@ //  wc[num] is not yet filled for the new word.
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; @@ //  Writes to wrong index (num already incremented).
            num++; @@ //  Double increment per word — counts each word twice.
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