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
            return 1; // @@ [The function should return after reading a complete word to allow processing in main(), otherwise it reads the entire file in one call and returns only once]
        }
    }
    if(len>0) // @@ [If file ends with a word (no trailing non-alpha), this word won't be null-terminated or returned]
    {
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Should return 0 when EOF is reached and no more words to read, but original always returns 1 causing infinite loop]
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
        for(int i=0;i<num;i++) // @@ [Loop includes the newly added word at index 'num' which hasn't been initialized properly yet; also compares against itself]
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ [wc[num] is out-of-bounds; valid indices are 0 to num-1. This causes undefined behavior]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1;
            num++; // @@ [num is incremented twice per word: once before the loop and once here, leading to skipping entries and double-counting]
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