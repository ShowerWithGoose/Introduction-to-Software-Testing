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
    char ch; // @@ Should be int ch; because fgetc returns int and EOF may be truncated if char is unsigned, causing incorrect loop termination.
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
            wc[num].word[len]='\0'; // @@ Missing return statement here; function continues reading until EOF instead of returning after extracting one word, causing an infinite loop in main.
        }
    }
    return 1; // @@ Should return 0 when EOF is reached without reading a new word to properly terminate the while loop in main; currently always returns 1.
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
        num++; // @@ Incrementing num here shifts the index; the newly read word is stored at wc[num-1], so subsequent comparisons should use wc[num-1].
        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ Compares with uninitialized wc[num]; should compare with wc[num-1] which holds the current word.
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ Initializes count for uninitialized wc[num] instead of wc[num-1].
            num++; // @@ Double increments num, causing index misalignment, skipping array positions, and potential out-of-bounds access.
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