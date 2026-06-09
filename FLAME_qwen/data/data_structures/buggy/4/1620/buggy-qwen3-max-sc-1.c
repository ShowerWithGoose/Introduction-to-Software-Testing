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
            return 1; // @@ [The function getword never returns after reading a word; it only returns after EOF, causing infinite loop in main. Also, it doesn't handle the last word if file doesn't end with non-alpha.]
        }
    }
    if(len>0) // @@ [Missing handling of last word in file if file ends without trailing non-alphabetic character.]
    {
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Should return 0 at EOF with no word to signal end, but current logic always returns 1 or loops infinitely.]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    if(fp == NULL) return 1; // @@ [Missing check for file open failure, though not directly causing compilation error, but robustness issue. However, primary issue is logic below.]
    while(getword(fp,wc,num)==1)
    {
        num++;
        int flag=0;
        for(int i=0;i<num;i++) // @@ [Loop includes the just-read word at index 'num' which hasn't been initialized properly yet; also double increments num incorrectly.]
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
            num++; // @@ [num is incremented twice per word: once before the loop and once here, leading to skipping indices and accessing uninitialized memory.]
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