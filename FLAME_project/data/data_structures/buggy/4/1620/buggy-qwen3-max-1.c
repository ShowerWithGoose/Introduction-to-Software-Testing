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
            return 1; // @@ [Missing return statement causes infinite loop in main; function should return after reading one word]
        }
    }
    if(len>0) // @@ [Handle last word in file if file doesn't end with non-alpha character]
    {
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Should return 0 at EOF to break main loop]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    if (fp == NULL) return 1; // @@ [Missing file open check may cause runtime error]
    while(getword(fp,wc,num)==1)
    {
        num++; // @@ [Incrementing num before checking duplicates leads to accessing uninitialized wc[num]]
        int flag=0;
        for(int i=0;i<num;i++)
        {
            if(strcmp(wc[i].word,wc[num-1].word)==0) // @@ [Should compare with wc[num-1] since num was already incremented]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num-1].ci=1; // @@ [Should initialize wc[num-1].ci instead of wc[num].ci]
        }
        else
        {
            num--; // @@ [Need to decrement num if word is duplicate to avoid counting twice]
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