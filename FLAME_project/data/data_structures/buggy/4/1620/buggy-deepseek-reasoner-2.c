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
            wc[num].word[len]='\0'; // @@ After setting the null terminator, the function should return the word and break out of the loop, but it continues reading characters, causing the buffer to be overwritten.
        }
    }
    return 1; // @@ The function always returns 1, even after EOF, leading to an infinite loop in the caller because it never returns 0 to indicate end of file.
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
        num++; // @@ After getword stores the word at index num (before increment), num is incremented, so subsequent access to wc[num] refers to an uninitialized element.
        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ wc[num] is the next empty slot (after increment), not the word just read. Should compare with wc[num-1].
            {
                wc[i].ci++; // @@ wc[i].ci may be uninitialized if this is the first occurrence; also wc[num-1].ci was never set to 1.
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ Again, wc[num] is the wrong index; should set wc[num-1].ci=1.
            num++; // @@ This extra increment skips an array slot, causing gaps and incorrect word counts.
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