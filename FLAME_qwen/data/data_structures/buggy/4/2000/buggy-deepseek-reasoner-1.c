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
    file=fopen("file.txt","r"); // @@ [Wrong filename; should be "article.txt"]
    ch=fgetc(file);
    while(ch!=EOF)
    {
        if(ch<'a') // @@ [Incorrect condition; should be if(ch>='A' && ch<='Z') to only convert uppercase letters]
            s[i++]=ch+32;
        else
            s[i++]=ch;
        ch=fgetc(file);
    } // @@ [Missing null terminator: s[i] = '\0' should be added after loop]
}
void wordCount()
{
    int i=0,len=strlen(s); // @@ [s is not null-terminated, strlen leads to undefined behavior]
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
            i=0;
            strcpy(w[cnt].word,tmp); // @@ [tmp is not null-terminated; strcpy expects a null-terminated string]
            memset(tmp,0,sizeof(tmp));
            w[cnt].count=1;
            cnt++;
            }
            else continue;
        }
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
    for (int k=0;k<cnt;k++) // @@ [Loop bound causes out-of-bounds access to w[k+1] when k=cnt-1; should be k<cnt-1]
    {
        if (strcmp(w[k].word,w[k+1].word)==0)
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