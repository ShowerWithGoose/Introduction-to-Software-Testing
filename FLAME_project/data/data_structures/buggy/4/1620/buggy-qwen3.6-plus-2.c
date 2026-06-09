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
int getword(FILE *fp, struct wordci wc[],int num) // @@ [The function logic is flawed: it reads the entire file in one call without properly terminating strings or handling multiple words, and it doesn't increment num or handle word boundaries correctly for the caller's logic. It also fails to null-terminate the last word if the file doesn't end with a non-alpha character.]
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
            return 1; // @@ [This return causes the function to exit after finding only ONE word. The main loop expects this function to process one word at a time, but the internal while loop consumes characters until EOF or a word break. However, because it returns 1 immediately after finding one word, the state of `fp` is correct for the next call, BUT the logic inside `main` regarding `num` is inconsistent with how `getword` uses `num`. In `main`, `num` is the count of existing words. `getword` writes to `wc[num]`. This part is okay logically IF `getword` only extracts one word. However, there is a critical bug: if the file ends with a letter, the last word is never null-terminated and returned because the `else if` block is skipped when EOF is reached directly after a letter.]
        }
    }
    return 0; // @@ [If the loop finishes (EOF), it returns 0. But if the last word was being read (len > 0) and EOF hit, that word is lost because it wasn't null-terminated and returned in the else-if block.]
}
int main()
{
    FILE *fp;
    char ch;
    struct wordci wc[1000];
    int num=0;
    int len=0;
    fp=fopen("article.txt","r");
    while(getword(fp,wc,num)==1) // @@ [The logic here assumes getword fills wc[num]. If getword returns 1, we have a new word at wc[num].]
    {
        num++; // @@ [Now num points to the index AFTER the newly read word. The new word is at wc[num-1].]
        int flag=0;
        for(int i=0;i<num;i++) // @@ [This loop goes up to i < num. Since we just incremented num, it includes the newly added word at wc[num-1].]
        {
            if(strcmp(wc[i].word,wc[num].word)==0) // @@ [ERROR: wc[num] is uninitialized/garbage because the new word is at wc[num-1]. Accessing wc[num] is out of bounds relative to the valid data filled by getword, or simply accessing empty memory if num was the size. getword wrote to wc[old_num], which is now wc[num-1]. wc[num] has not been written to yet. This causes undefined behavior/crash.]
            {
                wc[i].ci++;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            wc[num].ci=1; // @@ [Again, accessing wc[num] which is invalid. Should be wc[num-1].]
            num++; // @@ [Incrementing num again? If the word was new, we increment num again. So for a new word, num increases by 2 total in this iteration (once before loop, once here). For duplicate, num increases by 1. This logic is completely broken.]
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