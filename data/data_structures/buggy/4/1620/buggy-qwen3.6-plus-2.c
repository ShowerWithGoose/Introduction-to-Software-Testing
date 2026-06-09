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
    char ch; // @@ fgetc returns int, using char may cause EOF comparison to fail if char is unsigned.
    int len=0;
    while((ch=fgetc(fp))!=EOF) // @@ Reads the entire file in one call instead of a single word, and always returns 1, causing an infinite loop in main.
    {
        if(isalpha(ch))
        {
            wc[num].word[len]=tolower(ch);
            len++;
        }
        else if(!isalpha(ch)&&len>0)
        {
            wc[num].word[len]='\0'; // @@ Fails to return after successfully reading a word, causing it to overwrite the buffer and continue reading until EOF.
        }
    }
    return 1; // @@ Always returns 1 regardless of whether a word was read or EOF was reached, leading to an infinite loop.
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    while(getword(fp,wc,num)==1) // @@ Loop condition relies on getword returning 1, but getword always returns 1, causing infinite execution.
    {
        num++; // @@ Increments num before checking the word just read, causing subsequent comparisons to access uninitialized wc[num].
        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ Compares with wc[num] which was just incremented and is uninitialized; should compare with the word just read (wc[num-1]).
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1;
            num++; // @@ Increments num again for new words, causing num to increase by 2 per new word and skipping array indices.
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