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
    words[num].time++; // @@ [words[num].time is uninitialized; it should be set to 1, not incremented]
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
        printf("%c",ch); // @@ [This debug print outputs every character read, which violates the output format requirement of only printing word counts]
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