#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

#define length 1024
char ch,key[length];

typedef struct wordlist
{
    char word[length];
    int count;
}wordlist;
wordlist line[length],wordprint[length];

int cmp(const void*_p,const void*_q)
{
    wordlist *p=(wordlist*)_p;
    wordlist *q=(wordlist*)_q;
    if(strcmp(p->word,q->word)!=0)
        return strcmp(p->word,q->word)<0 ? -1:1;
    return 0;
}

int main()
{

    FILE *fp;
    int i=0,j=0,k=0;
    fp=fopen("article.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            key[i]=tolower(ch);
            i++;
        }
        else
        {
           if(i>0)
           {
               key[i]='\0';
               strcpy(line[j].word,key);
               line[j].count=1;
               j++;
               i=0;
           }
        }
    }

    qsort(line,j,sizeof(wordlist),cmp);
    strcpy(wordprint[k].word,line[0].word);
    wordprint[k].count=line[0].count;
    for(i=1;i<j;i++)
    {
        if(strcmp(line[i].word,line[i-1].word)==0)
        {
            wordprint[k].count++;
        }
        else
        {
            k=k+1;
            strcpy(wordprint[k].word,line[i].word);
            wordprint[k].count=line[i].count;
        }
    }
    for(i=0;i<=k;i++)
    {
        printf("%s %d\n",wordprint[i].word,wordprint[i].count);
    }

    return 0;
}



