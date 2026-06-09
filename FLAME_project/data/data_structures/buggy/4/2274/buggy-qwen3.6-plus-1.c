#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct WORD   
{
    int time;
    char word[30];
}words[10000];
int num=0;
void insert(char *str)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(strcmp(words[i].word,str)==0)
        {
            words[i].time++;
            return;
        }
    }
    words[num].time++; // @@ The initial count for a new word should be 1, not incrementing from uninitialized/zero memory which might be 0, but logically it's the first occurrence. More importantly, if time was 0, it becomes 1. However, the standard pattern is to set it to 1. Let's look closer. If words[num].time is 0 (initialized in main), then words[num].time++ makes it 1. This part is technically okay IF memory is zeroed. But wait, if the word already existed, we returned. If it's new, we add it. The logic `words[num].time++` assumes it starts at 0. In main, we initialize all to 0. So this sets it to 1. This is correct.
    strcpy(words[num].word,str);
    num++;
}
char w[30];
void scan(FILE *fp)
{
    char ch;
    int i=0;
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
        printf("%c",ch); // @@ This line prints the raw content of the file to stdout, which violates the output format requirement (only word frequencies should be printed).
        if(ch>='A' && ch<='Z')
        {
            ch = ch-'A'+'a';
        }
        if(!isalpha(ch) && w[0]!='\0')
        {
            int j = i;
            w[i] = '\0';
            insert(w);
            for(i=0;i<j;i++)
            {
                w[i]='\0';
            }
            i=0;
        }
        else if(isalpha(ch))
        {
            w[i++] = ch;
        }

    }  
    // @@ After the loop ends, if the file ends with a letter (i.e., the last token is a word not followed by a non-alpha character), the last word stored in 'w' is never processed/inserted because the insertion logic is triggered only by a non-alpha character.
}
int cmp(void const*a,void const *b)
{
    return strcmp((*(struct WORD*)a).word,(*(struct WORD*)b).word);
}
int main()
{
    for(int i=0;i<10000;i++)
    {
        words[i].time=0; 
    }
    FILE *p;
    p = fopen("article.txt","r");
    scan(p);
    qsort(words,num,sizeof(struct WORD),cmp);
    for(int i=0;i<num;i++) printf("%s %d\n",words[i].word,words[i].time);
    fclose(p);
    return 0;
}