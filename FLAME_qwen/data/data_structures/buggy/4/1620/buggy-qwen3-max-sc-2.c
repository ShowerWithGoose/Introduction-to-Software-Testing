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
            return 1; // @@ [The function getword never returns after reading a word, causing infinite loop. It should return 1 here to signal a word was read.]
        }
    }
    if(len>0) // @@ [If file ends with a word (no trailing non-alpha), this word is never null-terminated nor returned. Need to handle EOF case with pending word.]
    {
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [When EOF is reached and no word is being built, should return 0 to stop main loop. Original always returns 1 causing infinite loop.]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    while(getword(fp,wc,num)==1)
    {
        num++;
        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ [wc[num] is uninitialized or contains leftover data; the newly read word is stored at index 'num' before incrementing, but after num++, wc[num] is out of current valid range. Should compare wc[i] with wc[num-1].]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ [After num++ above, wc[num] is beyond the last added word. The new word is already stored in wc[num-1] by getword, so this should be wc[num-1].ci = 1; Also, num is incremented again below, leading to double increment.]
            num++; // @@ [num is already incremented at start of loop body; incrementing again here skips indices and causes incorrect indexing.]
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