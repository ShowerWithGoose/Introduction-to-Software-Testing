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
int getword(FILE *fp, struct wordci wc[],int num) // @@ [The function logic is flawed: it reads the entire file in one call without properly terminating strings or handling multiple words, and it doesn't increment num or handle word boundaries correctly for the caller's expectation. It returns 1 always until EOF, causing an infinite loop or incorrect processing in main.]
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
            return 1; // @@ [Should return here after finding one word to allow main to process it. Currently, it continues reading and overwrites the buffer or fails to null-terminate if the file ends with a letter.]
        }
    }
    if (len > 0) { // @@ [Handle the case where the file ends with a word character]
        wc[num].word[len]='\0';
        return 1;
    }
    return 0; // @@ [Return 0 when no more words are found (EOF reached)]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    while(getword(fp,wc,num)==1) // @@ [The loop condition relies on getword returning 1 for success. The original getword implementation was broken. With the fixed getword, this works, but the logic inside the loop below is also problematic because it compares wc[num] which might not be initialized if getword didn't write to it properly, or it double increments num.]
    {
        num++; // @@ [num is incremented here, so wc[num] in the following loop refers to the NEXT empty slot, but the word was read into wc[num-1] (the value of num passed to getword). This causes out-of-bounds access or comparison with uninitialized data.]
        int flag=0;
        for(int i=0;i<num;i++) // @@ [This loop goes up to num (which includes the current new word index if we adjusted correctly, but here num is already incremented). It should check against existing words 0 to num-1 (where num-1 is the current word). But since num was incremented, wc[num] is invalid. The logic should be: read into wc[num], then check duplicates among 0..num-1. If duplicate, merge. If not, increment num.]
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ [Accessing wc[num] is out of bounds because num was just incremented. The word was stored at wc[num-1].]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ [Again, accessing wc[num] which is out of bounds. Should be wc[num-1].]
            num++; // @@ [Incrementing num again leads to skipping indices or double counting logic errors.]
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