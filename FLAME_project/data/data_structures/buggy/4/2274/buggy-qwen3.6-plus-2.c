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
    words[num].time++; // @@ The initial count for a new word should be 1, not incremented from 0 (which results in 1, but logically it's setting the first occurrence). However, since time is initialized to 0, ++ makes it 1. This is technically correct for the first insertion. But wait, if the word already exists, it returns. If it doesn't, we add it. The logic here is actually okay for counting IF the array was zeroed. 
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
        printf("%c",ch); // @@ This line prints the raw content of the file to stdout, which causes the "Wrong Answer" because the output contains the original text before the word frequency list.
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
    // @@ Missing handling for the last word if the file does not end with a non-alpha character. If the last character is a letter, the word buffer 'w' is not processed.
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