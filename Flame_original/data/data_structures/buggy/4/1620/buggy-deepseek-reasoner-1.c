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
            wc[num].word[len]='\0'; // @@ The function should break or return after terminating the word; otherwise it continues reading and concatenates the entire file into one word.
        }
    }
    return 1; // @@ Always returns 1 even when no word is read (EOF reached); should return 0 to signal end of file.
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
        num++; // @@ Incrementing num here shifts the index of the newly read word; the new word is at index num-1, but subsequent code uses wc[num] incorrectly.
        int flag=0;
        for(int i=0;i<num;i++) // @@ Loop goes up to num which now includes uninitialized wc[num]? Actually after increment, num is the count, so i<num includes the uninitialized slot at index num? The new word is at index num-1, but the loop compares with wc[num] (line 48), which is out of bounds or uninitialized.
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ wc[num] is not the new word; should be wc[num-1] after proper indexing.
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ Should set ci for the new word at index num-1, not wc[num].
            num++; // @@ Second increment makes num increase by 2 per word, corrupting count.
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