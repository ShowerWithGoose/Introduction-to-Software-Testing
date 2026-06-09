#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

#define length 1024
char ch,temp[length];

typedef struct key
{
    char word[length];
    int count;
}key;
key keytab[length],wordprint[length];

int cmp(const void*_p,const void*_q)
{
    key *p=(key*)_p;
    key *q=(key*)_q;
    if(strcmp(p->word,q->word)!=0)
        return strcmp(p->word,q->word)<0 ? -1:1;
    return 0;
}

int main()
{

    FILE *fp;
    int i=0,k=0,j=0;
    fp=fopen("article.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            temp[i]=tolower(ch);
            i++;
        }
        else
        {
           if(i>0)
           {
               temp[i]='\0';
               strcpy(keytab[k].word,temp);
               keytab[k].count=1;
               k++;
               i=0;
           }
        }
    }

    qsort(keytab,k,sizeof(key),cmp);
    strcpy(wordprint[j].word,keytab[0].word);
    wordprint[j].count=keytab[0].count;
    for(i=1;i<k;i++)
    {
        if(strcmp(keytab[i].word,keytab[i-1].word)==0)
        {
            wordprint[j].count++;
        }
        else
        {
            j=j+1;
            strcpy(wordprint[j].word,keytab[i].word);
            wordprint[j].count=keytab[i].count;
        }
    }
    for(i=0;i<=j;i++)
    {
        printf("%s %d\n",wordprint[i].word,wordprint[i].count);
    }

    return 0;
}



