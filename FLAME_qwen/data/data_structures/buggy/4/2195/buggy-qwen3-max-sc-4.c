#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef struct _Word{
    char word[50];
    int count;
}Word, *PWord;

int cmp(const void *p,const void *q)
{
    PWord x=(PWord)p;
    PWord y=(PWord)q;
    return strcmp(x->word,y->word);
}

int main()
{
    Word words[200];
    char buf[200];  //暂存 
    int num=0;  //单词个数 
    FILE *fp;
    fp=fopen("article.txt","r");
    if (fp == NULL)
    {
        printf("Cannot open infile.\n");
        return 0;
    }
    while(fgets(buf,199,fp)!=NULL)
    {
        int len=strlen(buf);
        char word[50];
        for(int i=0;i<len;i++)
        {
            if(!isalpha(buf[i]))
                continue;
            int j,k;
            for(j=0;isalpha(buf[i]);j++) 
            {
                word[j]=tolower(buf[i]);
                i++;
            }
            word[j]='\0';
            
            for(k=0;k<num;k++)  //是否出现过 
                if(strcmp(word,words[k].word)==0)
                    break;
                    
            if(k==num)  //没出现过 
            {
                strcmp(words[num].word,word); // @@ [This line incorrectly uses strcmp instead of strcpy to store the new word. It should copy 'word' into 'words[num].word', but strcmp only compares and returns an integer, leaving words[num].word uninitialized or containing garbage.]
                words[num].count=1;
                num++;
            }
            else  //出现过
                words[k].count++;
        }
    }
    qsort(words,num,sizeof(words[0]),cmp);
    for(int i=0;i<num;i++)
        printf("%s %d\n",words[i].word,words[i].count);
    fclose(fp);
    return 0;
}