#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000],tmp[100],ch;
int cnt=0;    
FILE *file;
struct word
{
    char word[100];
    int count;
};
typedef struct word word;
word w[100];

int cmp(const void *a,const void *b);
void readArticle();
void wordCount();
void printFrenquency();


int main()
{
    readArticle();
    wordCount();
    printFrenquency();
    return 0;
}

void readArticle()
{
    int i=0;
    file=fopen("article.txt","r"); // @@ The problem states the file is named "article.txt", but the code opens "file.txt". This will cause a NULL pointer dereference or failure to read, leading to Runtime Error or incorrect output.
    ch=fgetc(file);
    while(ch!=EOF)
    {
        if(ch<'a')
            s[i++]=ch+32;
        else
            s[i++]=ch;
        ch=fgetc(file);
    }
}
void wordCount()
{
    int i=0,len=strlen(s);
    for (int j=0;j<len;j++)
    {
        if (s[j]>='a' && s[j]<='z')
        {
            tmp[i++]=s[j];
        }
        else
        {
            if (i)
            {
            tmp[i]='\0'; // @@ The string tmp is not null-terminated before being copied. strcpy requires a null-terminated source string. Without this, it may copy garbage data or cause a crash.
            i=0;
            strcpy(w[cnt].word,tmp);
            memset(tmp,0,sizeof(tmp));
            w[cnt].count=1;
            cnt++;
            }
            else continue;
        }
    }
    if (i > 0) { // @@ If the file ends with a letter, the last word is stored in tmp but never processed because the loop exits without hitting a non-alpha character to trigger the else block.
        tmp[i]='\0';
        strcpy(w[cnt].word,tmp);
        w[cnt].count=1;
        cnt++;
    }
}
int cmp(const void *a,const void *b)
{
    word *x=(word *)a;
    word *y=(word *)b;
    return strcmp(x->word,y->word);
}
void printFrenquency()
{
    qsort(w,cnt,sizeof(word),cmp);
    for (int k=0;k<cnt;k++)
    {
        if (k + 1 < cnt && strcmp(w[k].word,w[k+1].word)==0) // @@ Accessing w[k+1] when k is cnt-1 causes an out-of-bounds access (Runtime Error). Also, need to check if k+1 is within bounds.
        {
            w[k+1].count+=w[k].count;
            w[k].count=0;
        }
    }
    for (int k=0;k<cnt;k++)
    {
        if (w[k].count)
        {
            printf("%s %d\n",w[k].word,w[k].count);
        }
    }
}